#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;


class Item: public Object
{
private:
    int health,attack,defense;
    int value;
    bool weapon;
public:
    Item(){
        health=attack=defense=value=0;
    }
    Item(string thename,bool weapon, int theh, int theatt, int thedef,int thevalue)
                :Object(thename,"Item"),weapon(0),health(theh),attack(theatt),defense(thedef),value(thevalue){}
    Item(string thename,bool weapon,int theatt,int thedef,int thevalue)
                :Object(thename,"Weapon"),weapon(1),health(0),attack(theatt),defense(thedef),value(thevalue){}

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object* obj);   //put it in bag
    void showItem();

    /* Set & Get function*/
    int getHealth(){return health;}
    int getAttack(){return attack;}
    int getDefense(){return defense;}
    int getValue(){return value;}
    void setHealth(int theh){health=theh;}
    void setAttack(int theatt){attack=theatt;}
    void setDefense(int thedef){defense=thedef;}
    void setValue(int thevalue){value=thevalue;}
};




#endif // ITEM_H_INCLUDED
