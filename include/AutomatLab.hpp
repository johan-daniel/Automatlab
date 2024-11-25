#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <qtmetamacros.h>
#include "GraphicView.hpp"
#include "ui/ui_AutomatLab.h"

namespace Automatlab {

class AutomatLab : public QMainWindow {
    Q_OBJECT

private:
    Ui::AutomatLab ui;
    GraphicView gv;

public:
    AutomatLab();
    ~AutomatLab();

};

}

#endif