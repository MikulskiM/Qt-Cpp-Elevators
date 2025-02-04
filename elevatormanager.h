#ifndef ELEVATORMANAGER_H
#define ELEVATORMANAGER_H

#include <queue>
#include "elevator.h"
#include "request.h"

#define HIGHEST_FLOOR 5

class ElevatorManager
{
    std::list<Elevator> elevators;
    std::queue<Request> pendingRequests;
public:
    ElevatorManager();
    void assignElevator(Request request);
    void addRequest(Request request);
};

#endif // ELEVATORMANAGER_H
