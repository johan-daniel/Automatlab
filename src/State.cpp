#include "../include/State.hpp"
#include <algorithm>
#include <bits/ranges_algo.h>
#include <iostream>

using namespace Automatlab;


State::State(int id, EStateKind state, float x, float y) : m_State(state),  m_Transitions(), m_ID(id), x(x),  y(y) {}

void State::AddTransition(State& to, const std::string& chars) { 
    m_Transitions.push_back({ chars, &to }); 
}

void State::UpdateState(EStateKind state) { m_State = state; }

void State::RemoveTransition(const int state_ID) { 
    std::vector<Transition>::iterator x = std::find(m_Transitions.begin(), m_Transitions.end(), state_ID);
    if(x != m_Transitions.end()) m_Transitions.erase(x);
}


void State::ToString(bool small) {
    std::cout << "(S" << m_ID;
    if(m_State == EStateKind::First) std::cout << "|FIRST";
    else if(m_State == EStateKind::Final) std::cout << "|FINAL";
    else if(m_State == (EStateKind::First | EStateKind::Final)) std::cout << "|FIRST|FINAL";
    std::cout << ")";

    if(small) return;

    if(m_Transitions.size() > 0) {
        std::cout << " -> ";
        for(Transition t : m_Transitions) {
            std::cout << "[" << t.chars;
            t.to->ToString(true);
            std::cout << "] ";
        }
    }
}
