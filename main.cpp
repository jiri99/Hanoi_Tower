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

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    Navbar nav;
    nav.show();

    return app.exec();
}
