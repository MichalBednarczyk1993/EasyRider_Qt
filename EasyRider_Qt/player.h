#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

/**
 * @brief The Player class create and controll behaviour
 * of main object at this scene.
 */
class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    /**
     * @brief Player constructor
     * @param map - 2 dim vector of bool's which represents the playground,
     * where true is equal to part of the street, and false to walkway.
     * Vehicles are not allowed to move over walkway.
     * @param brickEdgeLeng - represents the size of single element of map
     * @param parent - by default scene
     */
    Player(std::vector<std::vector<bool>> *map, int brickEdgeLeng, QGraphicsItem* parent = 0);

    /**
     * @brief keyPressEvent is method allow to player move around the map
     * @param event - method will react for arrow key press events
     */
    void keyPressEvent(QKeyEvent* event);

public slots:
    /**
     * @brief spawn is method that will generate Bot object after SIGNAL
     */
    void spawn();

private:
    std::vector<std::vector<bool>> *map;
    int brickEdgeLeng;

    void moveIfNotColiding(int xDir, int yDir);
};

#endif // PLAYER_H
