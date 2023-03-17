//
// Created by Yifan Yang on 2023-03-16.
//

#include "position.h"
#include <math.h>

Position::Position() {
    name = "";
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Position::Position(float _x, float _y, float _z) {
    name = "";
    x = _x;
    y = _y;
    z = _z;
}

Position::Position(std::string _name, float _x, float _y, float _z) {
    name = _name;
    x = _x;
    y = _y;
    z = _z;
}

Position::~Position() {

}

float Position::distance2D(Position position) {
    return sqrtf( ( (x - position.getX()) * (x - position.getX()) ) +
                  ( (y - position.getY()) * (y - position.getY()) ) );
}

float Position::distance3D(Position position) {
    return sqrtf( ( (x - position.getX()) * (x - position.getX()) ) +
                  ( (y - position.getY()) * (y - position.getY()) ) +
                  ( (z - position.getZ()) * (z - position.getZ()) ) );
}

float Position::distance2D_(Position position1, Position position2) {
    return sqrtf( ( (position1.getX() - position2.getX()) * (position1.getX() - position2.getX()) ) +
                  ( (position1.getY() - position2.getY()) * (position1.getY() - position1.getY()) ) );
}

float Position::distance3D_(Position position1, Position position2) {
    return sqrtf( ( (position1.getX() - position2.getX()) * (position1.getX() - position2.getX()) ) +
                  ( (position1.getY() - position2.getY()) * (position1.getX() - position2.getY()) ) +
                  ( (position1.getZ() - position2.getZ()) * (position1.getZ() - position2.getZ()) ) );
}