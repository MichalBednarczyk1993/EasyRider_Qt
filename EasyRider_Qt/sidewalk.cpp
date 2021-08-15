#include "sidewalk.h"

#include <QGraphicsScene>


Sidewalk::Sidewalk(QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent) {
    setRect(0, 0, 100, 100);
}

void Sidewalk::init(int brickEdgeLeng)
{
    width = brickEdgeLeng;
    lenght = brickEdgeLeng;
    setRect(0, 0, width, lenght);
    setBrush(Qt::green);

}
