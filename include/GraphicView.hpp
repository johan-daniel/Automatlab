#ifndef GRAPHIC_VIEW_HPP__
#define GRAPHIC_VIEW_HPP__

#include <QGraphicsView>
#include <qgraphicsscene.h>
#include <qtmetamacros.h>
#include <QMouseEvent>
#include "Automata.hpp"
#include "StateWidget.hpp"

namespace Automatlab {

class GraphicView : public QGraphicsView {
    Q_OBJECT

private:
    Automata* a;
    QGraphicsScene scene;
    std::vector<StateWidget*> node_widgets;

public:
    GraphicView(Automata* a, QWidget* parent = nullptr);
    ~GraphicView();
    inline void SetAutomata(Automata* a) { this->a = a; };
    void Render();

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked(QPoint pos);
    void connectStateWidget(const StateWidget& sw);

};

}


#endif