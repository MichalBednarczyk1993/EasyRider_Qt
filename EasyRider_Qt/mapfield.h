#ifndef MAPFIELD_H
#define MAPFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class MapField : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MapField(QGraphicsItem* parent = 0);
};

#endif // MAPFIELD_H
