#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    int index;   //0->nothing 1->monster 2->monster+chest 3->chest 4->npc 5->boss
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room(){}
    Room(bool ex):isExit(ex){}
    bool popObject(Object* obj); /*pop out the specific object, used when the interaction is done*/
    bool checkDeadEnd(char way);

    /* Set & Get function*/
    void setUpRoom(Room* r) {upRoom=r;}
    void setDownRoom(Room* r) {downRoom=r;}
    void setLeftRoom(Room* r) {leftRoom=r;}
    void setRightRoom(Room* r) {rightRoom=r;}
    void setIsExit(bool b){isExit=b;}
    void setIndex(int i){index=i;}
    void setObjects(vector<Object*> obj){objects=obj;}
    bool getIsExit(){return isExit;}
    int getIndex(){return index;}
    vector<Object*> getObjects(){return objects;}
    Room* getUpRoom(){return upRoom;}
    Room* getDownRoom(){return downRoom;}
    Room* getLeftRoom(){return leftRoom;}
    Room* getRightRoom(){return rightRoom;}
};

#endif // ROOM_H_INCLUDED
