#ifndef car_inc_h
#define car_inc_h
#include <iostream>
#include <string>

using namespace std;

class Car {
    bool isIgnitionOn;
    int speed;
public:
    void turnIgnitionOn();
    void turnIgnitionOff();
    void setSpeed(int);
    void showCar();
};
#endif
