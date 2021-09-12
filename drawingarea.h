#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include "tower.h"

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    Tower *hanoi;
    DrawingArea(int n, QWidget *parent = nullptr);
    virtual ~DrawingArea() {
        delete hanoi;
    };
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
signals:
    void clicked();
};

#endif // DRAWINGAREA_H
