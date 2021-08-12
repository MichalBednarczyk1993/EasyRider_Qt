#include "mapfield.h"

MapField::MapField(QGraphicsItem* parent) : QObject(), QGraphicsRectItem(parent)
{
    setRect(0, 0, 100, 100);
}
