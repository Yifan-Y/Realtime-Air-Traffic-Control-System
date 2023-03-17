//
// Created by Yifan Yang on 2023-03-16.
//

#include <string>
#include "flight.h"

Flight::Flight(std::string _id, Position _position, Speed _speed) {
    id = _id;
    position = _position;
    speed = _speed;
}

Flight::~Flight() {

}
