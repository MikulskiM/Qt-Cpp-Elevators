#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevatormanager.h"
#include "floor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, ElevatorManager* manager = nullptr);
    ~MainWindow();
    void moveElevator(QFrame* elevator, Direction direction);
    QFrame* getElevatorFrame(int elevatorId);

private slots:
    void on_pushButton0_3_clicked();

    void on_pushButton5_5_clicked();

private:
    Ui::MainWindow *ui;
    ElevatorManager* elevatorManager;
};
#endif // MAINWINDOW_H
