#include "car.h"

void Car::turnIgnitionOn() {
    this->isIgnitionOn = true;
}

void Car::turnIgnitionOff() {
    this->isIgnitionOn = false;
};


void Car::setSpeed(int speed) {

    if (isIgnitionOn == true) {
        if (speed >= 65) {
            this->speed = 65;
        }
        else {
            this->speed = speed;
        }
    }
    else if (isIgnitionOn == false){
        this->speed = 0;
    }

};


void Car::showCar() {
    if (isIgnitionOn == true) {
        cout << "Ignition is on." << endl;
        cout << "Speed is " << speed << endl;
    }
    else if (isIgnitionOn == false) {
        cout << "Ignition is off" << endl;
        cout << "Speed is " << speed << endl;
    }


};
