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
    void ShowContextMenuFactory(const QPoint &pos);
    void ShowContextMenuAirport(const QPoint &pos);
    void ShowContextMenuAttack(const QPoint &pos);
    void ShowContextMenuMerge(const QPoint &pos);

    void launch_event(int clic, int x, int y);
    
    void conv_coord(int &x, int &y);
public slots:
    void fusionner();
    void attendre();
    void attaquer();
    void create_unit(int type);

private:
    Ui::MainWindow *ui;
    Game * game;

};

#endif // MAINWINDOW_H
