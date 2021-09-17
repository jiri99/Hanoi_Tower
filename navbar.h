#ifndef NAVBAR_H
#define NAVBAR_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>

#include "drawingarea.h"

class Navbar : public QMainWindow
{
    Q_OBJECT
    QWidget *window;
    QLCDNumber *lcd;
    QSlider *horizontalSlider;
    QPushButton *start;
    QHBoxLayout *navlayout;
    QAction *actRun;

    DrawingArea *area;
public:
    Navbar(QWidget *parent = nullptr);
    ~Navbar();
public slots:
    void run();
};

#endif // NAVBAR_H
