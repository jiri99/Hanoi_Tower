#include <QApplication>

#include "navbar.h"

using namespace std;

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    Navbar nav;
    nav.show();

    return app.exec();
}
