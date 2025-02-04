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
public:
    Floor(int floorNumber_, int floorUIHeight_)
        : floorNumber(floorNumber_), floorUIHeight(floorUIHeight_) {}

    int getFloorNumber() const { return floorNumber; }
    int getFloorUIHeight() const { return floorUIHeight; }

    void setFloorNumber(int newFloorNumber) { floorNumber = newFloorNumber; }
    void setFloorUIHeight(int newFloorUIHeight) { floorUIHeight = newFloorUIHeight; }
};

#endif // FLOOR_H
