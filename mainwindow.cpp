#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ElevatorManager* manager)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , elevatorManager(manager)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton0_3_clicked()
{
    Request request(0, 3);
    std::cout << "Created request(0, 3)\n";
    elevatorManager->addRequest(request);
    std::cout << "Added request(0, 3) to the pending requests\n";
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

void MainWindow::on_pushButton5_5_clicked()
{

}
