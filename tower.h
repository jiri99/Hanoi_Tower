#ifndef TOWER_H
#define TOWER_H

#include <iostream>
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

using namespace std;

struct tah {
    int from;
    int to;
};

class Tower : public QWidget
{
public:
    vector<vector<int>> tower;

    QPainter painter;

    struct tah prev;
    struct tah next;

    int lenght;

    Tower(int n);

    bool possible(struct tah a);
    bool start();
    bool solved();

    void move(struct tah a);
    struct tah thinking();
    void paint();
public:
    explicit Tower(QWidget *parent = nullptr) : QWidget{parent} {}
    void paintEvent(QPaintEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
};

/*class CustomWidget : public QWidget
{
public:
   vector<vector<int>> tower;
   int lenght;
   explicit CustomWidget(vector<vector<int>>in_tower, int in_lenght, QWidget *parent = nullptr) : QWidget{parent} {
       tower = in_tower;
       lenght = in_lenght;
   }
   void paintEvent(QPaintEvent *) override;
};*/

#endif // TOWER_H
