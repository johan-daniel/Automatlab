#include "../include/Automata.hpp"
#include <iostream>
#include <ranges>

using namespace Automatlab;

Automata::Automata(): m_Alphabet(), m_States() {}

void Automata::AddState(EStateKind state) {
    State s(m_States.size(), state);
    m_States.push_back(s);
}

void Automata::AddTransition(State& from, State& to, std::string chars, bool accepts_empty_word) {
    if(accepts_empty_word) chars.push_back(NULL_CHAR);

    from.AddTransition(to, chars);
    UpdateAlphabet(chars);
}


void Automata::UpdateAlphabet(const std::string& chars) {
    for(std::string::const_iterator it = chars.begin(); it != chars.end(); it++) {
        m_Alphabet[*it]++;
    }
}

void Automata::RemoveState(State& s) {
    auto x = std::find(m_States.begin(), m_States.end(), s);
    if(x != m_States.end()) m_States.erase(x);
}


std::set<char> Automata::GetAlphabet() {
    return m_Alphabet | std::ranges::views::keys | std::ranges::to<std::set>();
}


void Automata::ToString() {
    for(State s : m_States) {
        s.ToString();
        std::cout << std::endl;
    }
}