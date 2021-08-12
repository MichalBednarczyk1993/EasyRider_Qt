#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "map.h"

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>


class Game: public QGraphicsView
{
public:
    Game(QWidget* parent = 0);

    QGraphicsScene* scene;
    Player* player;
    Map* map;

private:
    int xSize, ySize;

    void setScreenSize(int horizontal, int vertical);
};

#endif // GAME_H
