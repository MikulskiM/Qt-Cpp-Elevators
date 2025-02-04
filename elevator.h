#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <list>
#include <iostream>
#include <QFrame>

#include "direction.h"
#include "status.h"

#define MOVE_STEP_SIZE 5

class Elevator
{
    int             id;
    int             currentFloor;
    std::list<int>  targetFloors;
    Direction       direction;
    Status          status;
    QFrame*         elevatorObject;

public:
    Elevator(int id_, QFrame* elevator_)
        : id(id_), currentFloor(0), targetFloors({}), direction(IDLE), status(AVAILABLE), elevatorObject(elevator_) {}

    Direction getDirection();
    Status getStatus();
    int getCurrentFloor();
    int getId();

    void setDirection(Direction newDirection);
    void setStatus(Status newStatus);

    void addTargetFloor(int floor);
    void move(Direction direction);
    void stopAtFloor();
};

#endif // ELEVATOR_H
