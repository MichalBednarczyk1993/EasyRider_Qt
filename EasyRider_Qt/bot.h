#ifndef BOT_H
#define BOT_H

#include "positioningutils.h"

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <vector>


class Bot : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bot(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem *parent=0);
    void setStartPos();
    inline int getColour() {return vehicle.colour;};

public slots:
    void move();

private:

    enum Dir {
        left,
        right,
        up,
        down
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
        int colour;
    };

    bool isPositive;
    Dir dir;
    Axis moveAlong;
    Vehicle vehicle;
    std::vector<std::vector<bool>> *map;
    int brickEdgeLeng;


    void drawDirection();
    void moveRightDirection();
    void randChangeDirection();
    std::vector<Dir> findPossibleDirs();


};




#endif // BOT_H
