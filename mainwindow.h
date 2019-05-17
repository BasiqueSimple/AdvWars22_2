#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QActionGroup>
#include <QMainWindow>
#include <QtNetwork>

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
    bool isMyTurn();
public slots:
    void fusionner();
    void attendre();
    void attaquer();
    void create_unit(int type);
    void onNewConnection();
    void onConnected();
    void onDisconnected();
    void onData();
private:
    Ui::MainWindow *ui;
    Game * game;
    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    quint32 currentSize = 0;
    bool isConfigured = false;
    void sendJson(QJsonObject obj);
};

#endif // MAINWINDOW_H
