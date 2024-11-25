#include <cmath>
#include <qapplication.h>
#include "../include/Automata.hpp"
#include "../include/AutomatLab.hpp"

using namespace Automatlab;

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);
    AutomatLab w;

    w.show();

    return a.exec();

    // Automata a;
    // for(int i = 0; i < 10; i++) a.AddState(EStateKind::None);
    // a.m_States[0].UpdateState(EStateKind::First);
    // a.m_States[1].UpdateState(EStateKind::Final);
    // a.m_States[2].UpdateState(EStateKind::First | EStateKind::Final);
    
    // a.AddTransition(a.m_States[0], a.m_States[1], "abc");
    // a.AddTransition(a.m_States[1], a.m_States[1], "bcde");

    // a.m_States[1].RemoveTransition(1);

    // //a.RemoveState(4);

    // a.ToString();

    // return 0;
}