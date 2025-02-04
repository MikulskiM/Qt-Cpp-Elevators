#ifndef REQUEST_H
#define REQUEST_H

#include "direction.h"
#include <iostream>

class Request
{
    int startFloor;
    int targetFloor;
    Direction direction;
    bool isAssigned;

public:
    Request(int startFloor_, int targetFloor_) {
        startFloor = startFloor_;
        targetFloor = targetFloor_;

        if (startFloor_ > targetFloor_) {
            direction = DOWN;
        }
        else if (startFloor_ < targetFloor_) {
            direction = UP;
        } else {
            std::cout << "\n\tRequest cancelled. Start floor = Target floor\n";
            throw direction;
        }

        isAssigned = false;
    }

    int getTargetFloor() {
        return targetFloor;
    }

    int getStartFloor() {
        return startFloor;
    }
};

#endif // REQUEST_H
