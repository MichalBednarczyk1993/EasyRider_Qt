#include "player.h"
#include "sidewalk.h"
#include "street.h"
#include "bot.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player(QGraphicsItem* parent): QGraphicsRectItem(parent)
{
    setRect(0, 0, 30, 30);
}

void Player::keyPressEvent(QKeyEvent *event) {

    qDebug() << "test";

    switch (event->key()) {
    case Qt::Key_Left:
        setPos(x()-10,y());
        break;
    case Qt::Key_Right:
        setPos(x()+10,y());
        break;
    case Qt::Key_Up:
        setPos(x(),y()-10);
        break;
    case Qt::Key_Down:
        setPos(x(),y()+10);
        break;
    }
}

void Player::spawn() {
    Bot* bot = new Bot();
    scene()->addItem(bot);
    bot->setStartPos();
}

void Player::moveIfNotColiding(int xDir, int yDir) {
    setPos(xDir,yDir);
    // get a list of all the items currently colliding with player
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid (*(colliding_items[i])) == typeid(Sidewalk)) {
            // musi rozszerzac interferjs MapField do Klasy Street i Chodnik
        }
    }

}
