#include <iostream>
#include <string>
#include "car.h"

using namespace std;

int main() {
    Car myCar;
    myCar.turnIgnitionOn();
    myCar.setSpeed(35);
    myCar.showCar();

    myCar.setSpeed(70);
    myCar.showCar();

    myCar.turnIgnitionOff();
    myCar.showCar();
    return 0; 
}
