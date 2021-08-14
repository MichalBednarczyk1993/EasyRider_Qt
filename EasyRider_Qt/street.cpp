#include "street.h"

#include <QGraphicsScene>

Street::Street(QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent) {
    setRect(0, 0, 100, 100);
}

void Street::init(int brickEdgeLeng)
{
    width = brickEdgeLeng;
    lenght = brickEdgeLeng;
    setRect(0, 0, width, lenght);
    setBrush(Qt::gray);

}
