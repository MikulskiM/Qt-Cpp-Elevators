#include "floor.h"
#include "request.h"

void Floor::requestElevator(int targetFloor_) {
    Request request(floorNumber, targetFloor_);
    std::cout << "Elevator requested from floor " << floorNumber << " to floor " << targetFloor_ << "\n";
    elevatorManager->addRequest(request);
}
