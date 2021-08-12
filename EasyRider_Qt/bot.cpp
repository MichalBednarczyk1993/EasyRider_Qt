#include "bot.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Bot::Bot(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    //TODO random type: car, motorcycle, truck, pedestrian

    vehicle.init(30, 30, 5);

    // generate random direaction starting and position
    setRect(0, 0, vehicle.width, vehicle.leng);
    drawDirection();

    // connect a timer to move() vehicle after every timeout
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bot::setStartPos() {
    int x = 0;
    int y = 0;

    if (axis == yDir) {
        if (isPositive) {
            x = scene()->width()/2 + 10;// in the midle of x axis
            y = scene()->height();
        } else {
            x = scene()->width()/2 - 10 - vehicle.width;
        }
    } else {
        y = scene()->width()/2;;
        if (isPositive) {
            x = scene()->height();
        } else  {

        }
    }

    setPos(x, y);

}

void Bot::move()
{
    // move bot down
    moveRigthWay();

    // destroy bot when it goes out of the screen
    if (pos().y() > scene()->height() || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }


}

void Bot::drawDirection() {

    isPositive = rand() % 2;

    switch (rand() % 3) {
    case 0:
        dir = left;
        break;
    case 1:
        dir = rigth;
        break;
    case 2:
        dir = straight;
        break;
    }

    if (rand()%2 == 0) {
        axis = xDir;
    } else {
        axis = yDir;
    }

}

void Bot::moveRigthWay()
{
    int x = pos().x();
    int y = pos().y();

    if (axis == yDir) {
        if (!isPositive) {
            y -= vehicle.speed;
        } else {
            y += vehicle.speed;
        }
    } else {
        if (!isPositive) {
            x -= vehicle.speed;
        } else {
            x += vehicle.speed;
        }
    }

    setPos(x, y);
}
