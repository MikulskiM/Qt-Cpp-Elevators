#ifndef FLOOR_H
#define FLOOR_H

#define FLOOR_0_Y 620
#define FLOOR_1_Y 510
#define FLOOR_2_Y 400
#define FLOOR_3_Y 285
#define FLOOR_4_Y 170
#define FLOOR_5_Y 60

#include "elevatormanager.h"

class Floor
{
    int floorNumber;
    int floorUIHeight;
    ElevatorManager* elevatorManager;
public:
    Floor(int floorNumber_, int floorUIHeight_, ElevatorManager* manager)
        : floorNumber(floorNumber_), floorUIHeight(floorUIHeight_), elevatorManager(manager) {}
    void requestElevator(int floor);
};

#endif // FLOOR_H
