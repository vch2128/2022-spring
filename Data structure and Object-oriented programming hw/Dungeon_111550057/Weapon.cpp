#include<iostream>
#include<string>
#include"Object.h"
#include"Item.h"
#include"Weapon.h"
#include"Player.h"

using namespace std;

void Weapon::showWeapon(){
    cout<<getName()<<": ATT+"<<getAttack()
                   <<" / DEF+"<<getDefense()
                   <<" / Suitable class: "<<fitClass;
}

bool Weapon::triggerEvent(Object* obj){
    Player* plr=dynamic_cast<Player*>(obj);
    char ans;
    cout<<endl<<"You obtained the weapon ";
    showWeapon();
    cout<<"."<<endl;
    cout<<"Your current weapon is ";
    plr->getWeapon().showWeapon();
    cout<<endl;
    if(plr->getName()!=fitClass){
        cout<<endl<<"You cannot equip the new weapon because you don't know how to use it."<<endl;
    }
    else{
    cout<<endl<<"Do you want to discard your current weapon and equip the new one? "<<endl
        <<"a. Yes."<<endl
        <<"b. No."<<endl;
    cin>>ans;
    if(ans=='a'||ans=='A'){
        cout<<endl<<"* You equipped "<<getName()<<" as your weapon. *"<<endl;
        plr->setWeapon(*this);
    }
    else{
        cout<<endl<<"* You discarded the "<<getName()<<". *"<<endl;
    }
    }
    return true;
}
