#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSlider>
#include <QPainter>
#include <QStylePainter>
#include <QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QLCDNumber>
#include <QObject>

#include <iostream>
#include <windows.h>

#include "tower.h"

using namespace std;

const int N = 12;

void process(int n) {
    Tower hanoi(n);
    tah m;
    while(!hanoi.solved()) {
        m = hanoi.thinking();
        hanoi.move(m);
        Sleep(3000);
    }
}

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QWidget window;
    window.setFixedSize(500, 50);

    QHBoxLayout *navlayout = new QHBoxLayout;

    QLCDNumber *lcd = new QLCDNumber();
    lcd->setPalette(Qt::black);
    lcd->display(3);

    QSlider *horizontalSlider = new QSlider(Qt::Horizontal);
    horizontalSlider->setMaximum(N);
    horizontalSlider->setMinimum(1);
    horizontalSlider->setValue(3);
    QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    QPushButton *button = new QPushButton("Run", &window);
    // QObject::connect(button, SIGNAL(clicked()), horizontalSlider, SLOT (run(value(int))));

    navlayout->addWidget(lcd);
    navlayout->addWidget(horizontalSlider);
    navlayout->addWidget(button);

    window.setLayout(navlayout);
    window.show();

    int n = 5;

    Tower hanoi(n);
    tah m;
    m = hanoi.thinking();
    hanoi.move(m);

    hanoi.resize(960, 540);
    hanoi.show();

    return app.exec();
}
