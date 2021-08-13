#ifndef MAPFIELD_H
#define MAPFIELD_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class MapField : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    MapField(int brickEdgeLeng, QGraphicsItem* parent = 0);
    void setStreet(bool isStreet);

private:
    int width = 100;
    int lenght = 100;
    bool street = false;

};

#endif // MAPFIELD_H
