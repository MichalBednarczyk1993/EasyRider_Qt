#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>


class Game: public QGraphicsView
{
public:
    Game(QWidget* parent = 0);

    QGraphicsScene* scene;
    Player* player;

private:
    int xSize, ySize;

    void setSceneProperties();
    void setScreenSize(int horizontal, int vertical);
    void setPlayer();
    void generateVehicles();
};

#endif // GAME_H
