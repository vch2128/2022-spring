#include<iostream>
#include<string>
#include"Item.h"
#include "Object.h"
#include "GameCharacter.h"
#include "Skill.h"

using namespace std;

GameCharacter::GameCharacter(char classtype){
    //a soldier/b assassin/c sorcerer/d archer/e priest
    setTag("Player");
    if(classtype=='a'||classtype=='A'){
        setName("Soldier");
        maxHealth=currentHealth=100;
        attack=28;
        defense=8;
        sk1=Skill("Running Attack",0,10,10);
        sk2=Skill("Mighty Swing",0,15,7);
    }
    else if(classtype=='b'||classtype=='B'){
        setName("Assassin");
        maxHealth=currentHealth=80;
        attack=35;
        defense=4;
        sk1=Skill("Sneak Attack",0,23,-3);
        sk2=Skill("Quiet Death",0,27,-5);
    }
    else if(classtype=='c'||classtype=='C'){
        setName("Sorcerer");
        maxHealth=currentHealth=80;
        attack=38;
        defense=3;
        sk1=Skill("Frost Bolt",0,20,0);
        sk2=Skill("Chain Lightning",1,21,0);
    }
    else if(classtype=='d'||classtype=='D'){
        setName("Archer");
        maxHealth=currentHealth=90;
        attack=31;
        defense=6;
        sk1=Skill("Quick Shot",0,14,6);
        sk2=Skill("Blazing Arrow",0,17,5);
    }
    else if(classtype=='e'||classtype=='E'){
        setName("Priest");
        maxHealth=currentHealth=100;
        attack=25;
        defense=3;
        sk1=Skill("Magic Barrier",10,2,13);
        sk2=Skill("Holy Aura",25,0,5);
    }
    else{
        cout<<"Unavailable"<<endl;
    }
}

GameCharacter::GameCharacter(int npctype){
    setTag("NPC");
    if(npctype==1){
        setName("Merchant");
        maxHealth=currentHealth=50;
        attack=5;
        defense=2;
    }
    else if(npctype==2){
        setName("Thief");
        maxHealth=currentHealth=60;
        attack=10;
        defense=8;
    }
    else if(npctype==3){
        setName("Little girl");
        maxHealth=currentHealth=20;
        attack=1;
        defense=0;
    }
}

GameCharacter::GameCharacter(int monstertype,bool bossindicator){
    if(bossindicator==false){
        setTag("Monster");
    if(monstertype==1){
        setName("Slime");
        maxHealth=currentHealth=30;
        attack=8;
        defense=0;
    }
    else if(monstertype==2){
        setName("Rat");
        maxHealth=currentHealth=40;
        attack=14;
        defense=1;
    }
    else if(monstertype==3){
        setName("Skeleton");
        maxHealth=currentHealth=45;
        attack=15;
        defense=2;
    }
    else if(monstertype==4){
        setName("Cobra");
        maxHealth=currentHealth=45;
        attack=17;
        defense=3;
    }
    }

    else{
    setTag("Boss");
    if(monstertype==1){
        setName("Hydra");
        maxHealth=currentHealth=500;
        attack=30;
        defense=10;
        sk1=Skill("Poison trap",0,20,0);
    }
    else if(monstertype==2){
        setName("Dracula");
        maxHealth=currentHealth=500;
        attack=32;
        defense=13;
        sk1=Skill("Bat Swarm",0,15,10);
    }
    }

}

bool GameCharacter::checkIsDead(){
    return(currentHealth<=0);
}

void GameCharacter::takeDamage(int damage){
    if(damage<0){
        damage=0;
    }
    //cout<<endl<<"dam"<<damage<<endl;
    currentHealth-=damage;
}

void GameCharacter::getHealed(int heal){
    currentHealth+=heal;
    if(currentHealth>maxHealth){
        currentHealth=maxHealth;
    }
}

void GameCharacter::setMaxHealth(int themax){
    maxHealth=themax;
}

void GameCharacter::setCurrentHealth(int thecur){
    currentHealth=thecur;
}

void GameCharacter::setAttack(int theatt){
    attack=theatt;
}

void GameCharacter::setDefense(int thedef){
    defense=thedef;
}

bool GameCharacter::checkSkillCD(int skillnum){
    if(skillnum==1){
        return(sk1.getCD()<=0);
    }
    else{
        return(sk2.getCD()<=0);
    }
}

void GameCharacter::useSkill(int sk){
    Skill* skill;
    if(sk==1){
        skill=&sk1;
    }
    else{
        skill=&sk2;
    }
    setCurrentHealth(getCurrentHealth()+ skill->getHealth());
    setAttack(getAttack()+skill->getAttack());
    setDefense(getDefense()+skill->getDefense());
}

void GameCharacter::afterSkill(int sk){
    Skill* skill;
    if(sk==1){
        skill=&sk1;
        skill->setCD(4);
    }
    else{
        skill=&sk2;
        skill->setCD(5);
    }
    setCurrentHealth(getCurrentHealth()- skill->getHealth());
    setAttack(getAttack()-skill->getAttack());
    setDefense(getDefense()-skill->getDefense());
}

void GameCharacter::skillCoolDown(int sk){
    Skill* skill;
    if(sk==1){
        skill=&sk1;
    }
    else{
        skill=&sk2;
    }
    skill->coolDown();
}

void GameCharacter::resetSkillCD(int sk){
    Skill* skill;
    if(sk==1){
        skill=&sk1;
    }
    else{
        skill=&sk2;
    }
    skill->setCD(0);
}
