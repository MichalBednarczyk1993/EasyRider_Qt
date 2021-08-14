#include "game.h"
#include "street.h"
#include "sidewalk.h"
#include "positioningutils.h"

#include <QTimer>


Game::Game(QWidget* parent)
{
    setScreenSize(1600, 1200);
    setSceneProperties();
    generateMap();
    setPlayer();
    generateVehicles();
    show();
}

void Game::setScreenSize(int horizontal, int vertical) {
    xSize = horizontal;
    ySize = vertical;
}

void Game::generateMap() {
    int brickEdgeLeng = 100; // Brick dimentions = 100x100

    for (int y = 0; y < ySize/brickEdgeLeng; y++) {
        std::vector<MapParameters> row;
        for (int x = 0; x < xSize/brickEdgeLeng; x++) {
            if (y%3 == 0 || x%4 == 0) {
                Street *mapfield = new Street();
                scene->addItem(mapfield);
                mapfield->setPos(x*brickEdgeLeng, y*brickEdgeLeng);
                mapfield->init(brickEdgeLeng);
                row.push_back(new MapParameters(true));
            } else {
                Sidewalk *mapfield = new Sidewalk();
                scene->addItem(mapfield);
                mapfield->setPos(x*brickEdgeLeng, y*brickEdgeLeng);
                mapfield->init(brickEdgeLeng);
                row.push_back(new MapParameters(false));
            }
        }
        map.push_back(row);
    }
}

void Game::setSceneProperties() {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, xSize, ySize);
    setScene(scene);
    setFixedSize(xSize, ySize);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::setPlayer() {
    player = new Player();
    // set player at the bottom of the scene
    PositioningUtils utils = PositioningUtils(map);
    std::pair<int, int> pos = utils.getValidPos(false, false, xSize/2, true);
    player->setPos(std::get<0>(pos), std::get<1>(pos));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
}

void Game::generateVehicles() {
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
}
