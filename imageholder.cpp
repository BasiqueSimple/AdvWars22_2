#include "imageholder.h"
#include <iostream>

ImageHolder::ImageHolder()
{
    this->plain = new QPixmap(":/terrain/doss/plain.gif");
    this->mountain = new QPixmap(":/terrain/doss/mountain.gif");
    this->wood = new QPixmap(":/terrain/doss/wood.gif");
    this->hriver = new QPixmap(":/terrain/doss/hriver.gif");
    this->vriver = new QPixmap(":/terrain/doss/vriver.gif");
    this->esriver = new QPixmap(":/terrain/doss/esriver.gif");
    this->swriver = new QPixmap(":/terrain/doss/swriver.gif");
    this->wnriver = new QPixmap(":/terrain/doss/wnriver.gif");
    this->neriver = new QPixmap(":/terrain/doss/neriver.gif");
    this->hroad = new QPixmap(":/terrain/doss/hroad.gif");
    this->vroad = new QPixmap(":/terrain/doss/vroad.gif");
    this->esroad = new QPixmap(":/terrain/doss/esroad.gif");
    this->swroad = new QPixmap(":/terrain/doss/swroad.gif");
    this->wnroad = new QPixmap(":/terrain/doss/wnroad.gif");
    this->neroad = new QPixmap(":/terrain/doss/neroad.gif");
    this->eswroad = new QPixmap(":/terrain/doss/eswroad.gif");
    this->swnroad = new QPixmap(":/terrain/doss/swnroad.gif");
    this->wneroad = new QPixmap(":/terrain/doss/wneroad.gif");
    this->nesroad = new QPixmap(":/terrain/doss/nesroad.gif");
    this->hbridge = new QPixmap(":/terrain/doss/hbridge.gif");
    this->hshoal = new QPixmap(":/terrain/doss/hshoal.gif");
    this->hshoaln = new QPixmap(":/terrain/doss/hshoaln.gif");
    this->reef = new QPixmap(":/terrain/doss/reef.gif");
    this->neutralcity = new QPixmap(":/terrain/doss/neutralcity.gif");
    this->neutralbase = new QPixmap(":/terrain/doss/neutralbase.gif");
    this->neutralairport = new QPixmap(":/terrain/doss/neutralairport.gif");
    this->blackholebase = new QPixmap(":/terrain/doss/blackholebase.gif");
    this->blackholehq = new QPixmap(":/terrain/doss/blackholehq.gif");
    this->vpipe = new QPixmap(":/terrain/doss/vpipe.gif");
    this->hpipe = new QPixmap(":/terrain/doss/hpipe.gif");
    this->espipe = new QPixmap(":/terrain/doss/espipe.gif");
    this->wnpipe = new QPixmap(":/terrain/doss/wnpipe.gif");
    this->npipeend = new QPixmap(":/terrain/doss/npipeend.gif");
    this->epipeend = new QPixmap(":/terrain/doss/epipeend.gif");
    this->spipeend = new QPixmap(":/terrain/doss/spipeend.gif");
    this->wpipeend = new QPixmap(":/terrain/doss/wpipeend.gif");
    this->jadesunbase = new QPixmap(":/terrain/doss/jadesunbase.gif");
    this->jadesunhq = new QPixmap(":/terrain/doss/jadesunhq.gif");
}
