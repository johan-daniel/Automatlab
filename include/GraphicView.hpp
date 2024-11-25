#ifndef GRAPHIC_VIEW_HPP__
#define GRAPHIC_VIEW_HPP__

#include <QGraphicsView>
#include <qgraphicsscene.h>
#include <qtmetamacros.h>
#include <QMouseEvent>

namespace Automatlab {

class GraphicView : public QGraphicsView {
    Q_OBJECT

private:
    QGraphicsScene* scene;
    std::vector<QGraphicsItem*> items;

public:
    GraphicView(QWidget* parent = nullptr);
    ~GraphicView();

protected:
    void mousePressEvent(QMouseEvent* event) override;

};

}


#endif