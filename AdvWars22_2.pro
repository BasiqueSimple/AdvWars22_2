#-------------------------------------------------
#
# Project created by QtCreator 2018-12-06T11:28:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdvWars22_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    cell.cpp \
    game.cpp \
    ia.cpp \
    imageholder.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    menubox.cpp \
    ui.cpp \
    Units/units.cpp \
    Units/Unitair/unitair.cpp \
    Units/Unitair/unitairbcopter.cpp \
    Units/Unitair/unitairbomber.cpp \
    Units/Unitair/unitaitfighter.cpp \
    Units/Unitterreinfant/unitterreinfant.cpp \
    Units/Unitterreinfant/unitterreinfantbazooka.cpp \
    Units/Unitterreinfant/unitterreinfantinfant.cpp \
    Units/Unitterrenoinfant/unitterrenoinfant.cpp \
    Units/Unitterrenoinfant/unitterrenoinfantantiair.cpp \
    Units/Unitterrenoinfant/unitterrenoinfantmdtank.cpp \
    Units/Unitterrenoinfant/unitterrenoinfantmegatank.cpp \
    Units/Unitterrenoinfant/unitterrenoinfantneotank.cpp \
    Units/Unitterrenoinfant/unitterrenoinfantrecon.cpp \
    Units/Unitterrenoinfant/unitterrenoinfanttank.cpp \
    Batiments/batiments.cpp \
    Batiments/batimentsaeroport.cpp \
    Batiments/batimentsusine.cpp \
    Batiments/batimentsville.cpp \
    joueur.cpp


HEADERS += \
        mainwindow.h \
    cell.h \
    game.h \
    ia.h \
    imageholder.h \
    map.h \
    menubox.h \
    ui.h \
    cell.h \
    game.h \
    ia.h \
    imageholder.h \
    mainwindow.h \
    map.h \
    menubox.h \
    ui.h \
    cell.h \
    game.h \
    ia.h \
    imageholder.h \
    mainwindow.h \
    map.h \
    menubox.h \
    ui.h \
    cell.h \
    game.h \
    ia.h \
    imageholder.h \
    mainwindow.h \
    map.h \
    menubox.h \
    ui.h \
    Test/buildings.h \
    cell.h \
    game.h \
    ia.h \
    imageholder.h \
    mainwindow.h \
    map.h \
    menubox.h \
    ui.h \
    Units/units.h \
    Units/Unitterreinfant/unitterreinfant.h \
    Units/Unitterreinfant/unitterreinfantinfant.h \
    Units/Unitterreinfant/unitterreinfantbazooka.h \
    Units/Unitterrenoinfant/unitterrenoinfant.h \
    Units/Unitterrenoinfant/unitterrenoinfantrecon.h \
    Units/Unitterrenoinfant/unitterrenoinfanttank.h \
    Units/Unitterrenoinfant/unitterrenoinfantmdtank.h \
    Units/Unitterrenoinfant/unitterrenoinfantmegatank.h \
    Units/Unitterrenoinfant/unitterrenoinfantneotank.h \
    Units/Unitair/unitair.h \
    Units/Unitair/unitairbcopter.h \
    Units/Unitair/unitairfighter.h \
    Units/Unitair/unitairbomber.h \
    Batiments/batiments.h \
    Batiments/batimentsville.h \
    Batiments/batimentsusine.h \
    Batiments/batimentsaeroport.h \
    Units/Unitterrenoinfant/unitterrenoinfantantiair.h \
    joueur.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.txt \
    Advance Wars By Web 2.1_files/jquery-3.3.1.min.js.téléchargé \
    Advance Wars By Web 2.1_files/acidrainairport.gif \
    Advance Wars By Web 2.1_files/acidrainbase.gif \
    Advance Wars By Web 2.1_files/acidraincity.gif \
    Advance Wars By Web 2.1_files/acidraincomtower.gif \
    Advance Wars By Web 2.1_files/acidrainhq.gif \
    Advance Wars By Web 2.1_files/acidrainlab.gif \
    Advance Wars By Web 2.1_files/acidrainport.gif \
    Advance Wars By Web 2.1_files/amberblazeairport.gif \
    Advance Wars By Web 2.1_files/amberblazebase.gif \
    Advance Wars By Web 2.1_files/amberblazecity.gif \
    Advance Wars By Web 2.1_files/amberblazecomtower.gif \
    Advance Wars By Web 2.1_files/amberblazehq.gif \
    Advance Wars By Web 2.1_files/amberblazelab.gif \
    Advance Wars By Web 2.1_files/amberblazeport.gif \
    Advance Wars By Web 2.1_files/awbwlogo3.gif \
    Advance Wars By Web 2.1_files/blackholeairport.gif \
    Advance Wars By Web 2.1_files/blackholebase.gif \
    Advance Wars By Web 2.1_files/blackholecity.gif \
    Advance Wars By Web 2.1_files/blackholecomtower.gif \
    Advance Wars By Web 2.1_files/blackholehq.gif \
    Advance Wars By Web 2.1_files/blackholelab.gif \
    Advance Wars By Web 2.1_files/blackholeport.gif \
    Advance Wars By Web 2.1_files/bluemoonairport.gif \
    Advance Wars By Web 2.1_files/bluemoonbase.gif \
    Advance Wars By Web 2.1_files/bluemooncity.gif \
    Advance Wars By Web 2.1_files/bluemooncomtower.gif \
    Advance Wars By Web 2.1_files/bluemoonhq.gif \
    Advance Wars By Web 2.1_files/bluemoonlab.gif \
    Advance Wars By Web 2.1_files/bluemoonport.gif \
    Advance Wars By Web 2.1_files/browndesertairport.gif \
    Advance Wars By Web 2.1_files/browndesertbase.gif \
    Advance Wars By Web 2.1_files/browndesertcity.gif \
    Advance Wars By Web 2.1_files/browndesertcomtower.gif \
    Advance Wars By Web 2.1_files/browndeserthq.gif \
    Advance Wars By Web 2.1_files/browndesertlab.gif \
    Advance Wars By Web 2.1_files/browndesertport.gif \
    Advance Wars By Web 2.1_files/cobalticeairport.gif \
    Advance Wars By Web 2.1_files/cobalticebase.gif \
    Advance Wars By Web 2.1_files/cobalticecity.gif \
    Advance Wars By Web 2.1_files/cobalticecomtower.gif \
    Advance Wars By Web 2.1_files/cobalticehq.gif \
    Advance Wars By Web 2.1_files/cobalticelab.gif \
    Advance Wars By Web 2.1_files/cobalticeport.gif \
    Advance Wars By Web 2.1_files/criver.gif \
    Advance Wars By Web 2.1_files/croad.gif \
    Advance Wars By Web 2.1_files/epipeend.gif \
    Advance Wars By Web 2.1_files/espipe.gif \
    Advance Wars By Web 2.1_files/esriver.gif \
    Advance Wars By Web 2.1_files/esroad.gif \
    Advance Wars By Web 2.1_files/eswriver.gif \
    Advance Wars By Web 2.1_files/eswroad.gif \
    Advance Wars By Web 2.1_files/greenearthairport.gif \
    Advance Wars By Web 2.1_files/greenearthbase.gif \
    Advance Wars By Web 2.1_files/greenearthcity.gif \
    Advance Wars By Web 2.1_files/greenearthcomtower.gif \
    Advance Wars By Web 2.1_files/greenearthhq.gif \
    Advance Wars By Web 2.1_files/greenearthlab.gif \
    Advance Wars By Web 2.1_files/greenearthport.gif \
    Advance Wars By Web 2.1_files/greyskyairport.gif \
    Advance Wars By Web 2.1_files/greyskybase.gif \
    Advance Wars By Web 2.1_files/greyskycity.gif \
    Advance Wars By Web 2.1_files/greyskycomtower.gif \
    Advance Wars By Web 2.1_files/greyskyhq.gif \
    Advance Wars By Web 2.1_files/greyskylab.gif \
    Advance Wars By Web 2.1_files/greyskyport.gif \
    Advance Wars By Web 2.1_files/hbridge.gif \
    Advance Wars By Web 2.1_files/hpipe.gif \
    Advance Wars By Web 2.1_files/hpiperubble.gif \
    Advance Wars By Web 2.1_files/hpipeseam.gif \
    Advance Wars By Web 2.1_files/hriver.gif \
    Advance Wars By Web 2.1_files/hroad.gif \
    Advance Wars By Web 2.1_files/hshoal.gif \
    Advance Wars By Web 2.1_files/hshoaln.gif \
    Advance Wars By Web 2.1_files/jadesunairport.gif \
    Advance Wars By Web 2.1_files/jadesunbase.gif \
    Advance Wars By Web 2.1_files/jadesuncity.gif \
    Advance Wars By Web 2.1_files/jadesuncomtower.gif \
    Advance Wars By Web 2.1_files/jadesunhq.gif \
    Advance Wars By Web 2.1_files/jadesunlab.gif \
    Advance Wars By Web 2.1_files/jadesunport.gif \
    Advance Wars By Web 2.1_files/missilesilo.gif \
    Advance Wars By Web 2.1_files/missilesiloempty.gif \
    Advance Wars By Web 2.1_files/mountain.gif \
    Advance Wars By Web 2.1_files/nepipe.gif \
    Advance Wars By Web 2.1_files/neriver.gif \
    Advance Wars By Web 2.1_files/neroad.gif \
    Advance Wars By Web 2.1_files/nesriver.gif \
    Advance Wars By Web 2.1_files/nesroad.gif \
    Advance Wars By Web 2.1_files/neutralairport.gif \
    Advance Wars By Web 2.1_files/neutralbase.gif \
    Advance Wars By Web 2.1_files/neutralcity.gif \
    Advance Wars By Web 2.1_files/neutralcomtower.gif \
    Advance Wars By Web 2.1_files/neutrallab.gif \
    Advance Wars By Web 2.1_files/neutralport.gif \
    Advance Wars By Web 2.1_files/npipeend.gif \
    Advance Wars By Web 2.1_files/orangestarairport.gif \
    Advance Wars By Web 2.1_files/orangestarbase.gif \
    Advance Wars By Web 2.1_files/orangestarcity.gif \
    Advance Wars By Web 2.1_files/orangestarcomtower.gif \
    Advance Wars By Web 2.1_files/orangestarhq.gif \
    Advance Wars By Web 2.1_files/orangestarlab.gif \
    Advance Wars By Web 2.1_files/orangestarport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosairport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosbase.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscity.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscomtower.gif \
    Advance Wars By Web 2.1_files/pinkcosmoshq.gif \
    Advance Wars By Web 2.1_files/pinkcosmoslab.gif \
    Advance Wars By Web 2.1_files/pinkcosmosport.gif \
    Advance Wars By Web 2.1_files/plain.gif \
    Advance Wars By Web 2.1_files/purplelightningairport.gif \
    Advance Wars By Web 2.1_files/purplelightningbase.gif \
    Advance Wars By Web 2.1_files/purplelightningcity.gif \
    Advance Wars By Web 2.1_files/purplelightningcomtower.gif \
    Advance Wars By Web 2.1_files/purplelightninghq.gif \
    Advance Wars By Web 2.1_files/purplelightninglab.gif \
    Advance Wars By Web 2.1_files/purplelightningport.gif \
    Advance Wars By Web 2.1_files/redfireairport.gif \
    Advance Wars By Web 2.1_files/redfirebase.gif \
    Advance Wars By Web 2.1_files/redfirecity.gif \
    Advance Wars By Web 2.1_files/redfirecomtower.gif \
    Advance Wars By Web 2.1_files/redfirehq.gif \
    Advance Wars By Web 2.1_files/redfirelab.gif \
    Advance Wars By Web 2.1_files/redfireport.gif \
    Advance Wars By Web 2.1_files/reef.gif \
    Advance Wars By Web 2.1_files/sea.gif \
    Advance Wars By Web 2.1_files/spipeend.gif \
    Advance Wars By Web 2.1_files/swnriver.gif \
    Advance Wars By Web 2.1_files/swnroad.gif \
    Advance Wars By Web 2.1_files/swpipe.gif \
    Advance Wars By Web 2.1_files/swriver.gif \
    Advance Wars By Web 2.1_files/swroad.gif \
    Advance Wars By Web 2.1_files/tealgalaxyairport.gif \
    Advance Wars By Web 2.1_files/tealgalaxybase.gif \
    Advance Wars By Web 2.1_files/tealgalaxycity.gif \
    Advance Wars By Web 2.1_files/tealgalaxycomtower.gif \
    Advance Wars By Web 2.1_files/tealgalaxyhq.gif \
    Advance Wars By Web 2.1_files/tealgalaxylab.gif \
    Advance Wars By Web 2.1_files/tealgalaxyport.gif \
    Advance Wars By Web 2.1_files/vbridge.gif \
    Advance Wars By Web 2.1_files/vpipe.gif \
    Advance Wars By Web 2.1_files/vpiperubble.gif \
    Advance Wars By Web 2.1_files/vpipeseam.gif \
    Advance Wars By Web 2.1_files/vriver.gif \
    Advance Wars By Web 2.1_files/vroad.gif \
    Advance Wars By Web 2.1_files/vshoal.gif \
    Advance Wars By Web 2.1_files/vshoale.gif \
    Advance Wars By Web 2.1_files/whitenovaairport.gif \
    Advance Wars By Web 2.1_files/whitenovabase.gif \
    Advance Wars By Web 2.1_files/whitenovacity.gif \
    Advance Wars By Web 2.1_files/whitenovacomtower.gif \
    Advance Wars By Web 2.1_files/whitenovahq.gif \
    Advance Wars By Web 2.1_files/whitenovalab.gif \
    Advance Wars By Web 2.1_files/whitenovaport.gif \
    Advance Wars By Web 2.1_files/wneriver.gif \
    Advance Wars By Web 2.1_files/wneroad.gif \
    Advance Wars By Web 2.1_files/wnpipe.gif \
    Advance Wars By Web 2.1_files/wnriver.gif \
    Advance Wars By Web 2.1_files/wnroad.gif \
    Advance Wars By Web 2.1_files/wood.gif \
    Advance Wars By Web 2.1_files/wpipeend.gif \
    Advance Wars By Web 2.1_files/yellowcometairport.gif \
    Advance Wars By Web 2.1_files/yellowcometbase.gif \
    Advance Wars By Web 2.1_files/yellowcometcity.gif \
    Advance Wars By Web 2.1_files/yellowcometcomtower.gif \
    Advance Wars By Web 2.1_files/yellowcomethq.gif \
    Advance Wars By Web 2.1_files/yellowcometlab.gif \
    Advance Wars By Web 2.1_files/yellowcometport.gif \
    Advance Wars By Web 2.1_files/line.png \
    Advance Wars By Web 2.1_files/awbw_minify.css \
    Advance Wars By Web 2.1_files/overlib_mini_minify.js.téléchargé \
    Advance Wars By Web 2.1_files/jquery-3.3.1.min.js.téléchargé \
    Advance Wars By Web 2.1_files/acidrainairport.gif \
    Advance Wars By Web 2.1_files/acidrainbase.gif \
    Advance Wars By Web 2.1_files/acidraincity.gif \
    Advance Wars By Web 2.1_files/acidraincomtower.gif \
    Advance Wars By Web 2.1_files/acidrainhq.gif \
    Advance Wars By Web 2.1_files/acidrainlab.gif \
    Advance Wars By Web 2.1_files/acidrainport.gif \
    Advance Wars By Web 2.1_files/amberblazeairport.gif \
    Advance Wars By Web 2.1_files/amberblazebase.gif \
    Advance Wars By Web 2.1_files/amberblazecity.gif \
    Advance Wars By Web 2.1_files/amberblazecomtower.gif \
    Advance Wars By Web 2.1_files/amberblazehq.gif \
    Advance Wars By Web 2.1_files/amberblazelab.gif \
    Advance Wars By Web 2.1_files/amberblazeport.gif \
    Advance Wars By Web 2.1_files/awbwlogo3.gif \
    Advance Wars By Web 2.1_files/blackholeairport.gif \
    Advance Wars By Web 2.1_files/blackholebase.gif \
    Advance Wars By Web 2.1_files/blackholecity.gif \
    Advance Wars By Web 2.1_files/blackholecomtower.gif \
    Advance Wars By Web 2.1_files/blackholehq.gif \
    Advance Wars By Web 2.1_files/blackholelab.gif \
    Advance Wars By Web 2.1_files/blackholeport.gif \
    Advance Wars By Web 2.1_files/bluemoonairport.gif \
    Advance Wars By Web 2.1_files/bluemoonbase.gif \
    Advance Wars By Web 2.1_files/bluemooncity.gif \
    Advance Wars By Web 2.1_files/bluemooncomtower.gif \
    Advance Wars By Web 2.1_files/bluemoonhq.gif \
    Advance Wars By Web 2.1_files/bluemoonlab.gif \
    Advance Wars By Web 2.1_files/bluemoonport.gif \
    Advance Wars By Web 2.1_files/browndesertairport.gif \
    Advance Wars By Web 2.1_files/browndesertbase.gif \
    Advance Wars By Web 2.1_files/browndesertcity.gif \
    Advance Wars By Web 2.1_files/browndesertcomtower.gif \
    Advance Wars By Web 2.1_files/browndeserthq.gif \
    Advance Wars By Web 2.1_files/browndesertlab.gif \
    Advance Wars By Web 2.1_files/browndesertport.gif \
    Advance Wars By Web 2.1_files/cobalticeairport.gif \
    Advance Wars By Web 2.1_files/cobalticebase.gif \
    Advance Wars By Web 2.1_files/cobalticecity.gif \
    Advance Wars By Web 2.1_files/cobalticecomtower.gif \
    Advance Wars By Web 2.1_files/cobalticehq.gif \
    Advance Wars By Web 2.1_files/cobalticelab.gif \
    Advance Wars By Web 2.1_files/cobalticeport.gif \
    Advance Wars By Web 2.1_files/criver.gif \
    Advance Wars By Web 2.1_files/croad.gif \
    Advance Wars By Web 2.1_files/epipeend.gif \
    Advance Wars By Web 2.1_files/espipe.gif \
    Advance Wars By Web 2.1_files/esriver.gif \
    Advance Wars By Web 2.1_files/esroad.gif \
    Advance Wars By Web 2.1_files/eswriver.gif \
    Advance Wars By Web 2.1_files/eswroad.gif \
    Advance Wars By Web 2.1_files/greenearthairport.gif \
    Advance Wars By Web 2.1_files/greenearthbase.gif \
    Advance Wars By Web 2.1_files/greenearthcity.gif \
    Advance Wars By Web 2.1_files/greenearthcomtower.gif \
    Advance Wars By Web 2.1_files/greenearthhq.gif \
    Advance Wars By Web 2.1_files/greenearthlab.gif \
    Advance Wars By Web 2.1_files/greenearthport.gif \
    Advance Wars By Web 2.1_files/greyskyairport.gif \
    Advance Wars By Web 2.1_files/greyskybase.gif \
    Advance Wars By Web 2.1_files/greyskycity.gif \
    Advance Wars By Web 2.1_files/greyskycomtower.gif \
    Advance Wars By Web 2.1_files/greyskyhq.gif \
    Advance Wars By Web 2.1_files/greyskylab.gif \
    Advance Wars By Web 2.1_files/greyskyport.gif \
    Advance Wars By Web 2.1_files/hbridge.gif \
    Advance Wars By Web 2.1_files/hpipe.gif \
    Advance Wars By Web 2.1_files/hpiperubble.gif \
    Advance Wars By Web 2.1_files/hpipeseam.gif \
    Advance Wars By Web 2.1_files/hriver.gif \
    Advance Wars By Web 2.1_files/hroad.gif \
    Advance Wars By Web 2.1_files/hshoal.gif \
    Advance Wars By Web 2.1_files/hshoaln.gif \
    Advance Wars By Web 2.1_files/jadesunairport.gif \
    Advance Wars By Web 2.1_files/jadesunbase.gif \
    Advance Wars By Web 2.1_files/jadesuncity.gif \
    Advance Wars By Web 2.1_files/jadesuncomtower.gif \
    Advance Wars By Web 2.1_files/jadesunhq.gif \
    Advance Wars By Web 2.1_files/jadesunlab.gif \
    Advance Wars By Web 2.1_files/jadesunport.gif \
    Advance Wars By Web 2.1_files/missilesilo.gif \
    Advance Wars By Web 2.1_files/missilesiloempty.gif \
    Advance Wars By Web 2.1_files/mountain.gif \
    Advance Wars By Web 2.1_files/nepipe.gif \
    Advance Wars By Web 2.1_files/neriver.gif \
    Advance Wars By Web 2.1_files/neroad.gif \
    Advance Wars By Web 2.1_files/nesriver.gif \
    Advance Wars By Web 2.1_files/nesroad.gif \
    Advance Wars By Web 2.1_files/neutralairport.gif \
    Advance Wars By Web 2.1_files/neutralbase.gif \
    Advance Wars By Web 2.1_files/neutralcity.gif \
    Advance Wars By Web 2.1_files/neutralcomtower.gif \
    Advance Wars By Web 2.1_files/neutrallab.gif \
    Advance Wars By Web 2.1_files/neutralport.gif \
    Advance Wars By Web 2.1_files/npipeend.gif \
    Advance Wars By Web 2.1_files/orangestarairport.gif \
    Advance Wars By Web 2.1_files/orangestarbase.gif \
    Advance Wars By Web 2.1_files/orangestarcity.gif \
    Advance Wars By Web 2.1_files/orangestarcomtower.gif \
    Advance Wars By Web 2.1_files/orangestarhq.gif \
    Advance Wars By Web 2.1_files/orangestarlab.gif \
    Advance Wars By Web 2.1_files/orangestarport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosairport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosbase.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscity.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscomtower.gif \
    Advance Wars By Web 2.1_files/pinkcosmoshq.gif \
    Advance Wars By Web 2.1_files/pinkcosmoslab.gif \
    Advance Wars By Web 2.1_files/pinkcosmosport.gif \
    Advance Wars By Web 2.1_files/plain.gif \
    Advance Wars By Web 2.1_files/purplelightningairport.gif \
    Advance Wars By Web 2.1_files/purplelightningbase.gif \
    Advance Wars By Web 2.1_files/purplelightningcity.gif \
    Advance Wars By Web 2.1_files/purplelightningcomtower.gif \
    Advance Wars By Web 2.1_files/purplelightninghq.gif \
    Advance Wars By Web 2.1_files/purplelightninglab.gif \
    Advance Wars By Web 2.1_files/purplelightningport.gif \
    Advance Wars By Web 2.1_files/redfireairport.gif \
    Advance Wars By Web 2.1_files/redfirebase.gif \
    Advance Wars By Web 2.1_files/redfirecity.gif \
    Advance Wars By Web 2.1_files/redfirecomtower.gif \
    Advance Wars By Web 2.1_files/redfirehq.gif \
    Advance Wars By Web 2.1_files/redfirelab.gif \
    Advance Wars By Web 2.1_files/redfireport.gif \
    Advance Wars By Web 2.1_files/reef.gif \
    Advance Wars By Web 2.1_files/sea.gif \
    Advance Wars By Web 2.1_files/spipeend.gif \
    Advance Wars By Web 2.1_files/swnriver.gif \
    Advance Wars By Web 2.1_files/swnroad.gif \
    Advance Wars By Web 2.1_files/swpipe.gif \
    Advance Wars By Web 2.1_files/swriver.gif \
    Advance Wars By Web 2.1_files/swroad.gif \
    Advance Wars By Web 2.1_files/tealgalaxyairport.gif \
    Advance Wars By Web 2.1_files/tealgalaxybase.gif \
    Advance Wars By Web 2.1_files/tealgalaxycity.gif \
    Advance Wars By Web 2.1_files/tealgalaxycomtower.gif \
    Advance Wars By Web 2.1_files/tealgalaxyhq.gif \
    Advance Wars By Web 2.1_files/tealgalaxylab.gif \
    Advance Wars By Web 2.1_files/tealgalaxyport.gif \
    Advance Wars By Web 2.1_files/vbridge.gif \
    Advance Wars By Web 2.1_files/vpipe.gif \
    Advance Wars By Web 2.1_files/vpiperubble.gif \
    Advance Wars By Web 2.1_files/vpipeseam.gif \
    Advance Wars By Web 2.1_files/vriver.gif \
    Advance Wars By Web 2.1_files/vroad.gif \
    Advance Wars By Web 2.1_files/vshoal.gif \
    Advance Wars By Web 2.1_files/vshoale.gif \
    Advance Wars By Web 2.1_files/whitenovaairport.gif \
    Advance Wars By Web 2.1_files/whitenovabase.gif \
    Advance Wars By Web 2.1_files/whitenovacity.gif \
    Advance Wars By Web 2.1_files/whitenovacomtower.gif \
    Advance Wars By Web 2.1_files/whitenovahq.gif \
    Advance Wars By Web 2.1_files/whitenovalab.gif \
    Advance Wars By Web 2.1_files/whitenovaport.gif \
    Advance Wars By Web 2.1_files/wneriver.gif \
    Advance Wars By Web 2.1_files/wneroad.gif \
    Advance Wars By Web 2.1_files/wnpipe.gif \
    Advance Wars By Web 2.1_files/wnriver.gif \
    Advance Wars By Web 2.1_files/wnroad.gif \
    Advance Wars By Web 2.1_files/wood.gif \
    Advance Wars By Web 2.1_files/wpipeend.gif \
    Advance Wars By Web 2.1_files/yellowcometairport.gif \
    Advance Wars By Web 2.1_files/yellowcometbase.gif \
    Advance Wars By Web 2.1_files/yellowcometcity.gif \
    Advance Wars By Web 2.1_files/yellowcometcomtower.gif \
    Advance Wars By Web 2.1_files/yellowcomethq.gif \
    Advance Wars By Web 2.1_files/yellowcometlab.gif \
    Advance Wars By Web 2.1_files/yellowcometport.gif \
    Advance Wars By Web 2.1_files/line.png \
    Advance Wars By Web 2.1_files/awbw_minify.css \
    Advance Wars By Web 2.1.html \
    Advance Wars By Web 2.1_files/overlib_mini_minify.js.téléchargé \
    Advance Wars By Web 2.1_files/jquery-3.3.1.min.js.téléchargé \
    Advance Wars By Web 2.1_files/acidrainairport.gif \
    Advance Wars By Web 2.1_files/acidrainbase.gif \
    Advance Wars By Web 2.1_files/acidraincity.gif \
    Advance Wars By Web 2.1_files/acidraincomtower.gif \
    Advance Wars By Web 2.1_files/acidrainhq.gif \
    Advance Wars By Web 2.1_files/acidrainlab.gif \
    Advance Wars By Web 2.1_files/acidrainport.gif \
    Advance Wars By Web 2.1_files/amberblazeairport.gif \
    Advance Wars By Web 2.1_files/amberblazebase.gif \
    Advance Wars By Web 2.1_files/amberblazecity.gif \
    Advance Wars By Web 2.1_files/amberblazecomtower.gif \
    Advance Wars By Web 2.1_files/amberblazehq.gif \
    Advance Wars By Web 2.1_files/amberblazelab.gif \
    Advance Wars By Web 2.1_files/amberblazeport.gif \
    Advance Wars By Web 2.1_files/awbwlogo3.gif \
    Advance Wars By Web 2.1_files/blackholeairport.gif \
    Advance Wars By Web 2.1_files/blackholebase.gif \
    Advance Wars By Web 2.1_files/blackholecity.gif \
    Advance Wars By Web 2.1_files/blackholecomtower.gif \
    Advance Wars By Web 2.1_files/blackholehq.gif \
    Advance Wars By Web 2.1_files/blackholelab.gif \
    Advance Wars By Web 2.1_files/blackholeport.gif \
    Advance Wars By Web 2.1_files/bluemoonairport.gif \
    Advance Wars By Web 2.1_files/bluemoonbase.gif \
    Advance Wars By Web 2.1_files/bluemooncity.gif \
    Advance Wars By Web 2.1_files/bluemooncomtower.gif \
    Advance Wars By Web 2.1_files/bluemoonhq.gif \
    Advance Wars By Web 2.1_files/bluemoonlab.gif \
    Advance Wars By Web 2.1_files/bluemoonport.gif \
    Advance Wars By Web 2.1_files/browndesertairport.gif \
    Advance Wars By Web 2.1_files/browndesertbase.gif \
    Advance Wars By Web 2.1_files/browndesertcity.gif \
    Advance Wars By Web 2.1_files/browndesertcomtower.gif \
    Advance Wars By Web 2.1_files/browndeserthq.gif \
    Advance Wars By Web 2.1_files/browndesertlab.gif \
    Advance Wars By Web 2.1_files/browndesertport.gif \
    Advance Wars By Web 2.1_files/cobalticeairport.gif \
    Advance Wars By Web 2.1_files/cobalticebase.gif \
    Advance Wars By Web 2.1_files/cobalticecity.gif \
    Advance Wars By Web 2.1_files/cobalticecomtower.gif \
    Advance Wars By Web 2.1_files/cobalticehq.gif \
    Advance Wars By Web 2.1_files/cobalticelab.gif \
    Advance Wars By Web 2.1_files/cobalticeport.gif \
    Advance Wars By Web 2.1_files/criver.gif \
    Advance Wars By Web 2.1_files/croad.gif \
    Advance Wars By Web 2.1_files/epipeend.gif \
    Advance Wars By Web 2.1_files/espipe.gif \
    Advance Wars By Web 2.1_files/esriver.gif \
    Advance Wars By Web 2.1_files/esroad.gif \
    Advance Wars By Web 2.1_files/eswriver.gif \
    Advance Wars By Web 2.1_files/eswroad.gif \
    Advance Wars By Web 2.1_files/greenearthairport.gif \
    Advance Wars By Web 2.1_files/greenearthbase.gif \
    Advance Wars By Web 2.1_files/greenearthcity.gif \
    Advance Wars By Web 2.1_files/greenearthcomtower.gif \
    Advance Wars By Web 2.1_files/greenearthhq.gif \
    Advance Wars By Web 2.1_files/greenearthlab.gif \
    Advance Wars By Web 2.1_files/greenearthport.gif \
    Advance Wars By Web 2.1_files/greyskyairport.gif \
    Advance Wars By Web 2.1_files/greyskybase.gif \
    Advance Wars By Web 2.1_files/greyskycity.gif \
    Advance Wars By Web 2.1_files/greyskycomtower.gif \
    Advance Wars By Web 2.1_files/greyskyhq.gif \
    Advance Wars By Web 2.1_files/greyskylab.gif \
    Advance Wars By Web 2.1_files/greyskyport.gif \
    Advance Wars By Web 2.1_files/hbridge.gif \
    Advance Wars By Web 2.1_files/hpipe.gif \
    Advance Wars By Web 2.1_files/hpiperubble.gif \
    Advance Wars By Web 2.1_files/hpipeseam.gif \
    Advance Wars By Web 2.1_files/hriver.gif \
    Advance Wars By Web 2.1_files/hroad.gif \
    Advance Wars By Web 2.1_files/hshoal.gif \
    Advance Wars By Web 2.1_files/hshoaln.gif \
    Advance Wars By Web 2.1_files/jadesunairport.gif \
    Advance Wars By Web 2.1_files/jadesunbase.gif \
    Advance Wars By Web 2.1_files/jadesuncity.gif \
    Advance Wars By Web 2.1_files/jadesuncomtower.gif \
    Advance Wars By Web 2.1_files/jadesunhq.gif \
    Advance Wars By Web 2.1_files/jadesunlab.gif \
    Advance Wars By Web 2.1_files/jadesunport.gif \
    Advance Wars By Web 2.1_files/missilesilo.gif \
    Advance Wars By Web 2.1_files/missilesiloempty.gif \
    Advance Wars By Web 2.1_files/mountain.gif \
    Advance Wars By Web 2.1_files/nepipe.gif \
    Advance Wars By Web 2.1_files/neriver.gif \
    Advance Wars By Web 2.1_files/neroad.gif \
    Advance Wars By Web 2.1_files/nesriver.gif \
    Advance Wars By Web 2.1_files/nesroad.gif \
    Advance Wars By Web 2.1_files/neutralairport.gif \
    Advance Wars By Web 2.1_files/neutralbase.gif \
    Advance Wars By Web 2.1_files/neutralcity.gif \
    Advance Wars By Web 2.1_files/neutralcomtower.gif \
    Advance Wars By Web 2.1_files/neutrallab.gif \
    Advance Wars By Web 2.1_files/neutralport.gif \
    Advance Wars By Web 2.1_files/npipeend.gif \
    Advance Wars By Web 2.1_files/orangestarairport.gif \
    Advance Wars By Web 2.1_files/orangestarbase.gif \
    Advance Wars By Web 2.1_files/orangestarcity.gif \
    Advance Wars By Web 2.1_files/orangestarcomtower.gif \
    Advance Wars By Web 2.1_files/orangestarhq.gif \
    Advance Wars By Web 2.1_files/orangestarlab.gif \
    Advance Wars By Web 2.1_files/orangestarport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosairport.gif \
    Advance Wars By Web 2.1_files/pinkcosmosbase.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscity.gif \
    Advance Wars By Web 2.1_files/pinkcosmoscomtower.gif \
    Advance Wars By Web 2.1_files/pinkcosmoshq.gif \
    Advance Wars By Web 2.1_files/pinkcosmoslab.gif \
    Advance Wars By Web 2.1_files/pinkcosmosport.gif \
    Advance Wars By Web 2.1_files/plain.gif \
    Advance Wars By Web 2.1_files/purplelightningairport.gif \
    Advance Wars By Web 2.1_files/purplelightningbase.gif \
    Advance Wars By Web 2.1_files/purplelightningcity.gif \
    Advance Wars By Web 2.1_files/purplelightningcomtower.gif \
    Advance Wars By Web 2.1_files/purplelightninghq.gif \
    Advance Wars By Web 2.1_files/purplelightninglab.gif \
    Advance Wars By Web 2.1_files/purplelightningport.gif \
    Advance Wars By Web 2.1_files/redfireairport.gif \
    Advance Wars By Web 2.1_files/redfirebase.gif \
    Advance Wars By Web 2.1_files/redfirecity.gif \
    Advance Wars By Web 2.1_files/redfirecomtower.gif \
    Advance Wars By Web 2.1_files/redfirehq.gif \
    Advance Wars By Web 2.1_files/redfirelab.gif \
    Advance Wars By Web 2.1_files/redfireport.gif \
    Advance Wars By Web 2.1_files/reef.gif \
    Advance Wars By Web 2.1_files/sea.gif \
    Advance Wars By Web 2.1_files/spipeend.gif \
    Advance Wars By Web 2.1_files/swnriver.gif \
    Advance Wars By Web 2.1_files/swnroad.gif \
    Advance Wars By Web 2.1_files/swpipe.gif \
    Advance Wars By Web 2.1_files/swriver.gif \
    Advance Wars By Web 2.1_files/swroad.gif \
    Advance Wars By Web 2.1_files/tealgalaxyairport.gif \
    Advance Wars By Web 2.1_files/tealgalaxybase.gif \
    Advance Wars By Web 2.1_files/tealgalaxycity.gif \
    Advance Wars By Web 2.1_files/tealgalaxycomtower.gif \
    Advance Wars By Web 2.1_files/tealgalaxyhq.gif \
    Advance Wars By Web 2.1_files/tealgalaxylab.gif \
    Advance Wars By Web 2.1_files/tealgalaxyport.gif \
    Advance Wars By Web 2.1_files/vbridge.gif \
    Advance Wars By Web 2.1_files/vpipe.gif \
    Advance Wars By Web 2.1_files/vpiperubble.gif \
    Advance Wars By Web 2.1_files/vpipeseam.gif \
    Advance Wars By Web 2.1_files/vriver.gif \
    Advance Wars By Web 2.1_files/vroad.gif \
    Advance Wars By Web 2.1_files/vshoal.gif \
    Advance Wars By Web 2.1_files/vshoale.gif \
    Advance Wars By Web 2.1_files/whitenovaairport.gif \
    Advance Wars By Web 2.1_files/whitenovabase.gif \
    Advance Wars By Web 2.1_files/whitenovacity.gif \
    Advance Wars By Web 2.1_files/whitenovacomtower.gif \
    Advance Wars By Web 2.1_files/whitenovahq.gif \
    Advance Wars By Web 2.1_files/whitenovalab.gif \
    Advance Wars By Web 2.1_files/whitenovaport.gif \
    Advance Wars By Web 2.1_files/wneriver.gif \
    Advance Wars By Web 2.1_files/wneroad.gif \
    Advance Wars By Web 2.1_files/wnpipe.gif \
    Advance Wars By Web 2.1_files/wnriver.gif \
    Advance Wars By Web 2.1_files/wnroad.gif \
    Advance Wars By Web 2.1_files/wood.gif \
    Advance Wars By Web 2.1_files/wpipeend.gif \
    Advance Wars By Web 2.1_files/yellowcometairport.gif \
    Advance Wars By Web 2.1_files/yellowcometbase.gif \
    Advance Wars By Web 2.1_files/yellowcometcity.gif \
    Advance Wars By Web 2.1_files/yellowcometcomtower.gif \
    Advance Wars By Web 2.1_files/yellowcomethq.gif \
    Advance Wars By Web 2.1_files/yellowcometlab.gif \
    Advance Wars By Web 2.1_files/yellowcometport.gif \
    Advance Wars By Web 2.1_files/line.png \
    Advance Wars By Web 2.1_files/awbw_minify.css \
    Advance Wars By Web 2.1_files/overlib_mini_minify.js.téléchargé \
    map.txt

RESOURCES += \
    hey.qrc
