#include "../include/GraphicView.hpp"
#include <iostream>
#include <QPoint>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include "../include/StateWidget.hpp"
#include "../include/AutomatLab.hpp"
#include "../include/State.hpp"


using namespace Automatlab;

GraphicView::GraphicView(Automata* a, QWidget* parent): QGraphicsView(parent), a(a), scene() {
    setRenderHint(QPainter::Antialiasing);
    setSceneRect(0, 0, 1, 1);   // For some reason without this line the scene doesn't properly fill the View even though coloring it would suggest otherwise
    setScene(&scene);
}

GraphicView::~GraphicView() {
    for(auto& i : node_widgets) i->deleteLater();
    scene.deleteLater();
}

void GraphicView::mousePressEvent(QMouseEvent* event) {
    if(itemAt(event->pos()) != nullptr) {
        QGraphicsView::mousePressEvent(event);
        return;
    }

    std::cout << "APP MODE : " << AutomatLab::s_State << std::endl;
    
    switch(AutomatLab::s_State) {
        case None: break;
        case Node: {
            a->AddState(EStateKind::None, event->pos().x(), event->pos().y()); 
            Render();   // This rerenders the entire canva on every new State :xdd:
        }
        case Transition: break;
    }

    emit clicked(event->pos());
}


void GraphicView::Render() {
    for(auto& s : a->m_States) {
        StateWidget* sw =  new StateWidget(mapToScene(s.x, s.y));
        node_widgets.push_back(sw);
        sw->m_State = &s;
        emit connectStateWidget(*sw);
        scene.addItem(sw);
    }
}