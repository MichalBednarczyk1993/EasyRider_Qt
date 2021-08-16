#ifndef VEHICLE_H
#define VEHICLE_H

#include <qnamespace.h>

class Vehicle
{
public:
    virtual void setValues() = 0;
    inline int getLength() {return length;}
    inline int getWidth() {return width;}
    inline int getSpeed() {return speed;}
    inline Qt::GlobalColor getColour() {return color;}

protected:
    int length;
    int width;
    int speed;
    Qt::GlobalColor color;

};

class BlueCar : public Vehicle {

    void setValues() {
        length = 30;
        width = 30;
        speed = 5;
        color = Qt::blue;
    }
};

class RedCar : public Vehicle {
    void setValues() {
        length = 30;
        width = 30;
        speed = 7;
        color = Qt::red;
    }
};

class YellowCar : public Vehicle {
    void setValues() {
        length = 30;
        width = 30;
        speed = 4;
        color = Qt::yellow;
    }
};

#endif // VEHICLE_H
