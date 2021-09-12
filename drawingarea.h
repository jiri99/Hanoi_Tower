#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QPainter>
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
    void closeEvent(QCloseEvent *evt) override;
signals:
    void clicked();
    void solved();
};

#endif // DRAWINGAREA_H
