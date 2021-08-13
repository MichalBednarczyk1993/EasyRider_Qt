#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "mapfield.h"

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <list>


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
    void generateMap();
    void setPlayer();
    void generateVehicles();
};

#endif // GAME_H
