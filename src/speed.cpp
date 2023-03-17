//
// Created by Yifan Yang on 2023-03-16.
//

#include "speed.h"


Speed::Speed() {
    name = "";
    speedX = 0.0;
    speedY = 0.0;
    speedZ = 0.0;
}

Speed::Speed(float _speedX, float _speedY, float _speedZ) {
    name = "";
    speedX = _speedX;
    speedY = _speedY;
    speedZ = _speedZ;
}

Speed::Speed(std::string _name, float _speedX, float _speedY, float _speedZ) {
    name = _name;
    speedX = _speedX;
    speedY = _speedY;
    speedZ = _speedZ;
}

Speed::~Speed() {

}
