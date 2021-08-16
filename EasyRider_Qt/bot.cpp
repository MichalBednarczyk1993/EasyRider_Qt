#include "bot.h"
#include "positioningutils.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <utility>
#include <math.h>

#include <QDebug>

Bot::Bot(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    this->map = map;
    this->brickEdgeLeng = brickEdgeLeng;

    vehicle.init(30, 30, 5);

    switch (rand() % 4) {
    case 1:
        vehicle.colour = Qt::blue;
        break;
    case 2:
        vehicle.colour = Qt::red;
        break;
    case 3:
        vehicle.colour = Qt::yellow;
        break;
    }

    // generate random direaction starting and position
    setRect(0, 0, vehicle.width, vehicle.leng);
    drawDirection();

    // connect a timer to move() vehicle after every timeout
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bot::setStartPos() {
    PositioningUtils positioning(map, brickEdgeLeng);
    std::pair<int, int> xy;
    int approxPos;

    if (moveAlong == yDir) {
        approxPos = rand() % (int)scene()->height();
        xy = positioning.getValidPos(false, isPositive, approxPos, true);
    } else {
        approxPos = rand() % (int)scene()->width();
        xy = positioning.getValidPos(true, isPositive, approxPos, true);
    }

    setPos(xy.first, xy.second);
}

void Bot::move()
{
    // move bot down
    moveRightDirection();

    // destroy bot when it goes out of the screen
    if (pos().y() > scene()->height() || pos().x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bot::drawDirection() {

    isPositive = rand() % 2;

    switch (rand() % 4) {
    case 0:
        dir = left;
        break;
    case 1:
        dir = right;
        break;
    case 2:
        dir = up;
        break;
    case 3:
        dir = down;
        break;
    }

    if (rand()%2 == 0) {
        moveAlong = xDir;
    } else {
        moveAlong = yDir;
    }

}

void Bot::moveRightDirection()
{
    int x = pos().x();
    int y = pos().y();

    randChangeDirection();

    switch (dir) {
    case left:
        x -= vehicle.speed;
        break;
    case right:
        x += vehicle.speed;
        break;
    case up:
        y -= vehicle.speed;
        break;
    case down:
        y += vehicle.speed;
        break;
    }

    setPos(x, y);
}

void Bot::randChangeDirection()
{
    // find possible dirs
    std::vector<Dir> options = findPossibleDirs();

    if(options.size() > 1) {
        // rand change dir
        dir = options[(rand() % options.size())-1];
    } else if (options.empty()) {
        switch (dir) {
        case left:
            dir = right;
            break;
        case right:
            dir = left;
            break;
        case up:
            dir = down;
            break;
        case down:
            dir = up;
            break;
        }
    } else {
        dir = options[0];
    }
}

std::vector<Bot::Dir> Bot::findPossibleDirs()
{
    std::vector<Dir> options;
    int roadPart = std::floor(brickEdgeLeng / 10);
    int xPos = pos().x();
    int yPos = pos().y();
    int xBrick = std::floor(xPos / brickEdgeLeng);
    int yBrick = std::floor(yPos / brickEdgeLeng);

    qDebug() << "x: " << xBrick << ", y: " << yBrick;

    switch (dir) {
    case left:
        if (xPos % brickEdgeLeng == roadPart * 6 && yBrick > 0 &&
                map->at(yBrick-1)[xBrick] == true) {
            options.push_back(Dir::up);

        } else if (xPos % brickEdgeLeng == roadPart * 1 &&
                   yBrick < (int) map->size()-1 &&
                   map->at(yBrick+1)[xBrick] == true) {
            options.push_back(Dir::down);

        } else if (xBrick > 0 && map->at(yBrick)[xBrick-1] == true) {
            options.push_back(Dir::left);
        }
        break;
    case right:
        if (xPos % brickEdgeLeng == roadPart * 6 && yBrick > 0 &&
                map->at(yBrick-1)[xBrick] == true) {
            options.push_back(Dir::up);

        } else if (xPos % brickEdgeLeng == roadPart * 1 &&
                   yBrick < (int) map->size()-1 &&
                   map->at(yBrick+1)[xBrick] == true) {
            options.push_back(Dir::down);

        } else if (xBrick < (int) map->at(0).size()-1 &&
                    map->at(yBrick)[xBrick+1] == true) {
            options.push_back(Dir::right);
        }
        break;
    case up:
        if (yPos % brickEdgeLeng == roadPart * 1 && xBrick > 0 &&
                map->at(yBrick)[xBrick-1] == true) {
            options.push_back(Dir::left);

        } else if (yPos % brickEdgeLeng == roadPart * 6 &&
                   xBrick < (int) map->at(0).size()-1 &&
                   map->at(yBrick)[xBrick+1] == true) {
            options.push_back(Dir::left);

        } else if (yBrick > 0 && map->at(yBrick-1)[xBrick] == true) {
            options.push_back(Dir::up);
        }
        break;
    case down:
        if (yPos % brickEdgeLeng == roadPart * 1 && xBrick > 0 &&
                map->at(yBrick)[xBrick-1] == true) {
            options.push_back(Dir::left);

        } else if (yPos % brickEdgeLeng == roadPart * 6 &&
                   xBrick < (int) map->at(0).size()-1 &&
                   map->at(yBrick)[xBrick+1] == true) {
            options.push_back(Dir::right);

        } else if (yBrick < (int) map->size()-1 &&
                   map->at(yBrick+1)[xBrick] == true) {
            options.push_back(Dir::down);
        }
        break;
    }

    return options;
}
