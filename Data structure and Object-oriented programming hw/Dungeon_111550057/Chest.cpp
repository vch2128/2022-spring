#include<iostream>
#include<vector>
#include<string>
#include"Object.h"
#include"Chest.h"
#include"Player.h"

using namespace std;

bool Chest::checkBroken(){
    return (getHealth()<=0);
}

void Chest::takeDamage(int att){
    health-=att;
}

bool Chest::triggerEvent(Object* obj)
{
    Player* plr=dynamic_cast<Player*>(obj);
    char ans,ans2;
    cout<<endl<<"You found a "<<getName()<<". Do you want to break it?"<<endl
        <<"a. Yes. Attack the chest."<<endl
        <<"b. No."<<endl;
    cin>>ans;
    while(checkBroken()==false&&(ans=='a'||ans=='A')){
        takeDamage(plr->getAttack());
        if(checkBroken()==false){
            cout<<endl<<"The chest is not broken yet. Attack again?"<<endl
                <<"a. Yes. Attack the chest again."<<endl
                <<"b. No."<<endl;
            cin>>ans;
        }
        else{
            cout<<endl<<"Congratulations! You broke the chest. You found $"<<getMoney()<<" in the chest."<<endl;
            plr->changeMoney(getMoney());
            cout<<endl<<"There is something under the pile of coins.";
            found->triggerEvent(plr);
            return true;
        }
    }
    return false;
}

