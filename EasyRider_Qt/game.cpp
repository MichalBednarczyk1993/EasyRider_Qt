#include "game.h"
#include "street.h"
#include "sidewalk.h"
#include "positioningutils.h"

#include <QTimer>


Game::Game(QWidget* parent)
{
    setScreenSize(1200, 800);
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
    brickEdgeLeng = 100; // Brick dimentions = 100x100

    for (int y = 0; y < ySize/brickEdgeLeng; y++) {
        std::vector<bool> row;
        row.reserve(xSize/brickEdgeLeng);
        for (int x = 0; x < xSize/brickEdgeLeng; x++) {
            if (y%3 == 0 || x%4 == 0) {
                Street *mapfield = new Street();
                scene->addItem(mapfield);
                mapfield->setPos(x*brickEdgeLeng, y*brickEdgeLeng);
                mapfield->init(brickEdgeLeng);
                row.push_back(true);
            } else {
                Sidewalk *mapfield = new Sidewalk();
                scene->addItem(mapfield);
                mapfield->setPos(x*brickEdgeLeng, y*brickEdgeLeng);
                mapfield->init(brickEdgeLeng);
                row.push_back(false);
            }
        }
        streetPart.push_back(row);
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
    player = new Player(&streetPart, brickEdgeLeng);
    // set player at the bottom of the scene
    PositioningUtils utils = PositioningUtils(&streetPart, brickEdgeLeng);
    std::pair<int, int> pos = utils.getValidPos(true, false, xSize/2, true);
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
