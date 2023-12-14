#include "Dungeon.h"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Item.h"
#include "Chest.h"
#include "MedicalCenter.h"

using namespace std;

void Dungeon::createPlayer(){
    string playername;
    char ans;
    cout<<"Please insert your name:";
    cin>>playername;
    cout<<endl<<"Please choose your character class."<<endl
        <<"a. Soldier: HP:100 / Attack:20 / Defense:5 / Skills:Running Attack, Mighty Swing"<<endl
        <<"b. Assassin: HP:80 / Attack:25 / Defense:2 / Skills:Sneak Attack, Quiet Death"<<endl
        <<"c. Sorcerer: HP:80 / Attack:28 / Defense:2 / Skills:Frost Bolt, Chain Lightning"<<endl
        <<"d. Archer: HP:90 / Attack:22 / Defense:4 / Skills:Quick Shot, Blazing Arrow"<<endl
        <<"e. Priest: HP:100 / Attack:18 / Defense:1 / Skills:Magic Barrier, Holy Aura"<<endl;
    cin>>ans;
    while(ans!='a'&&ans!='A'&&ans!='b'&&ans!='B'&&ans!='c'&&ans!='C'&&ans!='d'&&ans!='D'&&ans!='E'&&ans!='e'){
        cout<<endl<<"Unavailable. Please choose again. "<<endl;
        cin>>ans;
    }
    player=Player(playername,ans);
    player.triggerEvent(&player);
}

void Dungeon::createMap(){
    vector<Object*> obj;
    Monster* m;
    Item* i;
    Chest* c;
    NPC* n;
    MedicalCenter* medi;
    vector<Item*> com;
    for(unsigned int i=0;i<17;i++){
        rooms.push_back(Room(false));
    }

    //0
    rooms[0].setIndex(0);
    rooms[0].setDownRoom(&rooms[1]);
    rooms[0].setUpRoom(nullptr);
    rooms[0].setRightRoom(nullptr);
    rooms[0].setLeftRoom(nullptr);

    //1
    rooms[1].setIndex(1);
    rooms[1].setDownRoom(&rooms[2]);
    rooms[1].setUpRoom(&rooms[0]);
    rooms[1].setRightRoom(&rooms[4]);
    rooms[1].setLeftRoom(&rooms[3]);
    m=new Monster(2,0);
    obj.push_back(m);
    rooms[1].setObjects(obj);
    obj.clear();

    //2
    rooms[2].setIndex(1);
    rooms[2].setDownRoom(&rooms[8]);
    rooms[2].setUpRoom(&rooms[1]);
    rooms[2].setRightRoom(&rooms[5]);
    rooms[2].setLeftRoom(&rooms[6]);
    m=new Monster(3,0);
    obj.push_back(m);
    rooms[2].setObjects(obj);
    obj.clear();

    //3
    rooms[3].setIndex(3);
    rooms[3].setDownRoom(&rooms[6]);
    rooms[3].setUpRoom(nullptr);
    rooms[3].setRightRoom(&rooms[1]);
    rooms[3].setLeftRoom(nullptr);
    i=new Item("Jar of Fortitude",0,4,0,10,15);
    c=new Chest(12,30,i);
    obj.push_back(c);
    rooms[3].setObjects(obj);
    obj.clear();

    //4
    rooms[4].setIndex(2);
    rooms[4].setDownRoom(&rooms[5]);
    rooms[4].setUpRoom(nullptr);
    rooms[4].setRightRoom(nullptr);
    rooms[4].setLeftRoom(&rooms[1]);
    m=new Monster(1,0);
    obj.push_back(m);
    i=new Weapon("Big Sword","Soldier",15,12,20);
    c=new Chest(20,30,i);
    obj.push_back(c);
    rooms[4].setObjects(obj);
    obj.clear();

    //5
    rooms[5].setIndex(4);
    rooms[5].setDownRoom(&rooms[7]);
    rooms[5].setUpRoom(&rooms[4]);
    rooms[5].setRightRoom(&rooms[15]);
    rooms[5].setLeftRoom(&rooms[2]);
        //commodity of thief
        i=new Item("Exiled Horn",0,3,5,2,16);
        com.push_back(i);
        i=new Item("Decimation Stone",0,-3,10,0,18);
        com.push_back(i);
        i=new Item("Spite Gauntlet",0,0,8,0,10);
        com.push_back(i);
        i=new Weapon("Aurora Staff","Priest",12,19,20);
        com.push_back(i);
        i=new Weapon("Poisoned Dagger","Assassin",18,7,20);
        com.push_back(i);
    n=new NPC(com,2);
    com.clear();
    obj.push_back(n);
    rooms[5].setObjects(obj);
    obj.clear();

    //6
    rooms[6].setIndex(4);
    rooms[6].setDownRoom(&rooms[9]);
    rooms[6].setUpRoom(&rooms[6]);
    rooms[6].setRightRoom(&rooms[2]);
    rooms[6].setLeftRoom(nullptr);
    n=new NPC(com,3);
    obj.push_back(n);
    rooms[6].setObjects(obj);
    obj.clear();

    //7
    rooms[7].setIndex(3);
    rooms[7].setDownRoom(&rooms[16]);
    rooms[7].setUpRoom(&rooms[5]);
    rooms[7].setRightRoom(nullptr);
    rooms[7].setLeftRoom(&rooms[8]);
    i=new Item("Securing Lamp",0,0,5,10,18);
    c=new Chest(33,50,i);
    obj.push_back(c);
    rooms[7].setObjects(obj);
    obj.clear();

    //8
    rooms[8].setIndex(4);
    rooms[8].setDownRoom(&rooms[11]);
    rooms[8].setUpRoom(&rooms[2]);
    rooms[8].setRightRoom(&rooms[7]);
    rooms[8].setLeftRoom(&rooms[9]);
        //commodity of merchant
        i=new Item("Finality Ring",0,4,5,3,15);
        com.push_back(i);
        i=new Item("Circlet of Apathy",0,0,5,8,12);
        com.push_back(i);
        i=new Item("Skull of Riddles",0,0,8,1,11);
        com.push_back(i);
        i=new Weapon("Silver Bow","Archer",15,12,20);
        com.push_back(i);
        i=new Weapon("Holy Wand","Sorcerer",19,8,20);
        com.push_back(i);
    n=new NPC(com,1);
    com.clear();
    obj.push_back(n);
    rooms[8].setObjects(obj);
    obj.clear();

    //9
    rooms[9].setIndex(2);
    rooms[9].setDownRoom(&rooms[17]);
    rooms[9].setUpRoom(&rooms[6]);
    rooms[9].setRightRoom(&rooms[8]);
    rooms[9].setLeftRoom(&rooms[10]);
    m=new Monster(4,0);
    obj.push_back(m);
    i=new Item("Virtue Mask",0,3,5,2,10);
    c=new Chest(30,30,i);
    obj.push_back(c);
    rooms[9].setObjects(obj);
    obj.clear();

    //10
    rooms[10].setIndex(5);
    rooms[10].setDownRoom(nullptr);
    rooms[10].setUpRoom(nullptr);
    rooms[10].setRightRoom(&rooms[9]);
    rooms[10].setLeftRoom(nullptr);
    m=new Monster(1,1);
    obj.push_back(m);
    rooms[10].setObjects(obj);
    rooms[10].setIsExit(true);
    obj.clear();

    //11
    rooms[11].setIndex(2);
    rooms[11].setDownRoom(&rooms[14]);
    rooms[11].setUpRoom(&rooms[8]);
    rooms[11].setRightRoom(&rooms[16]);
    rooms[11].setLeftRoom(&rooms[17]);
    m=new Monster(2,0);
    obj.push_back(m);
    i=new Item("Mirage Pillar",0,0,8,6,14);
    c=new Chest(20,30,i);
    obj.push_back(c);
    rooms[11].setObjects(obj);
    obj.clear();

    //12
    rooms[12].setIndex(4);
    rooms[12].setDownRoom(nullptr);
    rooms[12].setUpRoom(&rooms[16]);
    rooms[12].setRightRoom(nullptr);
    rooms[12].setLeftRoom(&rooms[14]);
        //commodity of thief
        i=new Item("Jar of Fortitude",0,4,0,10,15);
        com.push_back(i);
        i=new Item("Decimation Stone",0,-3,10,0,18);
        com.push_back(i);
        i=new Item("Securing Lamp",0,0,5,10,20);
        com.push_back(i);
        i=new Weapon("Big Sword","Soldier",15,12,20);
        com.push_back(i);
        i=new Weapon("Poisoned Dagger","Assassin",18,7,20);
        com.push_back(i);
    n=new NPC(com,2);
    com.clear();
    obj.push_back(n);
    rooms[12].setObjects(obj);
    obj.clear();

    //13
    rooms[13].setIndex(3);
    rooms[13].setDownRoom(nullptr);
    rooms[13].setUpRoom(&rooms[17]);
    rooms[13].setRightRoom(&rooms[14]);
    rooms[13].setLeftRoom(nullptr);
    i=new Weapon("Holy Wand","Sorcerer",19,8,20);
    c=new Chest(28,50,i);
    obj.push_back(c);
    rooms[13].setObjects(obj);
    obj.clear();

    //14
    rooms[14].setIndex(5);
    rooms[14].setDownRoom(nullptr);
    rooms[14].setUpRoom(&rooms[11]);
    rooms[14].setRightRoom(&rooms[12]);
    rooms[14].setLeftRoom(&rooms[13]);
    m=new Monster(2,1);
    obj.push_back(m);
    rooms[14].setObjects(obj);
    rooms[14].setIsExit(true);
    obj.clear();

    //15
    rooms[15].setIndex(1);
    rooms[15].setDownRoom(nullptr);
    rooms[15].setUpRoom(nullptr);
    rooms[15].setRightRoom(nullptr);
    rooms[15].setLeftRoom(&rooms[5]);
    m=new Monster(4,0);
    obj.push_back(m);
    rooms[15].setObjects(obj);
    obj.clear();

    //16
    rooms[16].setIndex(2);
    rooms[16].setDownRoom(&rooms[12]);
    rooms[16].setUpRoom(&rooms[7]);
    rooms[16].setRightRoom(nullptr);
    rooms[16].setLeftRoom(&rooms[11]);
    m=new Monster(3,0);
    obj.push_back(m);
    i=new Item("Rod of Souls",0,3,0,6,12);
    c=new Chest(21,30,i);
    obj.push_back(c);
    rooms[16].setObjects(obj);
    obj.clear();

    //17
    rooms[17].setIndex(7);
    rooms[17].setDownRoom(&rooms[13]);
    rooms[17].setUpRoom(&rooms[9]);
    rooms[17].setRightRoom(&rooms[11]);
    rooms[17].setLeftRoom(nullptr);
    medi=new MedicalCenter();
    obj.push_back(medi);
    rooms[17].setObjects(obj);
    obj.clear();
}

void Dungeon::handleMovement(){
    char ans;
    bool b=1;
    while(b==1){
    cout<<endl<<"Which way do you want to go?"<<endl
        <<"a. Go up."<<endl
        <<"b. Go down."<<endl
        <<"c. Go right."<<endl
        <<"d. Go left."<<endl;
    cin>>ans;
    b=player.getCurrentRoom()->checkDeadEnd(ans);
    if(b==true){
        cout<<endl<<"You met a dead end. Choose again. "<<endl;
    }
    else{
        if(ans=='a'||ans=='A'){
            player.changeRoom(player.getCurrentRoom()->getUpRoom());
        }
        else if(ans=='b'||ans=='B'){
            player.changeRoom(player.getCurrentRoom()->getDownRoom());
        }
        else if(ans=='c'||ans=='C'){
            player.changeRoom(player.getCurrentRoom()->getRightRoom());
        }
        else if(ans=='d'||ans=='D'){
            player.changeRoom(player.getCurrentRoom()->getLeftRoom());
        }
    }
    }
}

void Dungeon::handleEvent(Object* obj){  //monster.npc.chest  true->pop  false->don't pop
    bool b;
    b=obj->triggerEvent(&player);
    if(b==true){
        player.getCurrentRoom()->popObject(obj);
    }
}

void Dungeon::startGame(){
    createMap();
    createPlayer();
    player.setCurrentRoom(&rooms[0]);
    player.setPreviousRoom(nullptr);
    cout<<endl<<"Welcome to the dungeon."<<endl;
}

void Dungeon::chooseAction(vector<Object*> obj){
    unsigned int i;
    Room* currentRoom=player.getCurrentRoom();
    char ans;
    cout<<endl<<"What do you want to do?"<<endl
        <<"a. Move."<<endl
        <<"b. Check status."<<endl;

    if(currentRoom->getIndex()==0||currentRoom->getIndex()==1){
        cin>>ans;
        while(ans!='a'&&ans!='b'&&ans!='A'&&ans!='B'){
            cout<<"Unavailable. Please insert again."<<endl;
            cin>>ans;
        }
    }
    else if(currentRoom->getIndex()==2||currentRoom->getIndex()==3){
        cout<<"c. Check the chest."<<endl;
        cin>>ans;
        while(ans!='a'&&ans!='b'&&ans!='A'&&ans!='B'&&ans!='c'&&ans!='C'){
            cout<<"Unavailable. Please insert again."<<endl;
            cin>>ans;
        }
        if(ans=='c'||ans=='C'){
            for(i=0;i<obj.size();i++){
                if(obj[i]->getTag()=="Chest"){ break; }
            }
            handleEvent(obj[i]);
        }
    }
    else if(currentRoom->getIndex()==4){
        cout<<"c. Talk to NPC."<<endl;
        cin>>ans;
        while(ans!='a'&&ans!='b'&&ans!='A'&&ans!='B'&&ans!='c'&&ans!='C'){
            cout<<"Unavailable. Please insert again."<<endl;
            cin>>ans;
        }
        if(ans=='c'||ans=='C'){
            for(i=0;i<obj.size();i++){
                if(obj[i]->getTag()=="NPC"){ break; }
            }
            handleEvent(obj[i]);
        }
    }
    else if(currentRoom->getIndex()==6){
        cout<<"c. Exit the dungeon."<<endl;
        cin>>ans;
        while(ans!='a'&&ans!='b'&&ans!='A'&&ans!='B'&&ans!='c'&&ans!='C'){
            cout<<"Unavailable. Please insert again."<<endl;
            cin>>ans;
        }
        if(ans=='c'||ans=='C'){
            cout<<endl<<"Congratulations! You escaped the dungeon successfully."<<endl;
            player.triggerEvent(&player);
            setRun(false);
        }
    }
    else if(currentRoom->getIndex()==7){
        cout<<"c. Go to Medical Center."<<endl;
        cin>>ans;
        while(ans!='a'&&ans!='b'&&ans!='A'&&ans!='B'&&ans!='c'&&ans!='C'){
            cout<<"Unavailable. Please insert again."<<endl;
            cin>>ans;
        }
        if(ans=='c'||ans=='C'){
            for(i=0;i<obj.size();i++){
                if(obj[i]->getTag()=="Medical Center"){ break; }
            }
            handleEvent(obj[i]);
        }
    }

    if(ans=='a'||ans=='A'){
        handleMovement();
    }
    else if(ans=='b'||ans=='B'){
        player.triggerEvent(&player);
    }
}


bool Dungeon::checkGameLogic(){  //true->continue  false->end
    if(player.checkIsDead()){
        return false;
    }
    else if(!player.checkIsDead()&&!run){
        return false;
    }
    return true;
}

void Dungeon::runDungeon(){
    int index;
    startGame();
    while(checkGameLogic()){
        index=player.getCurrentRoom()->getIndex();
        //cout<<endl<<"current room index: "<<player.getCurrentRoom()->getIndex()<<endl;
        if(index==1||index==2||index==5){
            handleEvent(player.getCurrentRoom()->getObjects()[0]);
            //cout<<endl<<"current room index: "<<player.getCurrentRoom()->getIndex()<<endl;
        }
        if(checkGameLogic()){
            chooseAction(player.getCurrentRoom()->getObjects());
        }
        //cout<<endl<<"gamelogic:"<<checkGameLogic()<<endl;
    }
}
