#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSlider>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 QWidget window;
 window.setFixedSize(960, 540);

 QPushButton *button = new QPushButton("Run", &window);

 QVBoxLayout *mainlayout = new QVBoxLayout;
 QHBoxLayout *navlayout = new QHBoxLayout;
 QHBoxLayout *displayout = new QHBoxLayout;

 QSlider *horizontalSliders = new QSlider(Qt::Horizontal);

 navlayout->addWidget(horizontalSliders);
 navlayout->addWidget(button);

 mainlayout->addLayout(displayout);
 mainlayout->addLayout(navlayout);
 window.setLayout(mainlayout);

 window.show();
 return app.exec();
}
