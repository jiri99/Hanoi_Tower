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

class Tower : public QWidget
{
    Q_OBJECT
public:
    vector<vector<int>> tower;

    QPainter painter;

    struct tah prev;
    struct tah next;

    int lenght;

    bool possible(struct tah a);
    bool start();
    bool solved();

    void move(struct tah a);
    struct tah thinking();
    void paint();
public:
    explicit Tower(int n, QWidget *parent = nullptr);
    virtual ~Tower();
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
};



/*class DrawingArea : public QWidget
{
public:
    Tower hanoi;
    explicit DrawingArea(int n, QWidget *parent = nullptr) : QWidget{parent} {
        hanoi = new Tower(n);
    };
    virtual ~DrawingArea();
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
};*/

#endif // TOWER_H
