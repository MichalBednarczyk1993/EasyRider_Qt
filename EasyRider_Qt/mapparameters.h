#ifndef MAPPARAMETERS_H
#define MAPPARAMETERS_H


class MapParameters
{
public:
    MapParameters(bool isStreet);

private:
    bool isStreet; // false if sidewalk
};

#endif // MAPPARAMETERS_H
