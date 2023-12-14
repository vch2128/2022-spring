#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include<iostream>
#include<string>
#include<vector>
#include"Object.h"
#include"Item.h"

using namespace std;

class Chest:public Object
{
private:
    int money;
    int health;
    Item* found;
public:
    Chest(int themoney,int theh,Item* theitem):money(themoney),health(theh),found(theitem){
        setTag("Chest");
        if(money>=15){
            setName("Big Chest");
        }
        else{
            setName("Small Chest");
        }
    }
    bool triggerEvent(Object* obj);   //broken true /not broken false
    bool checkBroken();
    void takeDamage(int att);

    int getHealth(){ return health;}
    int getMoney() {return money;}
    Item* getFound(){return found;}
    void setHealth(int theh){health=theh;}
    void setMoney(int themoney){money=themoney;}
    void setFound(Item* thefound){found=thefound;}
};


#endif // CHEST_H_INCLUDED
