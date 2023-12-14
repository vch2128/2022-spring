#include "Object.h"
#include<string>

using namespace std;



Object::Object(string thename,string thetag){
    name=thename;
    tag=thetag;
}

string Object::getName(){
    return name;
}

string Object::getTag(){
    return tag;
}

void Object::setName(string thename){
    name=thename;
}

void Object::setTag(string theTag){
    tag=theTag;
}

