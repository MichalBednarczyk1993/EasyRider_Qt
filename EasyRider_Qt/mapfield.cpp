#include "mapfield.h"

#include <QGraphicsScene>


MapField::MapField(int brickEdgeLeng, QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent)
{
    setRect(0, 0, brickEdgeLeng, brickEdgeLeng);
    width = brickEdgeLeng;
    lenght = brickEdgeLeng;
}

void MapField::setStreet(bool isStreet)
{
    street = isStreet;

    if (isStreet) {
        setBrush(Qt::gray);
    } else {
        setBrush(Qt::green);
    }
}


