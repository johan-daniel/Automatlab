#include "../include/AutomatLab.hpp"
#include <cstdint>
#include <iostream>
#include <qabstractbutton.h>
#include <qboxlayout.h>
#include <qcheckbox.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QCheckBox>

using namespace Automatlab;

EClickState AutomatLab::s_State = EClickState::None;


AutomatLab::AutomatLab(): m_GV(&m_Automata, this), m_Automata() { 
    m_UI.setupUi(this);
    m_UI.GraphView->layout()->addWidget(&m_GV);
    this->show();

    connect(m_UI.tb_StateBtn, &QAbstractButton::toggled, this, &AutomatLab::InsertStateMode);
    connect(m_UI.tb_TransitionBtn, &QAbstractButton::toggled, this, &AutomatLab::InsertTransitionMode);
    connect(&m_GV, &GraphicView::clicked, this, &AutomatLab::ButtonUsed);

    // Forwarded signal from the StateWidgets to display their parameters on the UI
    connect(&m_GV, &GraphicView::connectStateWidget, this, [&] (const StateWidget& sw) {
        connect(&sw, &StateWidget::clicked, this, &AutomatLab::StateParams);
    });
}

AutomatLab::~AutomatLab() {}



void AutomatLab::InsertStateMode(bool toggled) {
    if(toggled) {
        if(m_UI.tb_TransitionBtn->isChecked()) ToggleBtn(m_UI.tb_TransitionBtn, false);
        s_State = EClickState::Node;
    }
    else {
        s_State = EClickState::None;
    }
}

void AutomatLab::InsertTransitionMode(bool toggled) { 
    if(toggled) {
        if(m_UI.tb_StateBtn->isChecked()) ToggleBtn(m_UI.tb_StateBtn, false);
        s_State = EClickState::Transition;
    }
    else s_State = EClickState::None;
}

void AutomatLab::ButtonUsed() {
    switch(s_State) {
        case Node: {
            ToggleBtn(m_UI.tb_StateBtn, false);
            break;
        }
        case Transition:{
            ToggleBtn(m_UI.tb_TransitionBtn, false);
            break;
        }
        case None: break;
    }
}

void AutomatLab::ToggleBtn(QPushButton* btn, bool toggled) {
    btn->toggled(toggled);
    btn->setChecked(toggled);
}

void AutomatLab::StateParams(State* s) {
    std::cout << "Test " << s->m_ID << "\n";
    
    QGridLayout* grid_layout = static_cast<QGridLayout*>(m_UI.params->layout());

    grid_layout->addWidget(new QLabel("State type", m_UI.params), 0, 0);
    QFrame* type_frame = new QFrame(m_UI.params);
    QVBoxLayout* vlayout = new QVBoxLayout();
    type_frame->setLayout(vlayout);
    QCheckBox* b1 = new QCheckBox("First", type_frame);
    QCheckBox* b2 = new QCheckBox("Final", type_frame);

    for(uint8_t i = 1; i <= 2; i++) {
        auto test = static_cast<uint32_t>(s->GetStateKind()) >> i;
        continue;
    }

    vlayout->addWidget(b1);
    vlayout->addWidget(b2);
    grid_layout->addWidget(type_frame, 0, 1);
}