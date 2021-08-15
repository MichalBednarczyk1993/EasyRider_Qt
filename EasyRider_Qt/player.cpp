#include "player.h"
#include "sidewalk.h"
#include "street.h"
#include "bot.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem* parent): QGraphicsRectItem(parent)
{
    this->map = map;
    this->brickEdgeLeng = brickEdgeLeng;
    setRect(0, 0, 30, 30);
}

void Player::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
    case Qt::Key_Left:
        moveIfNotColiding(-10, 0);
        break;
    case Qt::Key_Right:
        moveIfNotColiding(10, 0);
        break;
    case Qt::Key_Up:
        moveIfNotColiding(0, -10);
        break;
    case Qt::Key_Down:
        moveIfNotColiding(0, 10);
        break;
    }
}

void Player::spawn() {
    Bot* bot = new Bot(map, brickEdgeLeng);
    scene()->addItem(bot);
    bot->setStartPos();
}

void Player::moveIfNotColiding(int xDir, int yDir) {
    setPos(x()+xDir,y()+yDir);
    // get a list of all the items currently colliding with player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug() << "colliding items size:" << colliding_items.size();

    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Sidewalk)) {
            setPos(x()-xDir, y()-yDir);
            qDebug() << "sidewalk";
        }
    }
}
