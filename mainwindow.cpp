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
    std::cout << "elevator: " << elevator << "\n";
    std::cout << "direction: " << direction << "\n";

    ui->elevator1->move(ui->elevator1->x(), ui->elevator1->y() - 5);
}
