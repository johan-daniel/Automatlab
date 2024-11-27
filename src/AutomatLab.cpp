#include "../include/AutomatLab.hpp"
#include <iostream>
#include <qabstractbutton.h>

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
    if(toggled) s_State = EClickState::State;
    else if(!m_UI.tb_TransitionBtn->isChecked()) s_State = EClickState::None;
}

void AutomatLab::InsertTransitionMode(bool toggled) { 
    if(toggled) s_State = EClickState::Transition;
    else if(!m_UI.tb_StateBtn->isChecked()) s_State = EClickState::None;
}

void AutomatLab::ButtonUsed() {
    switch(s_State) {
        case State: {
            m_UI.tb_StateBtn->toggle();
            m_UI.tb_StateBtn->setChecked(false);
            break;
        }
        case Transition:{
            m_UI.tb_TransitionBtn->toggle();
            m_UI.tb_TransitionBtn->setChecked(false);
            break;
        }
        case None: break;
    }
}