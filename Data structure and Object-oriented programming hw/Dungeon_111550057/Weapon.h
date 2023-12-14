#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

#include<iostream>
#include<string>
#include"Object.h"
#include"Item.h"

using namespace std;

class Weapon:public Item
{
private:
    string fitClass;
public:
    Weapon(){}
    Weapon(string thename,string theclass,int theatt,int thedef,int thevalue):Item(thename,true,theatt,thedef,thevalue),fitClass(theclass){}
    void showWeapon();
    bool triggerEvent(Object* obj);

    string getFitClass() {return fitClass;}
    void setFitClass(string s){fitClass=s;}
};

#endif // WEAPON_H_INCLUDED
