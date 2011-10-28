#include "viewer/widgets/MapView.h"

//TODO Debug. To delete
#include <iostream>
#include <QVector3D>

namespace simulationviewer
{
namespace widgets
{




    // ----------------------------------------------------------
    // Constructor/Destructor

    MapView::MapView(QWidget * ioParent) : QGraphicsView(ioParent)
    {
        initialize();
    }

    MapView::~MapView()
    {
    }


    // ----------------------------------------------------------
    // Public methods
    void MapView::drawFishes(const std::vector<QPoint>& iPointsList)
    {
        QPen p;
        p.setColor(Qt::red);


        std::cout << "width : " << this->width() << std::endl;
        std::cout << "height : " << this->height() << std::endl;

        std::cout << "si : " << (int)iPointsList.size() << std::endl;


        scene()->clear();

        for( int i = 0 ; i < (int)iPointsList.size(); ++i )
        {
            QPoint fish = iPointsList[i];

            scene()->addRect(fish.x(),fish.y(),1,1,p);
        }
    }


    // ----------------------------------------------------------
    // Private methods


    void MapView::initialize()
    {
        _mainGraphicScene = QSharedPointer<QGraphicsScene>(new QGraphicsScene(this));

        this->setScene(_mainGraphicScene.data());

        QPen p;
        p.setColor(Qt::red);
        scene()->addRect(0,0,1,1,p);

        scene()->addRect(10,10,1,1,p);
        scene()->addRect(-10,-10,1,1,p);



        scene()->addRect(this->width(),this->height(),1,1,p);
        scene()->addRect(-this->width(),-this->height(),1,1,p);


    }



}
}
