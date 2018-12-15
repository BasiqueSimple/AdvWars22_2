#include "imageholder.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QPainter>
#include <sstream>
#include <map>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
       terrain[92]=ih->blackholebase;
       terrain[95]=ih->blackholehq;
       terrain[101]=ih->vpipe;
       terrain[102]=ih->hpipe;
       terrain[104]=ih->espipe;
       terrain[106]=ih->wnpipe;
       terrain[107]=ih->npipeend;
       terrain[108]=ih->epipeend;
       terrain[109]=ih->spipeend;
       terrain[110]=ih->wpipeend;
       terrain[123]=ih->jadesunbase;
       terrain[125]=ih->jadesunhq;


       int tableau[17][21] = {{104,102,102,102,102,102,108,3,1,2,18,15,15,34,1,1,1,2,30,30,33},
                                  {101,34,1,1,1,2,1,18,15,15,34,1,1,3,1,3,1,1,1,3,30},
                                  {101,2,1,3,2,18,15,35,1,1,1,3,1,1,1,1,125,15,19,1,2},
                                  {109,2,34,15,15,34,1,1,2,2,2,2,2,3,1,123,23,1,21,19,1},
                                  {4,4,8,3,1,1,1,2,2,2,2,34,2,1,34,25,123,1,3,21,34},
                                  {2,34,5,1,1,1,2,2,34,2,2,2,2,3,1,16,1,1,1,1,3},
                                  {3,1,26,1,3,2,2,1,16,3,2,2,34,1,3,16,34,1,3,2,7},
                                  {1,18,26,1,1,2,34,3,16,1,1,3,1,1,18,20,1,1,7,4,9},
                                  {36,20,5,3,1,3,18,15,24,15,15,15,22,15,20,3,1,3,5,18,36},
                                  {7,4,9,1,1,18,20,1,1,3,1,1,16,3,34,2,1,1,26,20,1},
                                  {9,2,3,1,34,16,3,1,34,2,2,3,16,1,2,2,3,1,26,1,3},
                                  {3,1,1,1,1,16,1,3,2,2,2,2,34,2,2,1,1,1,5,34,2},
                                  {34,19,3,1,92,23,34,1,2,34,2,2,2,2,1,1,1,3,10,4,4},
                                  {1,21,19,1,25,92,1,3,2,2,2,2,2,1,1,34,15,15,34,2,107},
                                  {2,1,21,15,95,1,1,1,1,3,1,1,1,35,15,20,2,3,1,2,101},
                                  {29,3,1,1,1,3,1,3,1,1,34,15,15,20,1,2,1,1,1,34,101},
                                  {33,29,29,2,1,1,1,34,15,15,20,2,1,3,110,102,102,102,102,102,106}};

    int width = 1000;
    int size_img = width/21;
    int height = size_img*17;
    this->resize(width,height);

    for (int l = 0 ; l < 17 ; l++)
       {
        for (int c = 0 ; c < 21 ; c++)
           {
                painter.drawPixmap(size_img*c,size_img*l,size_img,size_img,*terrain[tableau[l][c]]);
           }
       }
}
