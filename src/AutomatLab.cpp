#include "../include/AutomatLab.hpp"
#include <qlabel.h>
#include <qnamespace.h>
#include <qpushbutton.h>

using namespace Automatlab;

AutomatLab::AutomatLab(): gv(), a() { 
    ui.setupUi(this);
    gv.SetAutomata(&a);
    ui.GraphView->layout()->addWidget(&gv);
    this->show();
}

AutomatLab::~AutomatLab() {}

