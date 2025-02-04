#include "elevatormanager.h"

ElevatorManager::ElevatorManager(){
    elevators = {};
    pendingRequests = {};
}

void ElevatorManager::assignElevator(Request request) {
    Elevator* bestElevator = nullptr;
    int minDistance = HIGHEST_FLOOR; // no need to use max int limit, right?

    for (auto& elevator : elevators) {
        // Check if elevator is on the same floor and available
        if (elevator.getCurrentFloor() == request.getStartFloor() && elevator.getStatus() == AVAILABLE) {
            elevator.setStatus(BUSY);
            elevator.addTargetFloor(request.getStartFloor());
            elevator.addTargetFloor(request.getTargetFloor());

            // Set direction based on start and target floor
            if (elevator.getCurrentFloor() > request.getStartFloor()) {
                elevator.setDirection(DOWN);
            } else {
                elevator.setDirection(UP);
            }
            return; // Task assigned - success
        }

        // If no direct elevator found, track the closest available elevator
        if (elevator.getStatus() == AVAILABLE) {
            int distance = abs(elevator.getCurrentFloor() - request.getStartFloor());
            if (distance < minDistance) {
                minDistance = distance;
                bestElevator = &elevator;
            }
        }
    }

    // Assign request to the closest available elevator, if found
    if (bestElevator) {
        bestElevator->setStatus(BUSY);
        bestElevator->addTargetFloor(request.getStartFloor());
        bestElevator->addTargetFloor(request.getTargetFloor());

        // Set direction for the elevator to reach the request start floor
        if (bestElevator->getCurrentFloor() > request.getStartFloor()) {
            bestElevator->setDirection(DOWN);
        } else {
            bestElevator->setDirection(UP);
        }
    } else {
        // wait() ?
        std::cout << "No available elevator to handle the request." << std::endl;
        pendingRequests.push(request); // Add request to queue for later processing
    }
}

void ElevatorManager::addRequest(Request request) {
    // pendingRequests.push(request);
    // pendingRequests.pop
    assignElevator(request);
}
