#include "game.h"

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
    bool street;

    for (int y = 0; y < ySize/brickEdgeLeng; y++) {
        for (int x = 0; x < xSize/brickEdgeLeng; x++) {
            MapField *mapfield = new MapField(brickEdgeLeng);
            scene->addItem(mapfield);
            mapfield->setPos(x*100, y*100);

            if (y%3 == 0 || x%4 == 0) {
                street = true;
            } else {
                street = false;
            }

            mapfield->setStreet(street);

        }
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
    // set player in the middle of scene
    player->setPos(xSize/2 - player->rect().width()/2, 600/2 - player->rect().height()/2);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
}

void Game::generateVehicles() {
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
}
