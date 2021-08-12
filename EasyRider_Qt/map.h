#ifndef MAP_H
#define MAP_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <vector>

struct Block {
    Block();
    Block(int width, int lenght, bool isStreet) {
        this->width = width;
        this->lenght = lenght;
        this->isStreet = isStreet;
    };
    void init(int width, int lenght) {
        this->width = width;
        this->lenght = lenght;
    };
    int width;
    int lenght;
    bool isStreet;
};


class Map: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Map(QGraphicsItem* parent = 0);
    void generateMap();
    std::vector<std::vector<Block>> getMap();

private:
    std::vector<std::vector<Block>> blockList;
};



#endif // MAP_H
