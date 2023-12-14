#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    string playername;
    Room* currentRoom;
    Room* previousRoom;
    int money;
    vector<Item> inventory;
    bool matches;
    Weapon weapon;
public:
    Player(){}
    Player(string player,char classtype):GameCharacter(classtype),playername(player),currentRoom(nullptr),previousRoom(nullptr),money(0),matches(0){
        if(classtype=='a'||classtype=='A'){
            weapon=Weapon("Normal Sword","Soldier",8,3,0);
        }
        else if(classtype=='b'||classtype=='B'){
            weapon=Weapon("Normal Dagger","Assassin",10,2,0);
        }
        else if(classtype=='c'||classtype=='C'){
            weapon=Weapon("Normal Magic Wand","Sorcerer",10,1,0);
        }
        else if(classtype=='d'||classtype=='D'){
            weapon=Weapon("Normal Bow","Archer",9,2,0);
        }
        else if(classtype=='e'||classtype=='E'){
            weapon=Weapon("Normal Staff","Priest",7,2,0);
        }
    }
    void addItem(Item i);
    void increaseStates(int h,int a,int d);
    void changeRoom(Room* r);
    void changeMoney(int m);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object* obj);

    /* Set & Get function*/
    void setCurrentRoom(Room* r){currentRoom=r;}
    void setPreviousRoom(Room* r){previousRoom=r;}
    void setInventory(vector<Item> inven){inventory=inven;}
    void setMoney(int m){money=m;}
    void setMatches(bool b){matches=b;}
    void setWeapon(Weapon w);
    Room* getCurrentRoom(){return currentRoom;}
    Room* getPreviousRoom(){return previousRoom;}
    vector<Item> getInventory(){return inventory;}
    int getMoney(){return money;}
    bool getMatches(){return matches;}
    Weapon getWeapon(){return weapon;}
};

#endif // PLAYER_H_INCLUDED
