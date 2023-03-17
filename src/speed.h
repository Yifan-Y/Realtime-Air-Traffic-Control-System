//
// Created by Yifan Yang on 2023-03-16.
//

#ifndef ATC_SPEED_H
#define ATC_SPEED_H

#include <string>

class Speed {
public:
    Speed();
    Speed(float _speedX, float _speedY, float _speedZ);
    Speed(std::string _name, float _speedX, float _speedY, float _speedZ);
    virtual ~Speed();

    std::string getName() {return name;};
    float getSpeedX() {return speedX;};
    float getSpeedY() {return speedY;};
    float getSpeedZ() {return speedZ;};

    void setName(std::string _name) {name = _name;};
    void setSpeedX(float _speedX) {speedX = _speedX;};
    void setSpeedY(float _speedY) {speedY = _speedY;};
    void setSpeedZ(float _speedZ) {speedZ = _speedZ;};



private:
    std::string name;
    float speedX;
    float speedY;
    float speedZ;
};

#endif //ATC_SPEED_H
