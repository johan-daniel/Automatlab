#include "../include/GraphicView.hpp"
#include <iostream>
#include <QPoint>
#include <qgraphicsview.h>
#include "../include/StateWidget.hpp"
#include "../include/AutomatLab.hpp"


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

void GraphicView::mousePressEvent(QMouseEvent* event) {
    if(itemAt(event->pos()) != nullptr) {
        QGraphicsView::mousePressEvent(event);
        return;
    }

    std::cout << "APP MODE : " << AutomatLab::s_State << std::endl;

    emit clicked();
    // // TODO : STATE HANDLING FOR TOOL BUTTONS
    // a->AddState(EStateKind::None, pos.x(), pos.y());

    // // TODO : NOT RE-RENDER EVERYTHING EVERY TIME :xdd:
    // Render();
}