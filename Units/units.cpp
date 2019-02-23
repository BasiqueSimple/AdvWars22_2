#include "units.h"
#include <onmap.h>
#include <string>
#include "Unitterreinfant/unitterreinfantinfant.h"



Unit::Unit(int x, int y) : Activable (x, y)
{
}

void Unit::mouvementspossibles(Terrain terrain)
{
    int movepointrestant = this->MovePoint;

    //Associe la bonne ConsommationMovePoint en fonction du terrain et de la unit

    int ConsommationMovePoint;
    if (typeid(terrain) == typeid(Plaine))
    {
        cout << "ca fonctionne !" << endl;
        if (this->getMoveType() == "F")
        {
           ConsommationMovePoint = 1;
        }
        else if (this->getMoveType() == "B")
        {
           ConsommationMovePoint = 1;
        }
        else if (this->getMoveType() == "T")
        {
           ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
           ConsommationMovePoint = 2 ;
        }
        else if (this->getMoveType() == "A")
        {
           ConsommationMovePoint = 1 ;
        }
        else
        {
           cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (typeid(terrain) == typeid(Montagne))
    {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 2 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 0;
            //0 quand on ne peut pas aller dessus
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Foret))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 2 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 3 ;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
    }
    else if (typeid(terrain) == typeid(Riviere))
    {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 2 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Route))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
             ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Pont))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Plage))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Reef))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Batimentville))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
           ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
           ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
           ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Batimentusine))
     {
        if (this->getMoveType() == "F")
        {
           ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Batimentaeroport))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 1 ;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 1 ;
        }
        else
        {
            cout << "Votre unit possède un type de mouvement inconnu" << endl;
        }
     }
    else if (typeid(terrain) == typeid(Pipe))
     {
        if (this->getMoveType() == "F")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "B")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "T")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "W")
        {
            ConsommationMovePoint = 0;
        }
        else if (this->getMoveType() == "A")
        {
            ConsommationMovePoint = 0;
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

    movepointrestant -= ConsommationMovePoint;
    //faire bouger la unit
    // renvoyer movepointrestant pour faire une boucle ailleurs ?
}

void Unit::attendre()
{
    //passer un tour
}

int Unit::getPV()
{
    return this->PV;
}

void Unit::recevoirdegat(int a)
{
    this->PV = --a;
}

void Unit::etrerepare(Terrain, Joueur)
{

}

void Unit::fusion(Unit celuiquejerejoins)
{
    if (typeid (this) == typeid (celuiquejerejoins))
    {
        if ((celuiquejerejoins.PV)==10)
        {
            cout << "Tu ne peux pas fusionner avec moi j'ai encore tous mes points de vie" <<endl;
        }
        else
        {
            // int a = this->PV + celuiquejerejoins.PV;
            //if (a > 10)
            //{
            //  a = 10;
            //}
            //creer un unit du même type dont PV = a
            //detruire this
            //detruire celuiquejerejoins
        }
    }
}

bool Unit::EtreEnVie()
{
    return this->PV > 0;
}

string Unit::getMoveType()
{
    return this->MoveType;
}

void Unit::activate(vector<Terrain*> terrains)
{
    cout<<"hey"<<endl;
    vector<tuple<int,int>> cases_acces = this->where(this->getposx(), this->getposy(), Unitterreinfantinfant::MovePoint,terrains);
    for(int i = 0; i<cases_acces.size(); ++i){
        cout << get<0>(cases_acces[i]) << "," << get<1>(cases_acces[i]) << endl;
    }
}

int Unit::getMP(){
    return this->MovePoint;
}

vector<tuple<int,int>> Unit::where(int posx, int posy, int MP, vector<Terrain*> terrains){
    vector<tuple<int,int>> * cases_acces = new vector<tuple<int,int>>;

    //Vers le nord
    cout<<"north"<<endl;
    int nextx = posx;
    int nexty = posy-1;
    for(int i=0;i<terrains.size();++i){
        if(terrains[i]->isAt(nextx,nexty)){
            cout<<MP<<endl;
            if(terrains[i]->getMP()!=0 && terrains[i]->getMP()<MP){
                cases_acces->push_back(make_tuple(nextx,nexty));
                vector<tuple<int,int>> newcases = this->where(nextx,nexty,MP-terrains[i]->getMP(),terrains);
                vector<tuple<int,int>> res;
                res.reserve(cases_acces->size() + newcases.size());
                res.insert(res.end(),newcases.begin(),newcases.end());
                res.insert(res.end(),cases_acces->begin(),cases_acces->end());
            }
        }
    }

    //Vers le sud
    cout<<"south"<<endl;
    nextx = posx;
    nexty = posy+1;
    for(int i=0;i<terrains.size();++i){
        if(terrains[i]->isAt(nextx,nexty)){
            cout<<MP<<endl;
            if(terrains[i]->getMP()!=0 && terrains[i]->getMP()<MP){
                cases_acces->push_back(make_tuple(nextx,nexty));
                vector<tuple<int,int>> newcases = this->where(nextx,nexty,MP-terrains[i]->getMP(),terrains);
                vector<tuple<int,int>> res;
                res.reserve(cases_acces->size() + newcases.size());
                res.insert(res.end(),newcases.begin(),newcases.end());
                res.insert(res.end(),cases_acces->begin(),cases_acces->end());
            }
        }
    }

    //Vers l'ouest
    cout<<"west"<<endl;
    nextx = posx-1;
    nexty = posy;
    for(int i=0;i<terrains.size();++i){
        if(terrains[i]->isAt(nextx,nexty)){
            cout<<MP<<endl;
            if(terrains[i]->getMP()!=0 && terrains[i]->getMP()<MP){
                cases_acces->push_back(make_tuple(nextx,nexty));
                vector<tuple<int,int>> newcases = this->where(nextx,nexty,MP-terrains[i]->getMP(),terrains);
                vector<tuple<int,int>> res;
                res.reserve(cases_acces->size() + newcases.size());
                res.insert(res.end(),newcases.begin(),newcases.end());
                res.insert(res.end(),cases_acces->begin(),cases_acces->end());
            }
        }
    }

    //Vers l'est
    cout<<"east"<<endl;
    nextx = posx+1;
    nexty = posy;
    for(int i=0;i<terrains.size();++i){
        if(terrains[i]->isAt(nextx,nexty)){
            cout<<MP<<endl;
            if(terrains[i]->getMP()!=0 && terrains[i]->getMP()<MP){
                cases_acces->push_back(make_tuple(nextx,nexty));
                vector<tuple<int,int>> newcases = this->where(nextx,nexty,MP-terrains[i]->getMP(),terrains);
                vector<tuple<int,int>> res;
                res.reserve(cases_acces->size() + newcases.size());
                res.insert(res.end(),newcases.begin(),newcases.end());
                res.insert(res.end(),cases_acces->begin(),cases_acces->end());
            }
        }
    }

    return *cases_acces;

}

void Unit::setImg(QPixmap img){
    this->img=img;
}

QPixmap Unit::getimg(){
    return this->img;
}

Unit::~Unit()
{

}
