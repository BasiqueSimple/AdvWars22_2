#include "game.h"
#include "mainwindow.h"
#include <QApplication>

#include "damage.h"


damage::damage()
{

}

int damage::calculerdamage(Unit attaquant, Unit attaque)
{
    int damage = 0;
    if (typeid(attaquant) == typeid(Unitterrenoinfantantiair))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 45 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 120 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 75 ;
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 10 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 1;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 5 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 60 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 25 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitairbcopter))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 25 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 75 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 25 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 75 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 10;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 20;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 55 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 55 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitairbomber))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 95 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 110 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 95 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 110 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 35;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 90;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 105 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitairfighter))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 100 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 100 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 55 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 0;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 0;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 0 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterreinfantinfant))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 5 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 7 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 55 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 1 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 45 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 1;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 1;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 12 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 5 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterrenoinfantmdtank))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 12 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 55;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 95 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 25;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 45;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 105 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 85;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterreinfantbazooka))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 9 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 15 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 55 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 5;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 15;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 85 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 55 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterrenoinfantmegatank))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 195 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 22;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 135 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 125;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 125;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 65;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 115;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 195;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 180;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterrenoinfantneotank))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 115 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 22 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 125 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 75;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 115 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 35;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 55;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 125;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 105;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterrenoinfantrecon))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 4 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 12 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 70 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 1 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 1;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 1;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 35 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 6 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else if (typeid(attaquant) == typeid(Unitterrenoinfanttank))
    {
        if (typeid(attaque) == typeid(Unitterrenoinfantantiair))
        {
            damage = 65 ;
        }
        else if (typeid(attaque) == typeid(Unitairbcopter))
        {
            damage = 10 ;
        }
        else if (typeid(attaque) == typeid(Unitairbomber))
        {
            damage = 0 ;
            //0 quand n'a pas le droit de n'attaquer
        }
        else if (typeid(attaque) == typeid(Unitairfighter))
        {
            damage = 0 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantinfant))
        {
            damage = 75 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmdtank))
        {
            damage = 15 ;
        }
        else if (typeid(attaque) == typeid(Unitterreinfantbazooka))
        {
            damage = 70 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantmegatank))
        {
            damage = 10;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantneotank))
        {
            damage = 15;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfantrecon))
        {
            damage = 85 ;
        }
        else if (typeid(attaque) == typeid(Unitterrenoinfanttank))
        {
            damage = 55 ;
        }
        else
        {
            cout << "Le type de unit que vous attaquez est inconnu" << endl;
        }
    }
    else
    {
        cout << "Le type de unit avec lequel vous attaquez est inconnu" << endl;
    }
    return damage;
}

int damage::calculerpointdefense(Unit attaque, Terrain terrain)
{
    int PointDefense =0;
    if (typeid(attaque)==typeid(Unitair))
    {
        PointDefense=0;
    }
    else
    {
        PointDefense=terrain.getPointDefense();
    }
    return PointDefense;
}

