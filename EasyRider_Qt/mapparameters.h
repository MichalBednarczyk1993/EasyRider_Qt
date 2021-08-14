#ifndef MAPPARAMETERS_H
#define MAPPARAMETERS_H


class MapParameters
{
public:
    MapParameters(bool isStreet, int brickEdgeLeng = 100);
    inline int getintBrickEdgeLeng() {return brickEdgeLeng;}
    inline bool getIsStreet() {return isStreet;}

private:
    int brickEdgeLeng = 100;
    bool isStreet; // false if sidewalk

};

#endif // MAPPARAMETERS_H
