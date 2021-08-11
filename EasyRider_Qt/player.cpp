#include "player.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player()
{
    setRect(0, 0, 30, 30);
}

void Player::keyPressEvent(QKeyEvent *event){

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
