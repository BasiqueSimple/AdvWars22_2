#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MaFenetre m;
    m.show();*/

    QApplication app(argc, argv);

    QWidget menu;
    QPushButton *serveur = new QPushButton("Jouer en serveur", &menu);


    MainWindow mainwindow (&menu);


    QWidget::connect(serveur, SIGNAL(clicked()), &mainwindow, SLOT(show()));
    menu.show();

    return app.exec();
}
