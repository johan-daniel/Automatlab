#ifndef STATE_WIDGET_HPP__
#define STATE_WIDGET_HPP__

#include <iostream>
#include <qbrush.h>
#include <qtmetamacros.h>
#include <qgraphicsitem.h>
#include <QGraphicsSceneMouseEvent>

constexpr float const R = 50;

class StateWidget : public QGraphicsEllipseItem {

    public:
        float x, y;

        inline StateWidget(QPointF p) : StateWidget(p.x(), p.y()) {}

        inline StateWidget(float x, float y, QGraphicsItem* parent = nullptr): QGraphicsEllipseItem(x-R/2,y-R/2,R,R) {
            setBrush(QBrush(Qt::white));
            setZValue(10);
        }

    protected:
        inline void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
            event->accept();
            std::cout << "State pressed\n";
        }
};


#endif