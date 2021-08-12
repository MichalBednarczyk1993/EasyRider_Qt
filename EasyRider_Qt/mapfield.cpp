#include "mapfield.h"

MapField::MapField(QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent)
{
    setRect(300, 300, 100, 100);
}
