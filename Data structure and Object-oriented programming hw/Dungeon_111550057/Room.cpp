#include "Room.h"
#include"Object.h"

using namespace std;

bool Room::popObject(Object* obj){
    unsigned int i;
    bool boss=(obj->getTag()=="Boss");
    for(i=0;i<objects.size();i++){
        if(objects[i]==obj){
            break;
        }
    }

    objects.erase(objects.begin()+i);

    if(objects.size()==0&&boss==false){
        setIndex(0);
    }
    else if(objects.size()==0&&boss==true){
        setIndex(6);
    }
    else if(objects.size()==1){
        if(objects[0]->getTag()=="Monster"){
            setIndex(1);
        }
        else if(objects[0]->getTag()=="Chest"){
            setIndex(3);
        }
    }
}

bool Room::checkDeadEnd(char way){
    if(way=='a'||way=='A'){
        return(getUpRoom()==nullptr);
    }
    else if(way=='b'||way=='B'){
        return(getDownRoom()==nullptr);
    }
    else if(way=='c'||way=='C'){
        return(getRightRoom()==nullptr);
    }
    else if(way=='d'||way=='D'){
        return(getLeftRoom()==nullptr);
    }
}
