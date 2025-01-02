#ifndef STATE_HPP__
#define STATE_HPP__

#include <cstdint>
#include <string>
#include <vector>

namespace Automatlab {

struct Transition;

enum class EStateKind : uint8_t {
    None  = 0x00,
    First = 0x01,
    Final = 0x02, 
};

inline EStateKind operator|(const EStateKind& a, const EStateKind& b) {
    return static_cast<EStateKind>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

class State {



private:
    EStateKind m_State;
    std::vector<Transition> m_Transitions;



public:
    uint16_t m_ID;
    float x, y;

    State(int id, EStateKind state, float x, float y);
    void AddTransition(State& to, const std::string& chars);
    void ToString(bool small = false);
    void UpdateState(EStateKind state);
    void RemoveTransition(const int state_ID);
    inline EStateKind GetStateKind() const { return m_State; }

    bool operator==(const int rhs) { return m_ID == rhs; }
    bool operator==(const State& rhs) { return m_ID == rhs.m_ID; }

};


struct Transition {
    std::string chars;
    State* to;
    bool operator==(const int s) { return (*to) == s; }
};

}

#endif