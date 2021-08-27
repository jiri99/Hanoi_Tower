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

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QWidget window;
    window.setFixedSize(960, 540);

    QPushButton *button = new QPushButton("Run", &window);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    QHBoxLayout *navlayout = new QHBoxLayout;
    QHBoxLayout *displayout = new QHBoxLayout;

    QPainter painter;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawRect(QRect(80,120,200,100));

    QGraphicsView * scene = new QGraphicsView;

    QRectF r1(100.0, 200.1, 110.2, 106.3);

    scene->setSceneRect(r1);

    QSlider *horizontalSliders = new QSlider(Qt::Horizontal);

    displayout->addWidget(scene);

    navlayout->addWidget(horizontalSliders);
    navlayout->addWidget(button);

    mainlayout->addLayout(displayout);
    mainlayout->addLayout(navlayout);
    window.setLayout(mainlayout);

    window.show();
    return app.exec();
}
