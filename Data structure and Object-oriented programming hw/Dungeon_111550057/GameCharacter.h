#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
#include "Skill.h"
using namespace std;

class Skill;

class GameCharacter: public Object
{
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
    Skill sk1,sk2;
public:
    GameCharacter(){}
    GameCharacter(char classtype);  //player
    GameCharacter(int npctype); //npc
    GameCharacter(int monstertype,bool bossindicator);  //monster
    bool checkIsDead();
    void takeDamage(int damage);
    void getHealed(int heal);
    bool checkSkillCD(int skillnum);
    void useSkill(int sk);
    void afterSkill(int sk);
    void skillCoolDown(int sk);
    void resetSkillCD(int sk);

    bool triggerEvent(Object* obj){return true;};

    /* Set & Get function*/
    void setMaxHealth(int themax);
    void setCurrentHealth(int thecur);
    void setAttack(int theatt);
    void setDefense(int thedef);
    int getMaxHealth()   {return maxHealth;}
    int getCurrentHealth()   {return currentHealth;}
    int getAttack()   {return attack;}
    int getDefense()   {return defense;}
    Skill getSkill1()  {return sk1;}
    Skill getSkill2()  {return sk2;}
};
#endif // GAMECHARACTER_H_INCLUDED
