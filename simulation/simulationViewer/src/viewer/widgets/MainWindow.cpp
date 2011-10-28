#include <QMenuBar>
#include <QToolBar>
#include <QIcon>

#include <unistd.h>
#include <sys/mman.h>

#include <iostream>
#include <fstream>
#include <string>

#include "viewer/widgets/MapView.h"
#include "viewer/widgets/MainWindow.h"


namespace simulationviewer
{
namespace widgets
{

using namespace std;
inline float endian_swap(float x)
{
     float a;
   unsigned char *dst = (unsigned char *)&a;
   unsigned char *src = (unsigned char *)&x;

   dst[0] = src[3];
   dst[1] = src[2];
   dst[2] = src[1];
   dst[3] = src[0];

   return a;
}

    // ----------------------------------------------------------
    // Constructor/Destructor

    MainWindow::MainWindow() : QMainWindow()
    {
        initialize();
        createMenus();


    }

    MainWindow::~MainWindow()
    {
        _map.clear();
        _controlBar.clear();
    }


    // ----------------------------------------------------------
    // Private methods


    void MainWindow::initialize()
    {
        _map = QSharedPointer<MapView>(new MapView(this));
        _controlBar = QSharedPointer<QDockWidget>(new QDockWidget(QString("Test"), this));

        this->setCentralWidget(_map.data());
        this->addDockWidget(Qt::LeftDockWidgetArea, _controlBar.data());

        this->setStyleSheet("QMainWindow {"
                            "  background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(79, 77, 70, 255)); "
                            "}");
    }

    void MainWindow::createMenus()
    {
        QAction * quitAction = new QAction("Quit", this);
        QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

        QIcon quitIcon;
        quitIcon.addPixmap(QPixmap("data/images/QuitIcon.png"), QIcon::Normal);
        quitAction->setIcon(quitIcon);

        QToolBar * toolBar = addToolBar("oriToolBar");
        toolBar->setMovable(false);

        QWidget* spacer = new QWidget();
        spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        toolBar->addAction("Left-aligned button");


        QAction * startAction = new QAction("Start", this);
        QObject::connect(startAction, SIGNAL(triggered()), this, SLOT(start()));
        toolBar->addAction(startAction);


        toolBar->addWidget(spacer);
        toolBar->addAction(quitAction);

    }

    void MainWindow::start()
    {
        FILE * pFile;
        pFile = fopen ("eta_410101.dta" , "r");
        if (pFile == NULL) perror ("Error opening file");

        int fd =  fileno(pFile);


        int imt = 3600, jmt = 1500;

        size_t sizet=sizeof(float)*imt*jmt;


        float *raw = (float*)mmap(0, sizet, PROT_WRITE | PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);

        if(raw == MAP_FAILED)
        {
          cout << " error mmap" << endl;
          return;
        }

        float va = 0, vl = 0;
        int x = 0, y = 0;

        std::vector<QPoint> fishList;

        /*for (int i =  starti-imt; i >=0; i+= dec)
        {
            vl = raw[i];
            va = endian_swap(vl);
            if(va>-1000)
            {

            }
            else
            {
                QPoint p;
                p.setX(x);
                p.setY(y);
                //fishList.push_back(p);

            }

            x++;
            if(i%imt == 0){
               cout << endl;
               i-= dec*imt - imt;
                y++;
               x=0;
            }
        }*/

        float q = 100000.000000;

        /*

        for (int i = imt*jmt - imt; i >= 0; ++i)
        {
            cout << "=====================" <<endl;
            cout << "i:" << i <<endl;
            cout << "x:" << x <<endl;
            cout << "y:" << y <<endl;

            vl = raw[i];
            va = endian_swap(vl);
            if(va>-1000)
            {
                cout << va ;
            }
            else
            {
                QPoint p;
                p.setX(x);
                p.setY(y);
                fishList.push_back(p);

            }

            x++;

            if( (i+1)%imt == 0 )
            {
                cout << endl;
                i -= 2*imt;
                y++;
                cout << i <<endl;
                if( i+1 >= 0)
                    x=0;
            }
        }

        cout << imt*jmt <<endl;
        cout << x << "," << y <<endl;*/

        //_map->drawFishes(fishList);
    }


}
}
