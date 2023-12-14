#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
    string script;
    int value;
public:
    Monster(int monstertype,bool bossindicator):GameCharacter(monstertype,bossindicator){
        if(bossindicator==false){
           if(monstertype==1){
                script="...";
                value=5;
            }
            else if(monstertype==2){
                script="*squeaks*";
                value=8;
            }
            else if(monstertype==3){
                script="...";
                value=12;
            }
            else if(monstertype==4){
                script="*hiss*";
                value=16;
            }
        }
        else if(bossindicator==true){
            if(monstertype==1){
                script="Roarrrr!!";
                value=100;
            }
            else{
                script="The blood is the life.";
                value=120;
            }
        }
    }
    void playerAttackMonster(Player* plr);
    void fightMonster(int sk,Player* plr);
    int playerChooseSkill(Player* plr);
    void monsterFightBack(Player* plr);
    void fightBoss(bool rage,int sk,Player* plr);
    bool bossInRage();
    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);  //monster die true/ not dead false

    int getValue(){return value;}
};



#endif // ENEMY_H_INCLUDED
