#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QActionGroup>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void ShowContextMenuCreateUsine(const QPoint &pos);
    void ShowContextMenuCreateAeroport(const QPoint &pos);

    void ShowContextMenuAttaquer(const QPoint &pos);

public slots:
    void attendre();
    void attaquer();
    void create_infant();
    void create_bazoo();
    void create_recon();
    void create_aa();
    void create_tank();
    void create_mdtank();
    void create_megatank();
    void create_neotank();
    void create_bcopter();
    void create_bomber();
    void create_fighter();
private:
    Ui::MainWindow *ui;
    Game game;
};

#endif // MAINWINDOW_H
