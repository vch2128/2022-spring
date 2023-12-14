#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"


using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item*> commodity;
    int pricedown;
public:
    NPC(){}
    NPC(vector<Item*> com,int type):GameCharacter(type),commodity(com){
        if(type==1){
            script="Mysterious person : I am a merchant. Do you want to trade with me? ";
            pricedown=3;
        }
        else if(type==2){
            script="Mysterious person : I am a merchant. I have some good things to show you. Come with me. ";
            pricedown=5;
        }
        else if(type==3){
            script="Little girl : Hello. I am scared and hungry. Can you help me? ";
            pricedown=0;
        }
    }
    void listCommodity(); /*print all the Item in this NPC*/
    void stealThings(Player* plr);
    void sellThings(Player* plr); //merchant sell things to player
    void buyThings(Player* plr);  //merchant buy things from player
    void helpTheGirl(Player* plr);

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object* obj);

    /* Set & Get function*/
    void setScript(string s) {script=s;};
    void setCommodity(vector<Item*> com){commodity=com;};
    string getScript(){return script;};
    vector<Item*> getCommodity(){return commodity;};
};


#endif // NPC_H_INCLUDED
