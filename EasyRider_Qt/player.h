#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Player(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem* parent = 0);
    void keyPressEvent(QKeyEvent* event);

public slots:
    void spawn();

private:
    std::vector<std::vector<bool>> *map;
    int brickEdgeLeng;

    void moveIfNotColiding(int xDir, int yDir);
};

#endif // PLAYER_H
