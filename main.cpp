#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElevatorManager elevatorManager;
    MainWindow w(nullptr, &elevatorManager);

    w.show();

    Floor floor0(0, FLOOR_0_Y, &elevatorManager);
    Floor floor1(1, FLOOR_1_Y, &elevatorManager);
    Floor floor2(2, FLOOR_2_Y, &elevatorManager);
    Floor floor3(3, FLOOR_3_Y, &elevatorManager);
    Floor floor4(4, FLOOR_4_Y, &elevatorManager);
    Floor floor5(5, FLOOR_5_Y, &elevatorManager);

    elevatorManager.addElevator(Elevator(1, w.getElevatorFrame(1)));
    elevatorManager.addElevator(Elevator(2, w.getElevatorFrame(2)));
    elevatorManager.addElevator(Elevator(3, w.getElevatorFrame(3)));

    return a.exec();
}
