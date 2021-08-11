#include "bot.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Bot::Bot(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // (later) random type: car, motorcycle, truck, pedestrian

    // generate random direaction starting and position
    drawDirection();
    setStartPos();

    // connect a timer to move() vehicle after every timeout
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bot::move()
{
    // move enemy down
    moveRigthWay();

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600 || pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }


}

void Bot::setStartPos() {
    int x = 0;
    int y = 0;

    if (axis == yDir) {
        x = 400; // in the midle of x axis
        if (!isPositive) {
            y = 600;
        }// else stay with 0
    } else {
        y = 300;
        if (!isPositive) {
            x = 800;
        }
    }

    setRect(x, y, 30, 30);

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
            y -= 5;
        } else {
            y += 5;
        }
    } else {
        if (!isPositive) {
            x -= 5;
        } else {
            x += 5;
        }
    }

    setPos(x, y);
}
