#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include<iostream>
#include<string>


using namespace std;

class GameCharacter;

class Skill
{
private:
    string name;
    string tag;
    int cd,health,attack,defense;
public:
    Skill():name(" "),tag("Skill"),cd(0),health(0),attack(0),defense(0){}
    Skill(string thename,int theh,int theatt,int thedef )
                :name(thename),tag("Skill"),cd(0),health(theh),attack(theatt),defense(thedef){}
    void coolDown(){cd-=1;}

    int getCD(){return cd;}
    int getHealth(){return health;}
    int getAttack(){return attack;}
    int getDefense(){return defense;}
    string getName(){return name;}
    string getTag(){return tag;}
    void setCD(int thecd){cd=thecd;}
    void setHealth(int theh){health=theh;}
    void setAttack(int theatt){attack=theatt;}
    void setDefense(int thedef){defense=thedef;}
    void setName(string thename){name=thename;}
    void setTag(string thetag){tag=thetag;}
};

#endif // SKILL_H_INCLUDED
