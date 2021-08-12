#ifndef BOT_H
#define BOT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>


class Bot : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Bot(QGraphicsItem *parent=0);
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


    bool isPositive;
    Dir dir;
    Axis axis;

    void drawDirection();
    void moveRigthWay();
};




#endif // BOT_H
