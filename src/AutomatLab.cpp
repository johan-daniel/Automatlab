#include "../include/AutomatLab.hpp"
#include <qlabel.h>
#include <qnamespace.h>
#include <qpushbutton.h>

using namespace Automatlab;

AutomatLab::AutomatLab() { 
    ui.setupUi(this);
    ui.GraphView->layout()->addWidget(&gv);
    this->show();
}

AutomatLab::~AutomatLab() {}

