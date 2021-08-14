#ifndef STREET_H
#define STREET_H

#include "mapfield.h"

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Street :
        public QObject,
        public QGraphicsRectItem,
        public MapField
{
        Q_OBJECT
public:
    Street(QGraphicsItem* parent=0);
    void init(int brickEdgeLeng);
};

#endif // STREET_H
