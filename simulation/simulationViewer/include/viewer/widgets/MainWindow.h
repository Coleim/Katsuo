/**
 * MainWindow.h
 * Created on Aug 21 - 2011
 * Author: Coleim
 */


#ifndef _ORI_SIMULATIONVIEWER_WIDGETS_MAINWINDOW_H
#define _ORI_SIMULATIONVIEWER_WIDGETS_MAINWINDOW_H


#include <QMainWindow>
#include <QDockWidget>


namespace simulationviewer
{
namespace widgets
{

    class MapView;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow();
        virtual ~MainWindow();

    public slots:
        void start();

    private:
        QSharedPointer<MapView> _map;
        QSharedPointer<QDockWidget> _controlBar;

        void initialize();
        void createMenus();



    };


}
}


#endif // _ORI_SIMULATIONVIEWER_WIDGETS_MAINWINDOW_H
