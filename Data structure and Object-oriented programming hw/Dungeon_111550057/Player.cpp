#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"
#include "Weapon.h"

using namespace std;

void Player::addItem(Item i){
    inventory.push_back(i);
}

void Player::increaseStates(int h,int a,int d){
    setMaxHealth(getMaxHealth()+h);
    setCurrentHealth(getCurrentHealth()+h);
    setAttack(getAttack()+a);
    setDefense(getDefense()+d);
}

void Player::changeRoom(Room* r){
    previousRoom=currentRoom;
    currentRoom=r;
}

void Player::changeMoney(int m){
    money+=m;
}

void Player::setWeapon(Weapon w){
    increaseStates(0,-(weapon.getAttack()),-(weapon.getDefense()));
    weapon=w;
    increaseStates(0,weapon.getAttack(),weapon.getDefense());
}

bool Player::triggerEvent(Object* obj){
    cout<<endl<<"Status of <"<<playername<<">"<<endl;
    cout<<">Class: "<<getName()<<endl
        <<">Health: "<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl
        <<">Attack: "<<getAttack()<<endl
        <<">Defense: "<<getDefense()<<endl
        <<">Money: $"<<money<<endl
        <<">Weapon: ";
    getWeapon().showWeapon();
    cout<<endl<<">Items in your bag: "<<endl;
    if(inventory.size()==0){
        cout<<"There's nothing in your bag.";
    }
    else{
        for(unsigned int i=0;i<inventory.size();i++){
            inventory[i].showItem();
            cout<<endl;
        }
    }
    cout<<endl;
    return true;
}
