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
    /**
     * @brief Bot constructor
     * @param map - 2 dim vector of bool's which represents the playground,
     * where true is equal to part of the street, and false to walkway.
     * Vehicles are not allowed to move over walkway.
     * @param brickEdgeLeng - represents the size of single element of map
     * @param parent - by default scene
     */
    Bot(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem *parent=0);

    /**
     * @brief setStartPos will set random start position and direction
     */
    void setStartPos();

    inline int getColour() {return vehicle.colour;};

public slots:
    /**
     * @brief move is a method that will move Bot object after SIGNAL
     */
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
