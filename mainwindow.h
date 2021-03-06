#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "ia.h"

#include <QActionGroup>
#include <QMainWindow>
#include <QtNetwork>

class ia;
class Game;

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
    void ShowContextMenuCapture(const QPoint &pos);
    void launch_event(int clic, int x, int y);
    
    void conv_coord(int &x, int &y);
    bool isMyTurn();

    void sendJson(QJsonObject obj);
public slots:
    void merge();
    void wait();
    void attack();
    void capture();//C'est cette ligne que j'ai modifié !!!!!
    void onNewConnection();
    void onConnected();
    void create_unit(int);
    void create_unit(int, bool);
    void onDisconnected();
    void onData();
private:
    Ui::MainWindow *ui;
    Game * game;
    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    quint32 currentSize = 0;
    bool isConfigured = false;
};

#endif // MAINWINDOW_H
