#include "game.h"

#include <QTimer>


Game::Game(QWidget* parent)
{
    setScreenSize(1600, 1200);
    setSceneProperties();
    setPlayer();
    generateVehicles();

    show();
}

void Game::setScreenSize(int horizontal, int vertical) {
    xSize = horizontal;
    ySize = vertical;
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
