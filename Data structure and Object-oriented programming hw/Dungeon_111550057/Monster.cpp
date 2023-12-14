#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Monster.h"
#include "Skill.h"

using namespace std;

int Monster::playerChooseSkill(Player* plr){
    char ans;
    int mode=1;
    cout<<endl<<"Choose which attack you want to use:"<<endl
        <<"a. Normal attack."<<endl;
    if(plr->checkSkillCD(1)==true){
        cout<<"b. "<<plr->getSkill1().getName()<<"."<<endl;
        mode=2;
        if(plr->checkSkillCD(2)==true){
            cout<<"c. "<<plr->getSkill2().getName()<<"."<<endl;
            mode=3;
        }
    }
    else{
        if(plr->checkSkillCD(2)==true){
            cout<<"b. "<<plr->getSkill2().getName()<<"."<<endl;
            mode=4;
        }
    }
    cin>>ans;
    switch(mode){
        case 1:
            if(ans=='a'||ans=='A'){
                return 1;
            }
            else{
                cout<<"Unavailable";
                return -1;
            }
        case 2:
            if(ans=='a'||ans=='A'){
                return 1;
            }
            else if(ans=='b'||ans=='B'){
                return 2;
            }
            else{
                cout<<"Unavailable";
                return 0;
            }
        case 3:
            if(ans=='a'||ans=='A'){
                return 1;
            }
            else if(ans=='b'||ans=='B'){
                return 2;
            }
            else if(ans=='C'||ans=='c'){
                return 3;
            }
            else{
                cout<<"Unavailable";
                return -1;
            }
        case 4:
            if(ans=='a'||ans=='A'){
                return 1;
            }
            else if(ans=='b'||ans=='B'){
                return 3;
            }
            else{
                cout<<"Unavailable";
                return -1;
            }
    }
    return -1;
}

void Monster::playerAttackMonster(Player* plr){
    takeDamage(plr->getAttack()-getDefense());
    cout<<endl<<"You harm the "<<getName()<<" by "<<plr->getAttack()-getDefense()<<" points."<<endl;
}

void Monster::monsterFightBack(Player* plr){
    plr->takeDamage(getAttack()-plr->getDefense());
    cout<<"You got harmed by the "<<getName()<<" by "<<getAttack()-plr->getDefense()<<" points."<<endl;
}

void Monster::fightMonster(int sk,Player* plr){
    //cout<<endl<<"plr cur1:"<<plr->getCurrentHealth()<<endl;
    if(sk==2||sk==3){
                //cout<<endl<<"use"<<endl;
                plr->useSkill(sk-1);
    }
    //cout<<endl<<"plr cur2:"<<plr->getCurrentHealth()<<endl;
    playerAttackMonster(plr);
    if(checkIsDead()==false){
        monsterFightBack(plr);
    }
    if(sk==2||sk==3){
        //if(plr->checkSkillCD(sk-1)){
            //cout<<endl<<"after"<<endl;
            plr->afterSkill(sk-1);
        //}
    }

    plr->skillCoolDown(1);
    plr->skillCoolDown(2);
}

bool Monster::bossInRage(){
    return(getCurrentHealth()<=100);
}

void Monster::fightBoss(bool rage,int sk,Player* plr){
    if(rage==true){
        cout<<endl<<"The boss is in rage!"<<endl;
        useSkill(1);
    }
    if(sk==2||sk==3){
        plr->useSkill(sk-1);
    }
    playerAttackMonster(plr);
    if(checkIsDead()==false){
        monsterFightBack(plr);
    }
    if(rage==true){
        plr->afterSkill(1);
    }
    if(sk==2||sk==3){
        plr->afterSkill(sk-1);
    }
    plr->skillCoolDown(1);
    plr->skillCoolDown(2);
}

bool Monster::triggerEvent(Object* obj){
    Player* plr=dynamic_cast<Player*>(obj);
    char ans;
    cout<<endl<<"You encountered the "<<getName()<<". You want to:"<<endl
        <<"a. Fight."<<endl
        <<"b. Retreat."<<endl
        <<"c. Try to sneak through."<<endl;
    cin>>ans;
    if(getTag()=="Monster"){
        if(ans=='a'||ans=='A'){
            cout<<endl<<"Fight!"<<endl;
            cout<<getName()<<": "<<script<<endl;
            while(checkIsDead()==false&&plr->checkIsDead()==false){
                fightMonster(playerChooseSkill(plr),plr);
                cout<<endl<<"Your current health: "<<plr->getCurrentHealth()<<endl
                    <<getName()<<"'s current health: "<<getCurrentHealth()<<endl;
                if(!checkIsDead()){
                cout<<endl<<"Keep fighting?"<<endl
                    <<"a. Yes."<<endl
                    <<"b. No. I want to retreat."<<endl;
                cin>>ans;
                if(ans=='b'||ans=='B'){
                    break;
                }
                }
            }
            if(checkIsDead()==true){
                cout<<"Congratulations! You defeated the monster. You got $"<<getValue()<<"."<<endl;
                plr->changeMoney(getValue());
                plr->resetSkillCD(1);
                plr->resetSkillCD(2);
                return true;
            }
            else if(plr->checkIsDead()==true){
                cout<<endl<<"You are dead."<<endl;
            }
        }
        if(ans=='b'||ans=='B'){
            plr->changeRoom(plr->getPreviousRoom());
        }
        else if(ans=='c'||ans=='C'){
            cout<<endl<<"You passed without alerting the "<<getName()<<". "<<endl;
        }
    }
    else if(getTag()=="Boss"){
        if(ans=='a'||ans=='A'||ans=='c'||ans=='C'){
            if(ans=='c'||ans=='C'){
                cout<<endl<<"You tried your best to sneak through. However, the "<<getName()<<" still noticed you."<<endl;
            }
            cout<<endl<<"Fight!"<<endl;
            cout<<getName()<<": "<<script<<endl;
            while(checkIsDead()==false&&plr->checkIsDead()==false){
                fightBoss(bossInRage(),playerChooseSkill(plr),plr);
                cout<<endl<<"Your current health: "<<plr->getCurrentHealth()<<endl
                    <<getName()<<"'s current health: "<<getCurrentHealth()<<endl;
                if(!checkIsDead()&&!plr->checkIsDead()){
                cout<<endl<<"Keep fighting?"<<endl
                    <<"a. Yes."<<endl
                    <<"b. No. I want to retreat."<<endl;
                cin>>ans;
                if(ans=='b'||ans=='B'){
                    break;
                }
                }
            }
            if(checkIsDead()==true){
                cout<<endl<<"Congratulations! You defeated the boss. You got $"<<getValue()<<"."<<endl;
                plr->changeMoney(getValue());
                plr->resetSkillCD(1);
                plr->resetSkillCD(2);
                return true;
            }
            else if(plr->checkIsDead()==true){
                cout<<endl<<"You are dead."<<endl;
            }
        }
        if(ans=='b'||ans=='B'){
            plr->changeRoom(plr->getPreviousRoom());
        }
    }
    return false;
}
