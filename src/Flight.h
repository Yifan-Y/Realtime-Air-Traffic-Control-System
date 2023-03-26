//
// Created by Yifan Yang on 2023-03-16.
//

#ifndef ATC_FLIGHT_H
#define ATC_FLIGHT_H

#include <string>
#include <ostream>
#include <cmath>


class Flight{
public:
    Flight(std::string _id, float _positionX, float _positionY, float _positionZ, float _speedX, float _speedY, float _speedZ);
    Flight(float time, std::string _id, float _positionX, float _positionY, float _positionZ, float _speedX, float _speedY, float _speedZ);
    virtual ~Flight();


    float getTime() {return time;};
    std::string getId() {return id;};
    float getPositionX() {return positionX;};
    float getPositionY() {return positionY;};
    float getPositionZ() {return positionZ;};
    float getSpeedX() {return speedX;};
    float getSpeedY() {return speedY;};
    float getSpeedZ() {return speedZ;};

    void setTime(float _time) {time = _time;};
    void setId(std::string _id) {id = _id;};
    void setPositionX(float _positionX) {positionX = _positionX;};
    void setPositionY(float _positionY) {positionY = _positionY;};
    void setPositionZ(float _positionZ) {positionZ = _positionZ;};
    void setSpeedX(float _speedX) {speedX = _speedX;};
    void setSpeedY(float _speedY) {speedY = _speedY;};
    void setSpeedZ(float _speedZ) {speedZ = _speedZ;};
    static void enRoute(Flight& flight);


    //std::ostream getLocation(Flight flight);
    //void getSpeed(Flight flight);
    static void updatePosition(Flight& flight, float _positionX, float _positionY, float _positionZ);
    void changeDirection(Flight flight, float _speedX, float _speedY, float _speedZ);

    friend std::ostream &operator<<(std::ostream &os, const Flight &flight);

private:
    float time{};
    std::string id;
    float positionX;
    float positionY;
    float positionZ;
    float speedX;
    float speedY;
    float speedZ;

};

#endif //ATC_FLIGHT_H
