#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "mapfield.h"

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class Sidewalk :
        public QObject,
        public QGraphicsRectItem,
        public MapField
{
    Q_OBJECT
public:
    Sidewalk(QGraphicsItem* parent=0);
    void init(int brickEdgeLeng);
};

#endif // SIDEWALK_H
