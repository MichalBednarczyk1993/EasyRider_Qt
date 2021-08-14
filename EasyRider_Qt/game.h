#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "mapparameters.h"

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <vector>


class Game: public QGraphicsView
{
public:
    Game(QWidget* parent = 0);

    QGraphicsScene* scene;
    Player* player;


private:
    int xSize, ySize;
    std::vector<std::vector<MapParameters>> map;

    void setSceneProperties();
    void setScreenSize(int horizontal, int vertical);
    void generateMap();
    void setPlayer();
    void generateVehicles();
};

#endif // GAME_H
