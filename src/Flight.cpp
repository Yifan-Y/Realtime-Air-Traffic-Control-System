//
// Created by Yifan Yang on 2023-03-16.
//

#include <string>
#include "Flight.h"
#include "Utility.h"

Flight::Flight(float _time, std::string _id, float _positionX, float _positionY, float _positionZ, float _speedX,
               float _speedY, float _speedZ) {
    time = _time;
    id = _id;
    positionX = _positionX;
    positionY = _positionY;
    positionZ = _positionZ;
    speedX = _speedX;
    speedY = _speedY;
    speedZ = _speedZ;
}

Flight::Flight(std::string _id, float _positionX, float _positionY, float _positionZ, float _speedX, float _speedY,
               float _speedZ) {
    id = _id;
    positionX = _positionX;
    positionY = _positionY;
    positionZ = _positionZ;
    speedX = _speedX;
    speedY = _speedY;
    speedZ = _speedZ;
}

Flight::~Flight() = default;




void Flight::changeDirection(Flight flight, float _speedX, float _speedY, float _speedZ) {
    flight.setSpeedX(_speedX);
    flight.setSpeedY(_speedY);
    flight.setSpeedZ(_speedZ);
}


std::ostream &operator<<(std::ostream &os, const Flight &flight) {
    os << "time: " << flight.time << " id: " << flight.id << " positionX: " << flight.positionX << " positionY: "
       << flight.positionY << " positionZ: " << flight.positionZ << " speedX: " << flight.speedX << " speedY: "
       << flight.speedY << " speedZ: " << flight.speedZ;
    return os;
}

void Flight::updatePosition(Flight& flight, float _positionX, float _positionY, float _positionZ) {
    flight.setPositionX(_positionX);
    flight.setPositionY(_positionY);
    flight.setPositionZ(_positionZ);
}

void Flight::enRoute(Flight& flight) {
    float newPositionX = flight.getPositionX() + Utility::kphToFps(flight.getSpeedX());
    float newPositionY = flight.getPositionY() + Utility::kphToFps(flight.getSpeedY());
    float newPositionZ = flight.getPositionZ() + Utility::kphToFps(flight.getSpeedZ());
    updatePosition(flight, newPositionX, newPositionY, newPositionZ);
}


