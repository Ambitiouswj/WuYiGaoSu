#include "mainwindow.h"
#include <QApplication>
#include "QSplashScreen"
#include "windows.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pmap("start1.jpg");
    QSplashScreen sp(pmap);
    MainWindow w;
    sp.show();
    Sleep(2000);
    a.processEvents();
    w.show();
    sp.finish(&w);
    return a.exec();
}
