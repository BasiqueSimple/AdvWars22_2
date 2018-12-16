#include "game.h"
#include "mainwindow.h"
#include <QApplication>

#include "./Terrains/plaine.h"
#include "./Terrains/montagne.h"
#include "./Terrains/foret.h"
#include "./Terrains/pipe.h"
#include "./Terrains/plage.h"
#include "./Terrains/pont.h"
#include "./Terrains/reef.h"
#include "./Terrains/riviere.h"
#include "./Terrains/route.h"
#include "./Batiments/batimentsville.h"
#include "./Batiments/batimentsusine.h"
#include "./Batiments/batimentsaeroport.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//Associe la bonne ConsommationMovePoint en fonction du terrain et de la unit
    Plaine element;
    Unit unit1(1,2);

    if (typeid(element) == typeid(Plaine))
    {
        cout << "ca fonctionne !" << endl;
        if (unit1.getMoveType() == "F")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "B")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "T")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "W")
        {
            element.modifierConsommationMovePoint(2);
        }
        else if (unit1.getMoveType() == "A")
        {
            element.modifierConsommationMovePoint(1);
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (typeid(element) == typeid(Montagne))
    {
        if (unit1.getMoveType() == "F")
        {
            element.modifierConsommationMovePoint(2);
        }
        else if (unit1.getMoveType() == "B")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "T")
        {
            element.modifierConsommationMovePoint(0);
            //0 quand on ne peut pas aller dessus
        }
        else if (unit1.getMoveType() == "W")
        {
            element.modifierConsommationMovePoint(0);
        }
        else if (unit1.getMoveType() == "A")
        {
            element.modifierConsommationMovePoint(1);
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (typeid(element) == typeid(Foret))
    {
        if (unit1.getMoveType() == "F")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "B")
        {
            element.modifierConsommationMovePoint(1);
        }
        else if (unit1.getMoveType() == "T")
        {
            element.modifierConsommationMovePoint(2);
        }
        else if (unit1.getMoveType() == "W")
        {
            element.modifierConsommationMovePoint(3);
        }
        else if (unit1.getMoveType() == "A")
        {
            element.modifierConsommationMovePoint(1);
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (typeid(element) == typeid(Riviere))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(2);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Route))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Pont))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Plage))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Reef))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Batimentville))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Batimentusine))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Batimentaeroport))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(1);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(1);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else if (typeid(element) == typeid(Pipe))
    {
       if (unit1.getMoveType() == "F")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "B")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "T")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "W")
       {
           element.modifierConsommationMovePoint(0);
       }
       else if (unit1.getMoveType() == "A")
       {
           element.modifierConsommationMovePoint(0);
       }
       else
       {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
       }
    }
    else
    {
        cout << "Ce terrain est inconnu" << endl;
    }


    return a.exec();
}
