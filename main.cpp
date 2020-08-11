#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //Widget w2;
    //w2.show();
    w.show();
    return a.exec();
}
