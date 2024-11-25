#ifndef AUTOMATA_HPP__
#define AUTOMATA_HPP__

#include "State.hpp"
#include <map>
#include <set>
#include <vector>
#include "string"

namespace Automatlab {

#define NULL_CHAR '\r'

class Automata {

private:
    std::map<char, int> m_Alphabet;

public:
    std::vector<State> m_States;

    Automata();
    ~Automata() {};

    void AddState(EStateKind state);
    void AddTransition(State& from, State& to, std::string chars, bool accepts_empty_word = false);
    void UpdateTransition(State& from, State& to, const std::string& new_chars, bool accepts_empty_word = false);
    void RemoveTransition(State& from, State& to);
    void RemoveState(State& s);
    void UpdateAlphabet(const std::string& chars);
    std::set<char> GetAlphabet();
    void ToString();
};

}

#endif