#include "../include/GraphicView.hpp"
#include <iostream>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <QPoint>
#include <qpen.h>


using namespace Automatlab;

GraphicView::GraphicView(QWidget* parent): QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setSceneRect(0, 0, 1, 1);   // For some reason without this line the scene doesn't properly fill the View even though coloring it would suggest otherwise
    setScene(scene);
}

GraphicView::~GraphicView() {
    delete scene;
}


void GraphicView::mousePressEvent(QMouseEvent* event) {
    std::string btn = (event->button() == Qt::LeftButton) ? "LMB" : "RMB";
    QPointF pos = mapToScene(event->pos());
    std::cout << btn << " (" << pos.x() << "," << pos.y() << ")\n";

    if(event->button() == Qt::RightButton) return;

    constexpr int const r = 50;
    scene->addEllipse(pos.x()-r/2., pos.y()-r/2., r, r, QPen(Qt::black), QBrush(Qt::white));

    
}