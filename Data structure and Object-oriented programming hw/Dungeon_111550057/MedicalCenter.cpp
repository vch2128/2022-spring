#include<iostream>
#include<string>
#include "Object.h"
#include "MedicalCenter.h"
#include "Player.h"

using namespace std;

bool MedicalCenter::triggerEvent(Object* obj){
    Player* plr=dynamic_cast<Player*>(obj);
    char ans,ans2;
    ans2='a';
    cout<<endl<<"Welcome to the Medical Center."<<endl;
    while(ans2!='b'&&ans!='B'){
    cout<<endl<<"What kind of healing service do you want?"<<endl
        <<"WARNING: Your current HP cannot exceed your max HP."<<endl
        <<"Your current HP: "<<plr->getCurrentHealth()<<" / "<<plr->getMaxHealth()<<endl
        <<"a. HP+10   price: $12."<<endl  //$1.2
        <<"b. HP+15   price: $16."<<endl
        <<"c. HP+20   price: $20."<<endl
        <<"d. I don't want any service."<<endl;
    cin>>ans;
    while(ans!='a'&&ans!='A'&&ans!='b'&&ans!='B'&&ans!='c'&&ans!='C'&&ans!='d'&&ans!='D'){
        cout<<endl<<"Unavailable. Please choose again. "<<endl;
        cin>>ans;
    }

    if((ans=='a'||ans=='A')&&plr->getMoney()>=12){
        plr->getHealed(10);
        plr->changeMoney(-12);
        cout<<endl<<"Service done. Your current health is: "<<plr->getCurrentHealth()<<" / "<<plr->getMaxHealth()<<endl;
    }
    else if((ans=='b'||ans=='B')&&plr->getMoney()>=16){
        plr->getHealed(15);
        plr->changeMoney(-16);
        cout<<endl<<"Service done. Your current health is: "<<plr->getCurrentHealth()<<" / "<<plr->getMaxHealth()<<endl;
    }
    else if((ans=='c'||ans=='C')&&plr->getMoney()>=20){
        plr->getHealed(20);
        plr->changeMoney(-20);
        cout<<endl<<"Service done. Your current health is: "<<plr->getCurrentHealth()<<" / "<<plr->getMaxHealth()<<endl;
    }
    else if(ans=='d'||ans=='D'){
        ans2='b';
    }
    else{
        cout<<endl<<"Unfortunately, your money is not enough."<<endl;
    }

    if(ans!='d'||ans!='D'){
        cout<<endl<<"Any other service?"<<endl
            <<"a. Yes."<<endl
            <<"b. No."<<endl;
        cin>>ans2;
    }

    if(ans2=='b'||ans2=='B'){
        cout<<endl<<"You left the Medical Center."<<endl;
    }
    }
    return false;
}
