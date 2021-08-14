#include "positioningutils.h"

PositioningUtils::PositioningUtils(std::vector<std::vector<MapParameters> > map)
{
    this->map = map;
}

std::pair<int, int> PositioningUtils::getValidPos(bool alongXAxis, bool positiveDir, int approxValue, bool isVehicle)
{
    if (alongXAxis) {
        return getValidPosAlongXAxis(positiveDir, approxValue, isVehicle);
    } else {
        return getValidPosAlongYAxis(positiveDir, approxValue, isVehicle);
    }
}

int PositioningUtils::setAtRightRoadSide(bool alongXAxis, bool positiveDir)
{
    if (alongXAxis) {
        if (positiveDir) {
            return 10; //map[0][0].
        } else {
            return 60;
        }
    } else {
        if (!positiveDir) {
            return 10;
        } else {
            return 60;
        }
    }
}

std::pair<int, int> PositioningUtils::getValidPosAlongXAxis(bool positiveDir, int approxValue, bool isVehicle)
{
    if (map.empty()) {
        return std::pair<int, int>(0, 0);
    }

    int yIndex = 0;
    if (!positiveDir) {
        yIndex = map.size() - 1;
    }

    int approxBrick = (approxValue / map[0][0].getintBrickEdgeLeng()) - 1;

    if (!map[yIndex][approxBrick].getIsStreet()) {
        int i = 1;
        while (isVehicle == map[yIndex][approxBrick+i].getIsStreet() ||
               isVehicle == map[yIndex][approxBrick-i].getIsStreet()) {
            i++;
        }
        if (isVehicle == map[yIndex][approxBrick+i].getIsStreet()) {
            approxBrick += i;
        } else {
            approxBrick -= i;
        }
    }
    int xIndex = approxBrick * map[0][0].getintBrickEdgeLeng() +
            setAtRightRoadSide(true, positiveDir);

    return std::pair<int, int>(xIndex, yIndex);
}

std::pair<int, int> PositioningUtils::getValidPosAlongYAxis(bool positiveDir, int approxValue, bool isVehicle)
{
    if (map.empty()) {
        return std::pair<int, int>(0, 0);
    }

    int yIndex = 0;
    if (!positiveDir) {
        yIndex = map.size() - 1;
    }

    int approxBrick = (approxValue / map[0][0].getintBrickEdgeLeng()) - 1;

    if (!map[yIndex][approxBrick].getIsStreet()) {
        int i = 1;
        while (isVehicle == map[yIndex][approxBrick+i].getIsStreet() ||
               isVehicle == map[yIndex][approxBrick-i].getIsStreet()) {
            i++;
        }
        if (isVehicle == map[yIndex][approxBrick+i].getIsStreet()) {
            approxBrick += i;
        } else {
            approxBrick -= i;
        }
    }
    int xIndex = approxBrick * map[0][0].getintBrickEdgeLeng() +
            setAtRightRoadSide(true, positiveDir);

    return std::pair<int, int>(yIndex, xIndex);
}



