#include "stdafx.h"
#include "myqwidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MyQwidget widget;
    widget.setWindowTitle("My Desine widget");
    widget.show();





    return a.exec();
}
