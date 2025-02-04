#include "mainwindow.h"
#include "floor.h"

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

//    Elevator elevator1(1, w.ui->elevator1

    return a.exec();
}
