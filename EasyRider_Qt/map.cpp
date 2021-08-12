#include "map.h"

#include <QGraphicsScene>
#include <stdlib.h>

Map::Map(QGraphicsItem* parent): QObject(), QGraphicsRectItem(parent) {

}

void Map::generateMap() {
    blockList.clear();

    for (int y = 0; y < 10; y++) {
        std::vector<Block> row;
        for (int x = 0; x < 4; x++) {
            bool street = !(x%2); // true if block will be not a part of the street
            if (y%4 == 0) {
                street  = true;
            }
            Block block(100, 100, street);

        }
        blockList.push_back(row);
    }
}

std::vector<std::vector<Block>> Map::getMap() {
    return blockList;
}

