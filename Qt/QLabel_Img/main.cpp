#include "widget.h"
#include "dialog.h"

#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    Dialog d;
//    d.show();

    return a.exec();

}
