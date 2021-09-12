#ifndef TOWER_H
#define TOWER_H

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

#include <iostream>
#include <vector>

using namespace std;

struct tah {
    int from;
    int to;
};

class Tower
{
public:
    vector<vector<int>> tower;

    struct tah prev;
    struct tah next;

    int lenght;

    Tower(int n);
    ~Tower() {};

    bool possible(struct tah a);
    bool start();
    bool solved();

    void move(struct tah a);
    struct tah thinking();
    void paint();
};


#endif // TOWER_H
