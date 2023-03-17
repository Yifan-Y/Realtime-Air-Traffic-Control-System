//
// Created by Yifan Yang on 2023-03-16.
//

#ifndef ATC_POSITION_H
#define ATC_POSITION_H

#include <string>
class Position {
public:
    Position();
    Position(float _x, float _y, float _z);
    Position(std::string _name, float _x, float _y, float _z);
    virtual ~Position();

    std::string getName() {return name;};
    float getX() {return x;};
    float getY() {return y;};
    float getZ() {return z;};

    void setName(std::string _name) {name = _name;};
    void setX(float _x) {x = _x;};
    void setY(float _y) {y = _y;};
    void setZ(float _z) {z = _z;};

    float distance3D(Position position);
    float distance2D(Position position);

    float distance3D_(Position position1, Position position2);
    float distance2D_(Position position1, Position position2);
private:
    std::string name;
    float x, y, z;
};


#endif //ATC_POSITION_H
