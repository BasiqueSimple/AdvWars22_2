#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include "./Terrains/plaine.h"
#include "./Units/units.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
