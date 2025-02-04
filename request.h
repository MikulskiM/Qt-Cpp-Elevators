#ifndef REQUEST_H
#define REQUEST_H

#include "direction.h"
#include <iostream>

class Request
{
    int startFloor;
    int targetFloor;
    Direction direction;
    bool isValid;

public:
    Request(int startFloor_, int targetFloor_)
            : startFloor(startFloor_), targetFloor(targetFloor_), isValid(true)
    {
        if (startFloor_ > targetFloor_) {
            direction = DOWN;
        }
        else if (startFloor_ < targetFloor_) {
            direction = UP;
        }
        else {
            std::cout << "Request cancelled. Start floor == Target floor\n";
            isValid = false;  // Set this request as invalid to later throw exception
        }
    }

    bool isValidRequest() { return isValid; }

    int getTargetFloor() { return targetFloor; }
    int getStartFloor() { return startFloor; }
};

#endif // REQUEST_H
