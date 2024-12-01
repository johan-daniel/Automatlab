#include "../include/AutomatLab.hpp"
#include <iostream>
#include <qabstractbutton.h>
#include <qpushbutton.h>

using namespace Automatlab;

EClickState AutomatLab::s_State = EClickState::None;


AutomatLab::AutomatLab(): m_GV(), m_Automata() { 
    m_UI.setupUi(this);
    m_GV.SetAutomata(&m_Automata);
    m_UI.GraphView->layout()->addWidget(&m_GV);
    this->show();

    connect(m_UI.tb_StateBtn, &QAbstractButton::toggled, this, &AutomatLab::InsertStateMode);
    connect(m_UI.tb_TransitionBtn, &QAbstractButton::toggled, this, &AutomatLab::InsertTransitionMode);

    connect(&m_GV, &GraphicView::clicked, this, &AutomatLab::ButtonUsed);
}

AutomatLab::~AutomatLab() {}



void AutomatLab::InsertStateMode(bool toggled) {
    if(toggled) {
        if(m_UI.tb_TransitionBtn->isChecked()) ToggleBtn(m_UI.tb_TransitionBtn, false);
        s_State = EClickState::State;
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
        case State: {
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