#include "positioningutils.h"

#include "QDebug"

PositioningUtils::PositioningUtils(std::vector<std::vector<bool> > *map, int brickEdgeLeng)
{
    this->streetPart = map;
    this->brickEdgeLeng = brickEdgeLeng;
}


/**
 * @brief PositioningUtils::getValidPos - will compute and return valid
 * position of vehicle (or pedestrian) at provided in constructor map.
 * Returned value will be close to expected approximate position.
 *
 * @param alongXAxis - true, if position will be set along X axis
 * @param positiveDir - true, if vehicle will be moving as values of
 * perpendiculal axis values will be growning
 * @param approxValue - approximate position along choosen axis
 * @param isVehicle - true if will ride over street
 *
 * @return std::pair <int, int> (xAxisPos, yAxisPos)
 */
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
    int brickLengPart = brickEdgeLeng / 10;

    // zmieniamy pozycję na osi X
    if (alongXAxis) {
        // będzie się poruszać w stronę rosnących wartości na osi Y (w dół mapy)
        if (positiveDir) {
            return brickLengPart; //map[0][0].
        } else {
            return 6 * brickLengPart;
        }
    } else {
        // będzie się poruszać w stronę rosnących wartości na osi X (prawa strona mapy)
        if (!positiveDir) {
            return brickLengPart;
        } else {
            return 6 * brickLengPart;
        }
    }
}

// startuje na osi X
// porusza się tak jak wartości Y rosną
// przybliżone położenie na osi X
std::pair<int, int> PositioningUtils::getValidPosAlongXAxis(bool positiveDir, int approxValue, bool isVehicle)
{
    if (streetPart->empty()) {
        return std::pair<int, int>(0, 0);
    }

    int yIndex = 0;
    int yPos = 0 + (brickEdgeLeng / 10); // + border
    if (!positiveDir) {
        yIndex = streetPart->size() - 1;
        yPos = ((streetPart->size() - 1) * brickEdgeLeng) + (brickEdgeLeng / 10);
    }

    int approxBrick = (approxValue / brickEdgeLeng) - 1;

    if (!streetPart->at(yIndex)[approxBrick]) {
        int i = 1;
        bool reach = false;
        while (!reach) {
            if (isVehicle == streetPart->at(yIndex)[approxBrick+i] ||
                    isVehicle == streetPart->at(yIndex)[approxBrick-i]) {
                reach = true;
            } else {
                i++;
            }
        }
        if (isVehicle == streetPart->at(yIndex)[approxBrick+i]) {
            approxBrick += i;
        } else {
            approxBrick -= i;
        }
    }
    int xPos = approxBrick * brickEdgeLeng + setAtRightRoadSide(true, positiveDir);

    return std::pair<int, int>(xPos, yPos);
}

// startuje na osi Y
// porusza się tak jak wartości X rosną
// przybliżone położenie na osi Y
std::pair<int, int> PositioningUtils::getValidPosAlongYAxis(bool positiveDir, int approxValue, bool isVehicle)
{
    if (streetPart->empty()) {
        return std::pair<int, int>(0, 0);
    }

    int xIndex = 0;
    int xPos = 0 + (brickEdgeLeng / 10); // + border
    if (!positiveDir) {
        xIndex = streetPart->at(0).size() - 1;
        xPos = ((streetPart->at(0).size() - 1) * brickEdgeLeng) + (brickEdgeLeng / 10);
    }

    int approxBrick = (approxValue / brickEdgeLeng) - 1;

    if (!streetPart->at(approxBrick)[xIndex]) {
        int i = 1;
        bool reach = false;
        while (!reach) {
            if (isVehicle == streetPart->at(approxBrick+i)[xIndex] ||
                    isVehicle == streetPart->at(approxBrick+i)[xIndex]) {
                reach = true;
            } else {
                i++;
            }
        }
        if (isVehicle == streetPart->at(approxBrick+i)[xIndex]) {
            approxBrick += i;
        } else {
            approxBrick -= i;
        }
    }
    int yPos = approxBrick * brickEdgeLeng + setAtRightRoadSide(true, positiveDir);

    return std::pair<int, int>(xPos, yPos);
}



