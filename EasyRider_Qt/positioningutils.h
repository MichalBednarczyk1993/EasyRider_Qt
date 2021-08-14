#ifndef POSITIONINGUTILS_H
#define POSITIONINGUTILS_H

#include "mapparameters.h"

#include <vector>
#include <utility>

class PositioningUtils
{
public:
    PositioningUtils();
    PositioningUtils(std::vector<std::vector<MapParameters>> map);
    std::pair<int, int> getValidPos(bool alongXAxis, bool positiveDir, int approxValue, bool isVehicle);
    int setAtRightRoadSide(bool alongXAxis, bool positiveDir);

private:
    std::vector<std::vector<MapParameters>> map;

    std::pair<int, int> getValidPosAlongXAxis(bool positiveDir, int approxValue, bool isVehicle);
    std::pair<int, int> getValidPosAlongYAxis(bool positiveDir, int approxValue, bool isVehicle);
};

#endif // POSITIONINGUTILS_H
