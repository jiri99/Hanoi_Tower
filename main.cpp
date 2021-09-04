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

#include "tower.h"

using namespace std;

const int N = 13;


class CustomWidget : public QWidget
{
public:
   explicit CustomWidget(QWidget *parent = nullptr) : QWidget{parent} {}
   void paintEvent(QPaintEvent *) override;
};

void CustomWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    /*auto r1 = rect().adjusted(10, 10, -10, -10);
    painter.setPen(Qt::white);
    painter.drawRect(r1);

    auto r2 = QRect{QPoint(0, 0), QSize(100, 100)};
    painter.setPen(QPen{Qt::black, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin});
    painter.drawRect(r2);*/

    QSize base_dim;
    base_dim = QSize(280, 30);
    QRect base1 = QRect(QPoint(30, 500), base_dim);
    QRect base2 = QRect(QPoint(340, 500), base_dim);
    QRect base3 = QRect(QPoint(650, 500), base_dim);
    painter.fillRect(base1, Qt::black);
    painter.fillRect(base2, Qt::black);
    painter.fillRect(base3, Qt::black);
    painter.drawRect(base1);
    painter.drawRect(base2);
    painter.drawRect(base3);

    QSize stand_dim;
    stand_dim = QSize(20, 480);
    QRect stand1 = QRect(QPoint(160, 20), stand_dim);
    QRect stand2 = QRect(QPoint(470, 20), stand_dim);
    QRect stand3 = QRect(QPoint(780, 20), stand_dim);
    painter.fillRect(stand1, Qt::black);
    painter.fillRect(stand2, Qt::black);
    painter.fillRect(stand3, Qt::black);
    painter.drawRect(stand1);
    painter.drawRect(stand2);
    painter.drawRect(stand3);
}

class MyClass {
public:
    Q_OBJECT
public slots:
    void run(int);
};

void MyClass::run(int k) {
    cout << k << endl;
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

    CustomWidget w;

    navlayout->addWidget(lcd);
    navlayout->addWidget(horizontalSlider);
    navlayout->addWidget(button);

    Tower pokus(5);
    tah m;
    m.from = 0;
    m.to = 1;

    cout << "Start of the test" << endl;
    cout << pokus.lenght << endl;
    if(pokus.start()) {
        cout << "Start"<< endl;
    }
    if(pokus.solved()) {
        cout << "Solved"<< endl;
    }
    pokus.move(m);

    for (int i = 0; i < pokus.tower.size(); i++) {
        for (int j = 0; j < pokus.lenght; j++) {
            cout << pokus.tower[i][j];
        }
        cout << endl;
    }

    window.setLayout(navlayout);
    window.show();

    // w.resize(960, 540);
    // w.show();

    return app.exec();
}
