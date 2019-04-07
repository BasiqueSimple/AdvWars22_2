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

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->game = *new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
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


       int tableau[17][21] = {{104,102,102,102,102,102,108,3,1,2,18,15,15,34,1,1,1,2,30,30,33},
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
                if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), tableau[l][c] ) != std::end(bigger_pics) ){
                    painter.drawPixmap(size_img*c,size_img*l-16,size_img,size_img+16,*terrain[tableau[l][c]]);
                }
                else if ( std::find(std::begin(big_pics), std::end(big_pics), tableau[l][c] ) != std::end(big_pics) ){
                    painter.drawPixmap(size_img*c,size_img*l-6,size_img,size_img+6,*terrain[tableau[l][c]]);
                }
                else if ( tableau[l][c] == 35 ){
                    painter.drawPixmap(size_img*c,size_img*l-29,size_img,size_img+29,*terrain[tableau[l][c]]);
                }
                else{
                    painter.drawPixmap(size_img*c,size_img*l,size_img,size_img,*terrain[tableau[l][c]]);
                }
           }
       }

    for(vector<Batiment*>::iterator it = this->game.getBatiments()->begin(); it != this->game.getBatiments()->end(); ++it)
    {
        int x = (*it)->getPosX();
        int y = (*it)->getPosY();
        if( (*it)->getTeam() == "os" ){
            if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), (*it)->getImage() ) != std::end(bigger_pics) ){
                painter.drawPixmap(size_img*x,size_img*y-16,size_img,size_img+16,*terrain[(*it)->getImage()]);
            }
            else if ( std::find(std::begin(big_pics), std::end(big_pics), (*it)->getImage() ) != std::end(big_pics) ){
                painter.drawPixmap(size_img*x,size_img*y-6,size_img,size_img+6,*terrain[(*it)->getImage()]);
            }
            else if ( (*it)->getImage() == 39 ){
                painter.drawPixmap(size_img*x,size_img*y-29,size_img,size_img+29,*terrain[(*it)->getImage()]);
            }
            else{
                painter.drawPixmap(size_img*x,size_img*y,size_img,size_img,*terrain[(*it)->getImage()]);
            }
        }
        else if( (*it)->getTeam() == "bm" ){
            if ( std::find(std::begin(bigger_pics), std::end(bigger_pics), (*it)->getImage() ) != std::end(bigger_pics) ){
                painter.drawPixmap(size_img*x,size_img*y-16,size_img,size_img+16,*terrain[(*it)->getImage()]);
            }
            else if ( std::find(std::begin(big_pics), std::end(big_pics), (*it)->getImage() ) != std::end(big_pics) ){
                painter.drawPixmap(size_img*x,size_img*y-6,size_img,size_img+6,*terrain[(*it)->getImage()]);
            }
            else if ( (*it)->getImage() == 44 ){
                painter.drawPixmap(size_img*x,size_img*y-29,size_img,size_img+29,*terrain[(*it)->getImage()]);
            }
            else{
                painter.drawPixmap(size_img*x,size_img*y,size_img,size_img,*terrain[(*it)->getImage()]);
            }
        }
    }

    for(unsigned int i = 0; i < this->game.getunits()->size(); ++i)
    {
        int x = (*this->game.getunits())[i]->getPosX();
        int y = (*this->game.getunits())[i]->getPosY();
        painter.drawPixmap(size_img*x, size_img*y,size_img, size_img, (*this->game.getunits())[i]->getimg());
    }

    for(vector<Terrain*>::iterator it = this->game.getHighlited()->begin(); it != this->game.getHighlited()->end(); ++it)
    {
        int x = (*it)->getPosX();
        int y = (*it)->getPosY();
        QRect rect = QRect(x*size_img,y*size_img,size_img,size_img);
        painter.drawRect(rect);
    }

    if(this->game.checkGameOver()){
        QMessageBox *box = new QMessageBox;
        QString go = QString::fromStdString("GAME OVER\nC'est "+this->game.getWinner()+" qui a gagné !");
        box->setInformativeText(go);
        box->show();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    int clic = this->game.click_on(x,y);
    if(clic==1){
        QPoint pos = *new QPoint(x,y);
        this->ShowContextMenuCreateUsine(pos);
    }
    if (clic==2){
        this->repaint();
        QPoint pos = *new QPoint(x,y);
        this->ShowContextMenuCreateAeroport(pos);
    }
    if (clic==3){
        this->repaint();
        QPoint pos = *new QPoint(x,y);
        this->ShowContextMenuAttaquer(pos);
    }
    if (clic==4){
        this->repaint();
        QPoint pos = *new QPoint(x,y);
        this->ShowContextMenuFusionner(pos);
    }
    this->repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch ( event->key() )
          {
             case 83:
                cout << "Next" << endl;
                this->game.joueur_suivant();
                this->repaint();
                break;
          }
}

void MainWindow::ShowContextMenuCreateUsine(const QPoint& pos)
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
    connect(infant, SIGNAL(triggered()), this, SLOT(create_infant()));
    connect(bazoo, SIGNAL(triggered()), this, SLOT(create_bazoo()));
    connect(recon, SIGNAL(triggered()), this, SLOT(create_recon()));
    connect(tank, SIGNAL(triggered()), this, SLOT(create_tank()));
    connect(aa, SIGNAL(triggered()), this, SLOT(create_aa()));
    connect(mdtank, SIGNAL(triggered()), this, SLOT(create_mdtank()));
    connect(megatank, SIGNAL(triggered()), this, SLOT(create_megatank()));
    connect(neotank, SIGNAL(triggered()), this, SLOT(create_neotank()));
    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuCreateAeroport(const QPoint &pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;

    QAction *bcopter = myMenu.addAction("bCopter-9000");
    QAction *bomber = myMenu.addAction("Bomber-22000");
    QAction *fighter = myMenu.addAction("Fighter-20000");
    connect(bcopter, SIGNAL(triggered()), this, SLOT(create_bcopter()));
    connect(bomber, SIGNAL(triggered()), this, SLOT(create_bomber()));
    connect(fighter, SIGNAL(triggered()), this, SLOT(create_fighter()));
    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuAttaquer(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;
    QAction *attend = myMenu.addAction("Attendre");
    QAction *attaque = myMenu.addAction("Attaquer");
    connect(attend, SIGNAL(triggered()), this, SLOT(attendre()));
    connect(attaque, SIGNAL(triggered()), this, SLOT(attaquer()));

    myMenu.exec(globalPos);
}

void MainWindow::ShowContextMenuFusionner(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu myMenu;
    QAction *attend = myMenu.addAction("Attendre");
    QAction *fusionne = myMenu.addAction("Fusionner");
    connect(attend, SIGNAL(triggered()), this, SLOT(attendre()));
    connect(fusionne, SIGNAL(triggered()), this, SLOT(fusionner()));

    myMenu.exec(globalPos);
}

void MainWindow::attendre(){
    Unit* unitpt = this->game.getDernier_bouge();
    unitpt->attendre();
}

void MainWindow::attaquer(){
    this->game.getDernier_bouge()->attaquer(this->game.getDernierUnit(), this->game.get_terrain_at(this->game.getDernierUnit()->getPosX(), this->game.getDernierUnit()->getPosY()));
    this->game.checkUnits();
    this->repaint();
}

void MainWindow::fusionner(){
    this->game.getDernier_bouge()->fusion(this->game.getDernierUnit());
    this->game.checkUnits();
    this->repaint();
}

void MainWindow::create_infant(){
    this->game.create_infant();
    this->repaint();
}

void MainWindow::create_bcopter(){
    this->game.create_bcopter();
    this->repaint();
}

void MainWindow::create_bomber(){
    this->game.create_bomber();
    this->repaint();
}

void MainWindow::create_fighter(){
    this->game.create_fighter();
    this->repaint();
}

void MainWindow::create_bazoo(){
    this->game.create_bazoo();
    this->repaint();
}

void MainWindow::create_recon(){
    this->game.create_recon();
    this->repaint();
}

void MainWindow::create_aa(){
    this->game.create_aa();
    this->repaint();
}

void MainWindow::create_tank(){
    this->game.create_tank();
    this->repaint();
}

void MainWindow::create_mdtank(){
    this->game.create_mdtank();
    this->repaint();
}

void MainWindow::create_megatank(){
    this->game.create_megatank();
    this->repaint();
}

void MainWindow::create_neotank(){
    this->game.create_neotank();
    this->repaint();
}


