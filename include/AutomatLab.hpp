#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <qtmetamacros.h>
#include "GraphicView.hpp"
#include "ui/ui_AutomatLab.h"
#include "Automata.hpp"

namespace Automatlab {

enum EClickState {
    None = 0,
    State,
    Transition
};

class AutomatLab : public QMainWindow {
    Q_OBJECT

private:
    Ui::AutomatLab m_UI;
    GraphicView m_GV;
    Automata m_Automata;

public:
    static EClickState s_State;

    AutomatLab();
    ~AutomatLab();

protected slots:
    void InsertStateMode(bool toggled);
    void InsertTransitionMode(bool toggled);
    void ButtonUsed();
};

}

#endif