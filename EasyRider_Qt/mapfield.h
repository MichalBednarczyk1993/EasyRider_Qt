#ifndef MAPFIELD_H
#define MAPFIELD_H

class MapField
{

public:
    virtual void init(int brickEdgeLeng)=0;

protected:
    int width = 100;
    int lenght = 100;

};

#endif // MAPFIELD_H
