#include "game.h"

#include <QTimer>


Game::Game(QWidget* parent)
{
    setScreenSize(1600, 1200);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, xSize, ySize);

    setScene(scene);
    setFixedSize(xSize, ySize);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    // set player in the middle of scene
    //TODO player should be always in the middle of the sceen
    player->setPos(xSize/2 - player->rect().width()/2, 600/2 - player->rect().height()/2);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);


    // generate enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}

void Game::setScreenSize(int horizontal, int vertical) {
    xSize = horizontal;
    ySize = vertical;
}
