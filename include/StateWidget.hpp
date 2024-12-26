#ifndef STATE_WIDGET_HPP__
#define STATE_WIDGET_HPP__

#include <iostream>
#include <qbrush.h>
#include <qtmetamacros.h>
#include <qgraphicsitem.h>
#include <QGraphicsSceneMouseEvent>
#include "../include/State.hpp"

using namespace Automatlab;

constexpr float const R = 50;

class StateWidget : public QGraphicsEllipseItem {

    public:
        float x, y;
        State* m_State;

        inline StateWidget(QPointF p, QGraphicsItem* parent = nullptr): QGraphicsEllipseItem(p.x()-R/2,p.y()-R/2,R,R)
        {
            setBrush(QBrush(Qt::white));
            setZValue(10);
        }

    protected:
        inline void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
            event->accept();
            std::cout << "State " << m_State->m_ID << " pressed\n";
        }
};


#endif