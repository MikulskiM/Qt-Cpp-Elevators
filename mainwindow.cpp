#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ElevatorManager* manager)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , elevatorManager(manager)
{
    ui->setupUi(this);

    // map all the buttons
    // Floor 0
    buttonToRequestMap[ui->pushButton0_0] = qMakePair(0, 0);
    buttonToRequestMap[ui->pushButton0_1] = qMakePair(0, 1);
    buttonToRequestMap[ui->pushButton0_2] = qMakePair(0, 2);
    buttonToRequestMap[ui->pushButton0_3] = qMakePair(0, 3);
    buttonToRequestMap[ui->pushButton0_4] = qMakePair(0, 4);
    buttonToRequestMap[ui->pushButton0_5] = qMakePair(0, 5);

    // Floor 1
    buttonToRequestMap[ui->pushButton1_0] = qMakePair(1, 0);
    buttonToRequestMap[ui->pushButton1_1] = qMakePair(1, 1);
    buttonToRequestMap[ui->pushButton1_2] = qMakePair(1, 2);
    buttonToRequestMap[ui->pushButton1_3] = qMakePair(1, 3);
    buttonToRequestMap[ui->pushButton1_4] = qMakePair(1, 4);
    buttonToRequestMap[ui->pushButton1_5] = qMakePair(1, 5);

    // Floor 2
    buttonToRequestMap[ui->pushButton2_0] = qMakePair(2, 0);
    buttonToRequestMap[ui->pushButton2_1] = qMakePair(2, 1);
    buttonToRequestMap[ui->pushButton2_2] = qMakePair(2, 2);
    buttonToRequestMap[ui->pushButton2_3] = qMakePair(2, 3);
    buttonToRequestMap[ui->pushButton2_4] = qMakePair(2, 4);
    buttonToRequestMap[ui->pushButton2_5] = qMakePair(2, 5);

    // Floor 3
    buttonToRequestMap[ui->pushButton3_0] = qMakePair(3, 0);
    buttonToRequestMap[ui->pushButton3_1] = qMakePair(3, 1);
    buttonToRequestMap[ui->pushButton3_2] = qMakePair(3, 2);
    buttonToRequestMap[ui->pushButton3_3] = qMakePair(3, 3);
    buttonToRequestMap[ui->pushButton3_4] = qMakePair(3, 4);
    buttonToRequestMap[ui->pushButton3_5] = qMakePair(3, 5);

    // Floor 4
    buttonToRequestMap[ui->pushButton4_0] = qMakePair(4, 0);
    buttonToRequestMap[ui->pushButton4_1] = qMakePair(4, 1);
    buttonToRequestMap[ui->pushButton4_2] = qMakePair(4, 2);
    buttonToRequestMap[ui->pushButton4_3] = qMakePair(4, 3);
    buttonToRequestMap[ui->pushButton4_4] = qMakePair(4, 4);
    buttonToRequestMap[ui->pushButton4_5] = qMakePair(4, 5);

    // Floor 5
    buttonToRequestMap[ui->pushButton5_0] = qMakePair(5, 0);
    buttonToRequestMap[ui->pushButton5_1] = qMakePair(5, 1);
    buttonToRequestMap[ui->pushButton5_2] = qMakePair(5, 2);
    buttonToRequestMap[ui->pushButton5_3] = qMakePair(5, 3);
    buttonToRequestMap[ui->pushButton5_4] = qMakePair(5, 4);
    buttonToRequestMap[ui->pushButton5_5] = qMakePair(5, 5);

    for (auto button : buttonToRequestMap.keys()) {
        connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveElevator(QFrame* elevator, Direction direction)
{
    int step;

    if (direction == UP) {
        std::cout << "Moving up\n";
        step = -MOVE_STEP_SIZE;
    } else {
        std::cout << "Moving down\n";
        step = MOVE_STEP_SIZE;
    }

    elevator->move(elevator->x(), elevator->y() + step);
}

QFrame* MainWindow::getElevatorFrame(int elevatorId)
{
    switch (elevatorId) {
        case 1: return ui->elevator1;
        case 2: return ui->elevator2;
        case 3: return ui->elevator3;
        default: return nullptr;
    }
}

void MainWindow::handleButtonClicked()
{
    // Check what button was clicked
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (!button || buttonToRequestMap.find(button) == buttonToRequestMap.end()) {
        return;
    } else {
        std::cout << "One of the elevator buttons was clicked!\n";
        std::cout << button << "\n";
    }

    auto floorPair = buttonToRequestMap[button];
    int startFloor = floorPair.first;
    int targetFloor = floorPair.second;

    std::cout << "Button mapped to request from floor " << startFloor << " to " << targetFloor << "\n";

    // Create and add request
    try {
        Request request(startFloor, targetFloor);

        if (!request.isValidRequest()) {
            std::cout << "Ignoring invalid request (start == target)\n";
            return;
        }

        std::cout << "Request created from floor " << startFloor << " to " << targetFloor << "\n";
        elevatorManager->addRequest(request);
    }
    catch (...) {
        std::cout << "ERROR: error while processing the request!\n";
    }
}
