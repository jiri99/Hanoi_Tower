#ifndef NAVBAR_H
#define NAVBAR_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>

#include "tower.h"

class Navbar : public QMainWindow
{
    Q_OBJECT
    QWidget *window;
    QLCDNumber *lcd;
    QSlider *horizontalSlider;
    QPushButton *button;
    QHBoxLayout *navlayout;
    QAction *actRun;

    Tower *hanoi;
public:
    Navbar(QWidget *parent = nullptr);
    ~Navbar();
public slots:
    void run();
};

#endif // NAVBAR_H
