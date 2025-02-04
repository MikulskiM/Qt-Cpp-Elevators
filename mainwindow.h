#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPushButton>

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
    void handleButtonClicked();

private:
    Ui::MainWindow *ui;
    ElevatorManager* elevatorManager;
    QMap<QPushButton*, QPair<int, int>> buttonToRequestMap; // maping buttons
};
#endif // MAINWINDOW_H
