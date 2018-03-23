#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));// srand(1);  Ответ 1
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.showFullScreen();

    return a.exec();
}
