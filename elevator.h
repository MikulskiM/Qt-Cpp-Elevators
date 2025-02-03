#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <list>
#include <iostream>
#include "direction.h"
#include "status.h"

class Elevator
{
    int id;
    int currentFloor;
    std::list<int> targetFloors;
    Direction direction = IDLE;
    Status status       = AVAILABLE;

public:
    Elevator(int id_);

    Direction getDirection();
    Status getStatus();

    void setDirection(Direction newDirection);
    void setStatus(Status newStatus);

    void addTargetFloor(int floor);
    void move(Direction direction);
    void stopAtFloor();
};

#endif // ELEVATOR_H
