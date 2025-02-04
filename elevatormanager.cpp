#include "elevatormanager.h"

ElevatorManager::ElevatorManager(){
    elevators = {};
    pendingRequests = {};
}

void ElevatorManager::assignElevator(Request request) {
    Elevator* bestElevator = nullptr;
    int minDistance = HIGHEST_FLOOR; // no need to use max int limit, right?

    std::cout << "Assigning elevator\n";

    for (auto& elevator : elevators) {
        // Check if elevator is on the same floor and available
        if (elevator.getCurrentFloor() == request.getStartFloor() && elevator.getStatus() == AVAILABLE) {

            std::cout << "Found elevator on the floor where the request was made\n";

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
        } else {
            std::cout << "No elevators on the request floor\n";
        }

        // If no direct elevator found, track the closest available elevator
        if (elevator.getStatus() == AVAILABLE) {

            std::cout << "Found available elevator\n";

            int distance = abs(elevator.getCurrentFloor() - request.getStartFloor());
            if (distance < minDistance) {
                minDistance = distance;
                bestElevator = &elevator;
            }
        } else {
            std::cout << "No available elevators\n";
        }
    }

    // Assign request to the closest available elevator, if found
    if (bestElevator) {

        std::cout << "Assiging request to the elevator " << bestElevator->getId() << "\n";

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
        std::cout << "Couldn't assign an elevator\n"
                     "No available elevator to handle the request." << std::endl;
        pendingRequests.push(request); // Add request to queue for later processing
    }
}

void ElevatorManager::addRequest(Request request) {
    // pendingRequests.push(request);
    // pendingRequests.pop
    std::cout << "Adding request(0, 3) to pending requests\n";
    assignElevator(request);
}
