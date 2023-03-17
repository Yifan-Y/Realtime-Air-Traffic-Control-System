//
// Created by Yifan Yang on 2023-03-16.
//

#ifndef ATC_FLIGHT_H
#define ATC_FLIGHT_H

#include <string>
#include "position.h"
#include "speed.h"

typedef struct {
    Position position;
    Speed speed;
} Route;

class Flight{
public:
    Flight(std::string _id, Position _position, Speed _speed);
    virtual ~Flight();

    std::string getId() {return id;};
    Position getPosition() {return position;};
    Speed getSpeed() {return speed;};

    void setId(std::string _id) {id = _id;};
    void setPosition(Position _position) {position = _position;};
    void setSpeed(Speed _speed) {speed = _speed;};

private:
    std::string id;
    Position position;
    Speed speed;

};

#endif //ATC_FLIGHT_H
