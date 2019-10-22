#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsPixmapItem>
#include "logic/imagePreprocessor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
