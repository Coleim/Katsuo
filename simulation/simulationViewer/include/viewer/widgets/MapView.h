/**
 * MapView.h
 * Created on Aug 27 - 2011
 * Author: Coleim
 */


#ifndef _ORI_SIMULATIONVIEWER_WIDGETS_MAPVIEW_H
#define _ORI_SIMULATIONVIEWER_WIDGETS_MAPVIEW_H

#include <QGraphicsView>
#include <QWidget>

namespace simulationviewer
{
namespace widgets
{

    class MapView : public QGraphicsView
    {
    public:
        MapView(QWidget * ioParent = 0);
        virtual ~MapView();

        void drawFishes(const std::vector<QPoint>& iPointsList);

    private:
        void initialize();
        void placeLayout();

        QSharedPointer<QGraphicsScene> _mainGraphicScene;
    };


}
}



#endif // _ORI_SIMULATIONVIEWER_WIDGETS_MAPVIEW_H
