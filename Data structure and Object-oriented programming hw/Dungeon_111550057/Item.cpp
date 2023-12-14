#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"

using namespace std;

bool Item::triggerEvent(Object* obj){
    Player* plr=dynamic_cast<Player*>(obj);
    char ans;
    cout<<endl<<"You obtained the "<<getName()<<"."<<endl;
    showItem();
    cout<<endl<<endl<<"Do you want to put it in your backpack? "<<endl
        <<"a. Yes."<<endl
        <<"b. No."<<endl;
    cin>>ans;
    if(ans=='a'||ans=='A'){
        cout<<endl<<"You put the "<<getName()<<" in your backpack."<<endl;
        plr->addItem(*this);
        plr->increaseStates(health,attack,defense);
    }
    else{
        cout<<endl<<"You discarded a "<<getName()<<"."<<endl;
    }
    return true;
}

void Item::showItem(){
    cout<<getName()<<"("<<getTag()<<") :"
        <<" HP+"<<getHealth()
        <<" / ATT+"<<getAttack()
        <<" / DEF+"<<getDefense();
}
