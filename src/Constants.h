//
// Created by Yifan Yang on 2023-03-17.
//

#ifndef ATC_CONSTANTS_H
#define ATC_CONSTANTS_H



// Heights
const float BORDER_X = 10000;
const float BORDER_Y = 10000;
const float BORDER_Z = 25000;
const float BOTTOM_HEIGHT = 15000;

// Distance
const float MINIMUM_X = 1000;
const float MINIMUM_Y = 1000;
const float MINIMUM_Z = 3000;

// Speed
// Maximum cruising speed, knots
const float MAX_SPEED = 600;
// Minimum cruising speed, knots
const float MIN_SPEED = 250;
// Default cruising speed, knots
const float DEFAULT_SPEED = 500;
// Maximum altitude change rate, feet per minutes
const float MAX_ALT_CHANGE_RATE = 4000;

#endif //ATC_CONSTANTS_H