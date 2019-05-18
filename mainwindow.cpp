#include "game.h"
#include "imageholder.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <tuple>
#include <vector>
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QPainter>
#include <QMouseEvent>
#include <sstream>
#include <QSignalMapper>

#define FACTORY 1
#define AIRPORT 2
#define ATTACK 3
#define MERGE 4
#define MOVE 5

#define INFANTRY 0
#define BAZOOKA 1
#define BCOPTER 2
#define BOMBER 3
#define FIGHTER 4
#define ANTIAIR 5
#define MDTANK 6
#define MEGATANK 7
#define NEOTANK 8
#define RECON 9
#define TANK 10

#define LEFT 16777234
#define UP 16777235
#define RIGHT 16777236
#define DOWN 16777237
#define SKEY 83
#define SPACE 32
#define ENTER 16777220

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->game = new Game(1000, "bm");

    server = new QTcpServer();
    if(! server->listen(QHostAddress::Any, 8123)) {
        std::cout << "I am a client" << std::endl;
        game->setThisPlayer("bm");
        other = new QTcpSocket();
        connect(other, SIGNAL(connected()), this, SLOT(onConnected()));
        other->connectToHost("127.0.0.1", 8123);
        connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    } else {
        std::cout << "I am the server" << std::endl;
        game->setThisPlayer("os");
        other = nullptr;
    }

    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    ImageHolder* ih = new ImageHolder();

    map<int, QPixmap*> terrain;
       terrain[1]=ih->plain;
       terrain[2]=ih->mountain;
       terrain[3]=ih->wood;
       terrain[4]=ih->hriver;
       terrain[5]=ih->vriver;
       terrain[7]=ih->esriver;
       terrain[8]=ih->swriver;
       terrain[9]=ih->wnriver;
       terrain[10]=ih->neriver;
       terrain[15]=ih->hroad;
       terrain[16]=ih->vroad;
       terrain[18]=ih->esroad;
       terrain[19]=ih->swroad;
       terrain[20]=ih->wnroad;
       terrain[21]=ih->neroad;
       terrain[22]=ih->eswroad;
       terrain[23]=ih->swnroad;
       terrain[24]=ih->wneroad;
       terrain[25]=ih->nesroad;
       terrain[26]=ih->hbridge;
       terrain[29]=ih->hshoal;
       terrain[30]=ih->hshoaln;
       terrain[33]=ih->reef;
       terrain[34]=ih->neutralcity;
       terrain[35]=ih->neutralbase;
       terrain[36]=ih->neutralairport;
       terrain[39]=ih->orangestarbase;
       terrain[101]=ih->vpipe;
       terrain[102]=ih->hpipe;
       terrain[104]=ih->espipe;
       terrain[106]=ih->wnpipe;
       terrain[107]=ih->npipeend;
       terrain[108]=ih->epipeend;
       terrain[109]=ih->spipeend;
       terrain[110]=ih->wpipeend;
       terrain[44]=ih->bluemoonbase;
       terrain[45]=ih->bluemoonairport;
       terrain[43]=ih->bluemooncity;
       terrain[40]=ih->orangestarairport;
       terrain[38]=ih->orangestarcity;


       int map[17][21] = {{104,102,102,102,102,102,108,3,1,2,18,15,15,34,1,1,1,2,30,30,33},
                          {101,34,1,1,1,2,1,18,15,15,34,1,1,3,1,3,1,1,1,3,30},
                          {101,2,1,3,2,18,15,35,1,1,1,3,1,1,1,1,43,15,19,1,2},
                          {109,2,34,15,15,34,1,1,2,2,2,2,2,3,1,44,23,1,21,19,1},
                          {4,4,8,3,1,1,1,2,2,2,2,34,2,1,34,25,44,1,3,21,34},
                          {2,34,5,1,1,1,2,2,34,2,2,2,2,3,1,16,1,1,1,1,3},
                          {3,1,26,1,3,2,2,1,16,3,2,2,34,1,3,16,34,1,3,2,7},
                          {1,18,26,1,1,2,34,3,16,1,1,3,1,1,18,20,1,1,7,4,9},
                          {36,20,5,3,1,3,18,15,24,15,15,15,22,15,20,3,1,3,5,18,36},
                          {7,4,9,1,1,18,20,1,1,3,1,1,16,3,34,2,1,1,26,20,1},
                          {9,2,3,1,34,16,3,1,34,2,2,3,16,1,2,2,3,1,26,1,3},
                          {3,1,1,1,1,16,1,3,2,2,2,2,34,2,2,1,1,1,5,34,2},
                          {34,19,3,1,39,23,34,1,2,34,2,2,2,2,1,1,1,3,10,4,4},
                          {1,21,19,1,25,39,1,3,2,2,2,2,2,1,1,34,15,15,34,2,107},
                          {2,1,21,15,38,1,1,1,1,3,1,1,1,35,15,20,2,3,1,2,101},
                          {29,3,1,1,1,3,1,3,1,1,34,15,15,20,1,2,1,1,1,34,101},
                          {33,29,29,2,1,1,1,34,15,15,20,2,1,3,110,102,102,102,102,102,106}};
    int width = 1000;
    int size_img = width/21;
    int height = size_img*17;

    this->resize(width,height);

    int bigger_pics[] = {2,34,43,38};

    int big_pics[] = {36,40,45};

    for (unsigned int l = 0 ; l < 17 ; l++ )
       {
        for (int c = 0 ; c < 21 ; c++)
           {
                if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), map[l][c] ) != std::end(bigger_pics) ){
                    painter.drawPixmap(size_img*c,size_img*l-16,size_img,size_img+16,*terrain[map[l][c]]);
                }
                else if ( std::find(std::begin(big_pics), std::end(big_pics), map[l][c] ) != std::end(big_pics) ){
                    painter.drawPixmap(size_img*c,size_img*l-6,size_img,size_img+6,*terrain[map[l][c]]);
                }
                else if ( map[l][c] == 35 ){
                    painter.drawPixmap(size_img*c,size_img*l-29,size_img,size_img+29,*terrain[map[l][c]]);
                }
                else{
                    painter.drawPixmap(size_img*c,size_img*l,size_img,size_img,*terrain[map[l][c]]);
                }
           }
       }

    for(vector<Building*>::iterator it = game->getBuildings()->begin(); it != game->getBuildings()->end(); ++it)
    {
        int x = (*it)->getPosX();
        int y = (*it)->getPosY();
        conv_coord(x, y);
        if( (*it)->getTeam() == "os" ){
            if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), (*it)->getImage() ) != std::end(bigger_pics) ){
                painter.drawPixmap(x,y-16,size_img,size_img+16,*terrain[(*it)->getImage()]);
            }
            else if ( std::find(std::begin(big_pics), std::end(big_pics), (*it)->getImage() ) != std::end(big_pics) ){
                painter.drawPixmap(x,y-6,size_img,size_img+6,*terrain[(*it)->getImage()]);
            }
            else if ( (*it)->getImage() == 39 ){
                painter.drawPixmap(x,y-29,size_img,size_img+29,*terrain[(*it)->getImage()]);
            }
            else{
                painter.drawPixmap(x,y,size_img,size_img,*terrain[(*it)->getImage()]);
            }
        }
        else if( (*it)->getTeam() == "bm" ){
            if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), (*it)->getImage() ) != std::end(bigger_pics) ){
                painter.drawPixmap(x,y-16,size_img,size_img+16,*terrain[(*it)->getImage()]);
            }
            else if ( std::find(std::begin(big_pics), std::end(big_pics), (*it)->getImage() ) != std::end(big_pics) ){
                painter.drawPixmap(x,y-6,size_img,size_img+6,*terrain[(*it)->getImage()]);
            }
            else if ( (*it)->getImage() == 44 ){
                painter.drawPixmap(x,y-29,size_img,size_img+29,*terrain[(*it)->getImage()]);
            }
            else{
                painter.drawPixmap(x,y,size_img,size_img,*terrain[(*it)->getImage()]);
            }
        }
    }

    QPen pen = QPen();
    QFont font = QFont();
    font.setPixelSize(25);
    font.setBold(true);
    painter.setFont(font);
    for(vector<Unit*>::iterator it = game->getUnits()->begin(); it != game->getUnits()->end(); ++it)
    {
        int x = (*it)->getPosX();
        int y = (*it)->getPosY();
        conv_coord(x, y);
        if( (*it)->getTeam() == "bm" ) pen.setColor(Qt::blue);
        else pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.drawPixmap(x, y,size_img, size_img, (*it)->getimg());
        painter.drawText(x, y, QString::number((*it)->getPV()));
    }

    pen.setColor(Qt::black);
    painter.setPen(pen);
    for(vector<Terrain*>::iterator it = game->getHighlited()->begin(); it != game->getHighlited()->end(); ++it)
    {
        int x = (*it)->getPosX();
        int y = (*it)->getPosY();
        conv_coord(x, y);
        QRect rect = QRect(x,y,size_img,size_img);
        painter.drawRect(rect);
    }

    int x = game->getSelectedCase()->getPosX();
    int y = game->getSelectedCase()->getPosY();
    conv_coord(x, y);
    if( game->getThisPlayer()->getTeam() == "bm" ) pen.setColor(Qt::blue);
    else pen.setColor(Qt::red);
    pen.setWidth(3);
    painter.setPen(pen);
    QRect rect = QRect(x,y,size_img,size_img);
    painter.drawRect(rect);

    if(game->checkGameOver()){
        QMessageBox *box = new QMessageBox;
        QString go = QString::fromStdString("GAME OVER\nC'est "+game->getWinner()+" qui a gagné !");
        box->setInformativeText(go);
        box->show();
    }

    x = 16;
    y = 17;
    conv_coord(x, y);
    painter.drawText(x-10, y-20, QString("myTurn: ") + (isMyTurn() ? "true" : "false"));
}

void MainWindow::launch_event(int clic, int x, int y)
{
    QPoint pos;
    switch( clic ){
    case FACTORY:
        pos = *new QPoint(x,y);
        ShowContextMenuFactory(pos);
        break;
    case AIRPORT:
        pos = *new QPoint(x,y);
        ShowContextMenuAirport(pos);
        break;
    case ATTACK:
        pos = *new QPoint(x,y);
        ShowContextMenuAttack(pos);
        break;
    case MERGE:
        pos = *new QPoint(x,y);
        ShowContextMenuMerge(pos);
        break;
    case MOVE:
        QJsonObject json;
        json["action"] = MOVE;
        json["oldX"] = game->getPosBeforeMoved()->getPosX();
        json["oldY"] = game->getPosBeforeMoved()->getPosY();
        json["newX"] = x;
        json["newY"] = y;

        sendJson(json);
        break;
    }
    repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if( ! isMyTurn() )
            return;

    int x = event->x();
    int y = event->y();
    int clic = game->click_on(x,y);
    launch_event(clic, x, y);
}

bool MainWindow::isMyTurn(){
    return game->getCurrentPlayer()->getTeam() == game->getThisPlayer()->getTeam();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(! isMyTurn() )
            return;

    int key = event->key();
    cout << key << endl;
    QJsonObject json;
    switch ( event->key() )
          {
             case SKEY:
                cout << "Next" << endl;
                game->next_turn();
                json["action"] = SKEY;
                sendJson(json);
                repaint();
                break;
            case RIGHT:
               game->moveSelectedCase(RIGHT);
               repaint();
               break;
            case LEFT:
               game->moveSelectedCase(LEFT);
               repaint();
               break;
            case UP:
               game->moveSelectedCase(UP);
               repaint();
               break;
            case DOWN:
               game->moveSelectedCase(DOWN);
               repaint();
               break;
            case SPACE:
               { int x = game->getSelectedCase()->getPosX();
                int y = game->getSelectedCase()->getPosY();
                conv_coord(x, y);
                int clic = game->click_on(x, y);
                launch_event(clic, x, y);
                break;}
            case ENTER:
              { int x = game->getSelectedCase()->getPosX();
                int y = game->getSelectedCase()->getPosY();
                conv_coord(x, y);
                int clic = game->click_on(x, y);
                launch_event(clic, x, y);
                break;}
            }
}

void MainWindow::conv_coord(int &x, int &y){
    int width = 1000;
    int size_img = width/21;
    x *= size_img;
    y *= size_img;
}

void MainWindow::ShowContextMenuFactory(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;

    QAction *infant = myMenu.addAction("Infanterie-1000");
    QAction *bazoo = myMenu.addAction("Bazooka-3000");
    QAction *recon = myMenu.addAction("Reconnaissance-4000");
    QAction *tank = myMenu.addAction("Tank-7000");
    QAction *aa = myMenu.addAction("AntiAir-8000");
    QAction *mdtank = myMenu.addAction("MDTank-16000");
    QAction *megatank = myMenu.addAction("MegaTank-28000");
    QAction *neotank = myMenu.addAction("NeoTank-22000");

    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect (infant, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (bazoo, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (recon, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (tank, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (aa, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (mdtank, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (megatank, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (neotank, SIGNAL(triggered()), signalMapper, SLOT(map())) ;

    signalMapper -> setMapping (infant, INFANTRY) ;
    signalMapper -> setMapping (bazoo, BAZOOKA) ;
    signalMapper -> setMapping (recon, RECON) ;
    signalMapper -> setMapping (tank, TANK) ;
    signalMapper -> setMapping (aa, ANTIAIR) ;
    signalMapper -> setMapping (mdtank, MDTANK) ;
    signalMapper -> setMapping (megatank, MEGATANK) ;
    signalMapper -> setMapping (neotank, NEOTANK) ;

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(create_unit(int))) ;

    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuAirport(const QPoint &pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;

    QAction *bcopter = myMenu.addAction("bCopter-9000");
    QAction *bomber = myMenu.addAction("Bomber-22000");
    QAction *fighter = myMenu.addAction("Fighter-20000");

    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect (bcopter, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (bomber, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
    connect (fighter, SIGNAL(triggered()), signalMapper, SLOT(map())) ;

    signalMapper -> setMapping (bcopter, BCOPTER) ;
    signalMapper -> setMapping (bomber, BOMBER) ;
    signalMapper -> setMapping (fighter, FIGHTER) ;

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(create_unit(int))) ;

    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuAttack(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;
    QAction *attend = myMenu.addAction("Attendre");
    QAction *attaque = myMenu.addAction("Attaquer");
    connect(attend, SIGNAL(triggered()), this, SLOT(wait()));
    connect(attaque, SIGNAL(triggered()), this, SLOT(attack()));

    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuMerge(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;
    QAction *attend = myMenu.addAction("Attendre");
    QAction *fusionne = myMenu.addAction("Fusionner");
    connect(attend, SIGNAL(triggered()), this, SLOT(wait()));
    connect(fusionne, SIGNAL(triggered()), this, SLOT(merge()));

    myMenu.exec(globalPos);
}

void MainWindow::wait(){
    Unit* unit = game->getLastMovedUnit();
    unit->wait();
}

void MainWindow::attack(){
    Unit * selectedUnit = game->getSelectedUnit();
    game->getLastMovedUnit()->attack(selectedUnit, game->getTerrainAt(selectedUnit->getPosX(), selectedUnit->getPosY()));
    game->checkUnits();
    QJsonObject json;
    json["action"] = ATTACK;
    json["attackerX"] = game->getLastMovedUnit()->getPosX();
    json["attackerY"] = game->getLastMovedUnit()->getPosY();
    json["defendantX"] = game->getSelectedUnit()->getPosX();
    json["defendantY"] = game->getSelectedUnit()->getPosY();
    sendJson(json);
    this->repaint();
}

void MainWindow::merge(){
    game->getLastMovedUnit()->merge(game->getSelectedUnit());
    game->checkUnits();
    QJsonObject json;
    json["action"] = MERGE;
    json["fromX"] = game->getLastMovedUnit()->getPosX();
    json["fromY"] = game->getLastMovedUnit()->getPosY();
    json["intoX"] = game->getSelectedUnit()->getPosX();
    json["intoY"] = game->getSelectedUnit()->getPosY();
    sendJson(json);
    repaint();
}

void MainWindow::create_unit(int type){
    game->create_unit(type);
    QJsonObject unit_created;
    unit_created["action"] = FACTORY;
    unit_created["posX"] = game->getLastBuilding()->getPosX();
    unit_created["posY"] = game->getLastBuilding()->getPosY();
    unit_created["type"] = type;
    sendJson(unit_created);
    repaint();
}

void MainWindow::sendJson(QJsonObject obj) {
    QByteArray data = QJsonDocument(obj).toJson();
    QDataStream out(other);
    out << (quint32) data.length();
    other->write(data);
}

void MainWindow::onNewConnection() {
    std::cout << "A new client is connecting !" << std::endl;
    other = server->nextPendingConnection();
    connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));

    QJsonObject info;
    info["money"] = game->getEarnings();
    info["first"] = QString::fromStdString(game->getFirstPlayer());
    update();

    isConfigured = true;

    sendJson(info);
    update();
}

void MainWindow::onConnected() {
    std::cout << "I am connected" << std::endl;
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));
}

void MainWindow::onDisconnected() {
    std::cout << "The other guy just disconnected" << std::endl;
}

void MainWindow::onData() {
    if(currentSize == 0) {
        if(other->bytesAvailable() < 4) return;

        QDataStream in(other);
        in >> currentSize;
    }

    if(other->bytesAvailable() < currentSize) return;

    QByteArray data = other->read(currentSize);
    currentSize = 0;

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    if(! isConfigured) {
        int money = json["money"].toInt();
        QString first = json["first"].toString();
        game->setEarnings(money);
        game->setFirstPlayer(first.toStdString());
        update();
        isConfigured = true;
    } else {
        int action = json["action"].toInt();
        if ( action == MOVE ){
            int oldX = json["oldX"].toInt();
            int oldY = json["oldY"].toInt();
            int newX = json["newX"].toInt();
            int newY = json["newY"].toInt();


            if( Unit * unit = game->getUnitAt(oldX, oldY) ) {
                game->setSelectedUnit(unit);
                game->conv_coord(newX, newY);
                game->move_unit(newX, newY);
            }
            else {
                std::cerr << "ERROR" << std::endl;
                destroy();
                return;
            }
        }
        else if( action == FACTORY ){
            int posX = json["posX"].toInt();
            int posY = json["posY"].toInt();
            int type = json["type"].toInt();
            if( Building* building = game->getBuildingAt(posX, posY) ){
                game->setLastBuilding(building);
                game->create_unit(type);
            }
            else {
                std::cerr << "ERROR" << std::endl;
                destroy();
                return;
            }
        }
        else if( action == SKEY ){
            game->next_turn();
        }
        else if( action == ATTACK ){
            int x1 = json["attackerX"].toInt();
            int y1 = json["attackerY"].toInt();
            int x2 = json["defendantX"].toInt();
            int y2 = json["defendantY"].toInt();

            if( game->getLastMovedUnit()->isAt(x1, y1) && game->areNextToEachOther(x1, y1, x2, y2) ){
                game->getLastMovedUnit()->attack(game->getUnitAt(x2, y2), game->getTerrainAt(x2, y2));
                game->checkUnits();
            }
            else{
                std::cerr << "ERROR" << std::endl;
                destroy();
                return;
            }
        }
        else if( action == MERGE ){
            int x1 = json["fromX"].toInt();
            int y1 = json["fromY"].toInt();
            int x2 = json["intoX"].toInt();
            int y2 = json["intoY"].toInt();

            if( game->getLastMovedUnit()->isAt(x1, y1) && game->areNextToEachOther(x1, y1, x2, y2) ){
                game->getLastMovedUnit()->merge(game->getUnitAt(x2, y2));
                game->checkUnits();
            }
            else{
                std::cerr << "ERROR" << std::endl;
                destroy();
                return;
            }
        }
    }

    repaint();
}
