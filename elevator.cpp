#include "elevator.h"

Direction Elevator::getDirection() {
    return direction;
}

Status Elevator::getStatus() {
    return status;
}

int Elevator::getCurrentFloor() {
    return currentFloor;
}

int Elevator::getId() {
    return id;
}

void Elevator::setDirection(Direction newDirection) {
    direction = newDirection;
}

void Elevator::setStatus(Status newStatus) {
    status = newStatus;
}

void Elevator::addTargetFloor(int floor) {
    targetFloors.push_back(floor);
}

void Elevator::move(Direction direction) {
    if (direction == IDLE) {
        std::cout << "\n\tERROR:\tUSED IDLE DIRECTION IN THE move() FUNCTION!\n\n";
    }
    // linked rectangle moves up od down
    // checks if it's at the target floor
    // if target floor "open the door" -> stopAtFloor()
}

void Elevator::stopAtFloor() {
    std::cout << "STOPPED AT THE " << currentFloor << " FLOOR\n";
    // perform some quick animation, change color, wait for 10 seconds
    // and then set status to AVAILABLE and direction to IDLE if we finished all target floors
}
