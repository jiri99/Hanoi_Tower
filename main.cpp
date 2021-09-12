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
#include <QMainWindow>
#include <QLCDNumber>
#include <QObject>

#include <iostream>
#include <windows.h>
#include <vector>

#include "tower.h"
#include "navbar.h"

using namespace std;

/*class NavigationWindow : public QMainWindow
{
    Q_OBJECT
    QWidget *window;
    QLCDNumber *lcd;
    QSlider *horizontalSlider;
    QPushButton *button;
    QHBoxLayout *navlayout;
public:
    NavigationWindow(QWidget *parent = nullptr);
    ~NavigationWindow();
// public slots:
};

NavigationWindow::NavigationWindow(QWidget *parent) : QMainWindow(parent) {
    window = new QWidget;
    navlayout = new QHBoxLayout;
    lcd = new QLCDNumber();
    button = new QPushButton("Run");
    horizontalSlider = new QSlider(Qt::Horizontal);

    window->setFixedSize(500, 50);

    lcd->setPalette(Qt::black);
    lcd->display(3);

    horizontalSlider->setMaximum(N);
    horizontalSlider->setMinimum(1);
    horizontalSlider->setValue(3);
    // QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    // QObject::connect(button, SIGNAL(clicked()), horizontalSlider, SLOT (run(value(int))));

    navlayout->addWidget(lcd);
    navlayout->addWidget(horizontalSlider);
    navlayout->addWidget(button);

    window->setLayout(navlayout);
}

NavigationWindow::~NavigationWindow(){

}*/

/*class NavigationWindow : public QWidget
{
    Q_OBJECT
public:
    QWidget window;
    NavigationWindow(QWidget *parent = nullptr) : QWidget{parent} {
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
    }
    virtual ~NavigationWindow() {}
};*/

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

    Navbar nav;
    nav.show();

    return app.exec();
}
