#include "navbar.h"
#include "drawingarea.h"

#include <windows.h>

using namespace std;

const int N = 12;

Navbar::Navbar(QWidget *parent) : QMainWindow(parent)
{
    window = new QWidget();

    navlayout = new QHBoxLayout;
    lcd = new QLCDNumber();
    button = new QPushButton("Run");
    horizontalSlider = new QSlider(Qt::Horizontal);

    this->setFixedSize(500, 50);

    lcd->setPalette(Qt::black);
    lcd->display(3);

    horizontalSlider->setMaximum(N);
    horizontalSlider->setMinimum(1);
    horizontalSlider->setValue(3);
    QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    QObject::connect(button, SIGNAL(clicked()), this, SLOT (run()));

    navlayout->addWidget(lcd);
    navlayout->addWidget(horizontalSlider);
    navlayout->addWidget(button);

    window->setLayout(navlayout);
    this->setCentralWidget(window);
}

Navbar::~Navbar() {};

void Navbar::run() {
    int n = horizontalSlider->value();
    area = new DrawingArea(n, nullptr);

    cout << "Drawing area created" << endl;
    // area->resize(960, 540);
    area->show();
    /*tah m;
    while(!hanoi.solved()) {
        m = hanoi.thinking();
        hanoi.move(m);
    }*/
};
