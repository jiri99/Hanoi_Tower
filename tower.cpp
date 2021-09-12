#include "tower.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

Tower::Tower(int n, QWidget *parent) : QWidget(parent)
{
    QPainter painter;

    vector<int> tower1;
    vector<int> tower2;
    vector<int> tower3;

    for(int i=0; i < n; i++){
        tower1.push_back(i+1);
        tower2.push_back(0);
        tower3.push_back(0);
    }

    tower.push_back(tower1);
    tower.push_back(tower2);
    tower.push_back(tower3);

    prev.from = 0;
    next.from = 0;
    prev.to = 0;
    next.to = 0;

    lenght = n;
}

Tower::~Tower() {};

bool Tower::possible(struct tah a) {
    int i = 0;
    int j = 0;
    do {
        i++;
    } while(i != lenght && tower[a.from][i] == 0);
    do {
        j++;
    } while(j != lenght && tower[a.to][j] == 0);
    if(j == lenght || tower[a.from][i] < tower[a.to][j]) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::start() {
    int i = 0;
    while (i < lenght && tower[0][i] == i + 1) {
        i++;
    }
    if (i == lenght) {
        return true;
    }
    else {
        return false;
    }
};

bool Tower::solved() {
    int i = 0;
    while (i < lenght && tower[2][i] == i + 1) {
        i++;
    }
    if (i == lenght) {
        return true;
    }
    else {
        return false;
    }
};

void Tower::move(struct tah a) {
    int i = 0;
    while (tower[a.from][i] == 0 && i < lenght) {
        i++;
    }
    int j = 0;
    while (tower[a.to][j] == 0 && j < lenght) {
        j++;
    }
    j--;
    tower[a.to][j] = tower[a.from][i];
    tower[a.from][i] = 0;
};

struct tah Tower::thinking() {
    if (start()) {
            next.from = 0;
            if (lenght % 2 == 0) {
                next.to = 2;
                return next;
            }
            else {
                next.to = 1;
                return next;
            }
        }
        else {
            struct tah a;
            struct tah b;
            a.from = 0;
            b.from = 0;
            a.to = 0;
            b.to = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int l = 0;
                    while (tower[i][l] == 0 && l < lenght) {
                        l++;
                    }
                    if (i != j && i != prev.to && b.from == 0 && b.to == 0 && tower[i][l] != 0) {
                        b.from = i;
                        b.to = j;
                        if (possible(b)) {
                            if (a.from == 0 && a.to == 0) {
                                cout << tower[b.from][l] << endl;
                                a.from = b.from;
                                a.to = b.to;
                                b.from = 0;
                                b.to = 0;
                            }
                        }
                        else {
                            b.from = 0;
                            b.to = 0;
                        }
                    }
                }
            }
            cout << a.from << endl;
            cout << a.to << endl;
            cout << b.from << endl;
            cout << b.to << endl;
            int i = 0;
            while (tower[a.to][i] == 0 && i < lenght) {
                i++;
            }
            if (b.from != 0 || b.to != 0) {
                int j = 0;
                while (tower[b.to][j] == 0 && j < lenght) {
                    j++;
                }
                if (tower[b.to][j] < tower[a.to][i]) {
                    next.from = b.from;
                    next.to = b.to;
                }
                else {
                    next.from = a.from;
                    next.to = a.to;
                }
            }
            else {
                next.from = a.from;
                next.to = a.to;
            }
            return next;
        }
};

void Tower::mouseMoveEvent(QMouseEvent *) {
    QPainter painter(this);
    tah m;
    m = thinking();
    move(m);

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

    double l = 130/(lenght+1);
    cout << l << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < lenght; j++) {
            if (tower[i][j] != 0) {
                painter.fillRect(QRect(QPoint(l*(lenght-tower[i][j]+1)+310*i+30, 500-(lenght - j)*45), QSize(2*l*tower[i][j]+20, 45)), QColor::fromHsv((tower[i][j]*360/(lenght+1)), 200, 240));
            }
        }
    }
}

void Tower::paintEvent(QPaintEvent *)
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

    double l = 130/(lenght+1);
    cout << l << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < lenght; j++) {
            if (tower[i][j] != 0) {
                painter.fillRect(QRect(QPoint(l*(lenght-tower[i][j]+1)+310*i+30, 500-(lenght - j)*45), QSize(2*l*tower[i][j]+20, 45)), QColor::fromHsv((tower[i][j]*360/(lenght+1)), 200, 240));
            }
        }
    }
}
