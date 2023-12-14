#ifndef MEDICALCENTER_H_INCLUDED
#define MEDICALCENTER_H_INCLUDED

#include<iostream>
#include<string>
#include "Object.h"

using namespace std;

class MedicalCenter:public Object
{
private:

public:
    MedicalCenter(){
        setName("Medical Center");
        setTag("Medical Center");
    }
    virtual bool triggerEvent(Object* obj);
};

#endif // MEDICALCENTER_H_INCLUDED
