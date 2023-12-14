#include "NPC.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include<cstdlib>
#include<ctime>


using namespace std;

void NPC::listCommodity(){
    cout<<endl<<"Mysterious person: Here are some things available:"<<endl;
    for(unsigned int i=0;i<commodity.size();i++){
        cout<<i+1<<". ";
        commodity[i]->showItem();
        cout<<" / listed price: $"<<commodity[i]->getValue()<<endl;
    }
}

void NPC::stealThings(Player* plr){
    srand(time(NULL));

    vector<Item> v1;
    v1=plr->getInventory();
    int max=v1.size()-1;
    int x=rand()%(max+1);

    plr->increaseStates(-(v1[x].getHealth()),-(v1[x].getAttack()),-(v1[x].getDefense()));
    commodity.push_back(&v1[x]);
    v1.erase(v1.begin()+x);
    plr->setInventory(v1);
    cout<<"The mysterious person vanished and you suddenly found out something was missing in your bag."<<endl;
}

void NPC::sellThings(Player* plr){
    int ans2;
    char ans1;
    bool repeat=1;
    bool b;
    while(repeat){
    listCommodity();
    cout<<endl<<"Mysterious person: Anything interested?"<<endl
        <<"a. Yes."<<endl
        <<"b. No thanks."<<endl;
    cin>>ans1;
    if(ans1=='a'||ans1=='A'){
        //selling
        cout<<endl<<"Mysterious person: Great! Choose a commodity (please indicate by number): ";
        cin>>ans2;

        if((plr->getMoney())>=(commodity[ans2-1]->getValue())){  //enough money?
        plr->changeMoney(-(commodity[ans2-1]->getValue()));
        if(commodity[ans2-1]->getTag()=="Item"){
            b=commodity[ans2-1]->triggerEvent(plr);

            /*vector<Item> v=plr->getInventory();
            v.push_back(*commodity[ans2-1]);
            plr->setInventory(v);
            plr->increaseStates(commodity[ans2-1]->getHealth(),commodity[ans2-1]->getAttack(),commodity[ans2-1]->getDefense());*/
        }
        else if(commodity[ans2-1]->getTag()=="Weapon"){
            Weapon* weapon=dynamic_cast<Weapon*>(commodity[ans2-1]);
            b=weapon->triggerEvent(plr);
        }
        commodity.erase(commodity.begin()+ans2-1); //thing sold

        //again?
        cout<<endl<<"Mysterious person: Thank you for your purchase. Want anything else? "<<endl
            <<"a. Yes."<<endl
            <<"b. No thanks."<<endl;
        cin>>ans1;
        }

        else{
            cout<<endl<<"Unfortunately, you don't have enough money."<<endl;
            cout<<endl<<"Mysterious person: That's a shame. Do you want anything else? "<<endl
                <<"a. Yes."<<endl
                <<"b. No thanks."<<endl;
            cin>>ans1;
        }


        if(ans1=='b'||ans1=='B'){
            cout<<endl<<"Mysterious person: That's fine. Come back when you need anything."<<endl;
            repeat=0;
        }
    }
    else{
        cout<<endl<<"Mysterious person: That's fine. Come back when you need anything."<<endl;
        repeat=0;
    }
    }
}

void NPC::buyThings(Player* plr){
    bool repeat=1;
    vector<Item> v;
    int ans1;
    char ans2;
    while(repeat){
        v=plr->getInventory();
        if(v.size()==0){
            cout<<endl<<"Unfortunately, you have nothing to sell."<<endl;
            repeat=0;
        }
        else{
        cout<<endl<<"Items in your bag: "<<endl;
        for(unsigned int i=0;i<v.size();i++){
            cout<<i+1<<". ";
            v[i].showItem();
            cout<<" : listed price: $"<<v[i].getValue()-pricedown<<endl;
        }
        cout<<endl<<"Mysterious person: Do you want to sell anything? "<<endl
            <<"a. Yes."<<endl
            <<"b. No thanks."<<endl;
        cin>>ans2;
        if(ans2=='a'||ans2=='A'){
            //buying
            cout<<endl<<"Choose an item in your bag for sell (please indicate by number): ";
            cin>>ans1;
            plr->increaseStates(-(v[ans1-1].getHealth()),-(v[ans1-1].getAttack()),-(v[ans1-1].getDefense()));
            plr->changeMoney(v[ans1-1].getValue()-pricedown);
            commodity.push_back(&v[ans1-1]);
            v.erase(v.begin()+ans1-1);
            plr->setInventory(v);

            //again?
            cout<<endl<<"Mysterious person: Thank you. Anything else for sale?"<<endl
            <<"a. Yes."<<endl
            <<"b. No thanks."<<endl;
            cin>>ans2;
            if(ans2=='b'||ans2=='B'){
                cout<<endl<<"Mysterious person: Alright. Hope to see you soon."<<endl;
                repeat=0;
            }
        }
        else{
            cout<<endl<<"Mysterious person: Alright. Hope to see you soon."<<endl;
            repeat=0;
        }
        }
    }
}

void NPC::helpTheGirl(Player* plr){
    vector<Item> v;
    int ans;
    v=plr->getInventory();
    if(v.size()==0){
        cout<<endl<<"Unfortunately, you have nothing in your bag."<<endl
            <<"Little girl: Thanks anyway."<<endl;
    }
    else{
    cout<<endl<<"Items in your bag: "<<endl;
    for(unsigned int i=0;i<v.size();i++){
        cout<<i+1<<". ";
        v[i].showItem();
        cout<<endl;
    }
    cout<<endl<<"Which one do you want to give to the little girl? (Please indicate by number. Insert 0 if you changed your mind.): ";
    cin>>ans;
    if(ans==0){
        cout<<endl<<"Little girl: Fine...Thanks anyway..."<<endl;
    }
    else{
        ans-=1;
        cout<<endl<<"Little girl: Thank you so much for your "<<v[ans].getName()<<"! This box of matches is for you. Have a great day!"<<endl;
        plr->increaseStates(-(v[ans].getHealth()),-(v[ans].getAttack()),-(v[ans].getDefense()));
        v.erase(v.begin()+ans);
        v.push_back(Item("Matches",0,0,0,0,0));
        plr->setInventory(v);
        plr->setMatches(true);
    }
    }
}

bool NPC::triggerEvent(Object* obj){
    Player* plr=dynamic_cast<Player*>(obj);
    cout<<endl<<script<<endl;
    cout<<endl<<"* You checked your bag. You have $"<<plr->getMoney()<<" and "<<plr->getInventory().size()<<" item(s) now. *"<<endl;
    char ans;
    if(getName()=="Merchant"||getName()=="Thief"){
        cout<<"a. Yes! I'd love to sell some stuff."<<endl
            <<"b. Of course. I want to buy some stuff."<<endl
            <<"c. No thanks. Maybe next time. "<<endl;
        cin>>ans;
        if(ans=='a'||ans=='A'){
            buyThings(plr);
        }
        else if(ans=='b'||ans=='B'){
            sellThings(plr);
        }
        else{
            cout<<endl<<"Mysterious person: Sure. Good luck."<<endl;
        }
        if(getName()=="Thief"&&plr->getInventory().size()!=0){
            stealThings(plr);
            return true;
        }
    }
    else {
        cout<<"a. Yes. I will help you."<<endl
            <<"b. No. I'm sorry."<<endl;
        cin>>ans;
        if(ans=='a'||ans=='A'){
            helpTheGirl(plr);
        }
        else{
            cout<<endl<<"Little Girl: Fine..."<<endl;
        }
    }
    return false;
}
