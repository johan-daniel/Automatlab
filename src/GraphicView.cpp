#include "../include/GraphicView.hpp"
#include <iostream>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicssceneevent.h>
#include <qnamespace.h>
#include <QPoint>
#include <qpen.h>
#include <qtransform.h>
#include "../include/StateWidget.hpp"


using namespace Automatlab;

GraphicView::GraphicView(QWidget* parent): QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setRenderHint(QPainter::Antialiasing);
    setSceneRect(0, 0, 1, 1);   // For some reason without this line the scene doesn't properly fill the View even though coloring it would suggest otherwise
    setScene(scene);
    scene->addItem(new StateWidget(mapToScene(50,50)));
}

GraphicView::~GraphicView() {
    delete scene;
}

void GraphicView::Render() {
    constexpr int const r = 50;
    for(State s : a->m_States) {
        scene->addEllipse(s.x-r/2., s.y-r/2., r, r, QPen(Qt::black), QBrush(Qt::white));
    }
}

void GraphicView::mousePressEvent(QMouseEvent* event) {
    if(itemAt(event->pos()) != nullptr) return;
    std::cout << "GV clicked\n";

    // // TODO : STATE HANDLING FOR TOOL BUTTONS
    // a->AddState(EStateKind::None, pos.x(), pos.y());

    // // TODO : NOT RE-RENDER EVERYTHING EVERY TIME :xdd:
    // Render();
}