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

    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}
