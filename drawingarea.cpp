#include "drawingarea.h"

DrawingArea::DrawingArea(int n, QWidget *parent) : QWidget{parent}
{
    hanoi = new Tower(n);
    resize(960, 540);
    connect(this, SIGNAL(clicked()), this, SLOT(repaint()));
}

void DrawingArea::mousePressEvent(QMouseEvent *) {
    tah m;
    m = hanoi->thinking();
    hanoi->move(m);

    emit clicked();
}

void DrawingArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

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

    double l = 130/(hanoi->lenght+1);
    cout << l << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < hanoi->lenght; j++) {
            if (hanoi->tower[i][j] != 0) {
                painter.fillRect(QRect(QPoint(l*(hanoi->lenght-hanoi->tower[i][j]+1)+310*i+30, 500-(hanoi->lenght - j)*45), QSize(2*l*hanoi->tower[i][j]+20, 45)), QColor::fromHsv((hanoi->tower[i][j]*360/(hanoi->lenght+1)), 200, 240));
            }
        }
    }
}
