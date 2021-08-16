#ifndef POSITIONINGUTILS_H
#define POSITIONINGUTILS_H

#include <vector>
#include <utility>

/**
 * @brief The PositioningUtils class helps to calculate valid position at map
 * for moving vehicles.
 */
class PositioningUtils
{
public:
    PositioningUtils();
    PositioningUtils(std::vector<std::vector<bool>> *map, int brickEdgeLeng);
    PositioningUtils(const PositioningUtils&) = default;
    PositioningUtils& operator=(const PositioningUtils& x);

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
    std::pair<int, int> getValidPos(bool alongXAxis, bool positiveDir, int approxValue, bool isVehicle);

    /**
     * @brief setAtRightRoadSide
     * @param alongXAxis - true, if vehicle will be riding along X axis
     * @param positiveDir - true, if vehicle will be moving as values of
     * axis values will be growning
     * @return position at axis that is perpendiculal to moving direction
     */
    int setAtRightRoadSide(bool alongXAxis, bool positiveDir);

private:
    std::vector<std::vector<bool>> *streetPart;
    int brickEdgeLeng;

    std::pair<int, int> getValidPosAlongXAxis(bool positiveDir, int approxValue, bool isVehicle);
    std::pair<int, int> getValidPosAlongYAxis(bool positiveDir, int approxValue, bool isVehicle);
};

#endif // POSITIONINGUTILS_H
