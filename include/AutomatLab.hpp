#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <qpushbutton.h>
#include <qtmetamacros.h>
#include "GraphicView.hpp"
#include "ui/ui_AutomatLab.h"
#include "Automata.hpp"
#include "../include/State.hpp"

namespace Automatlab {

enum EClickState {
    None = 0,
    Node,
    Transition
};

class AutomatLab : public QMainWindow {
    Q_OBJECT

private:
    Ui::AutomatLab m_UI;
    GraphicView m_GV;
    Automata m_Automata;

    void ToggleBtn(QPushButton* btn, bool toggled);

public:
    static EClickState s_State;

    AutomatLab();
    ~AutomatLab();

public slots:
    void StateParams(State* s);
    void InsertStateMode(bool toggled);
    void InsertTransitionMode(bool toggled);
    void ButtonUsed();
};

}

#endif