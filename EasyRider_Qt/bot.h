#ifndef BOT_H
#define BOT_H

#include "positioningutils.h"

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>


class Bot : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bot(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem *parent=0);
    void setStartPos();

public slots:
    void move();

private:

    enum Dir {
        left,
        rigth,
        straight
    };

    enum Axis {
        xDir,
        yDir
    };

    struct Vehicle {

        void init(int lenght, int widht, int speed) {
            this->leng = lenght;
            this->width = widht;
            this->speed = speed;
        };
        int leng;
        int width;
        int speed;
    };

    bool isPositive;
    Dir dir;
    Axis axis;
    Vehicle vehicle;
    std::vector<std::vector<bool>> *map;
    int brickEdgeLeng;


    void drawDirection();
    void moveRigthWay();
};




#endif // BOT_H
