#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "positioningutils.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>

/**
 * @brief The Game class will initialize the game.
 * It has to be used each time you will create new instance
 * of this program.
 */
class Game: public QGraphicsView
{
public:
    Game();

private:
    QGraphicsScene* scene;
    Player* player;
    int xSize, ySize;
    std::vector<std::vector<bool>> streetPart;
    int brickEdgeLeng;

    void setSceneProperties();
    void setScreenSize(int horizontal, int vertical);
    void generateMap();
    void setPlayer();
    void generateVehicles();
};

#endif // GAME_H
