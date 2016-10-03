#include"animal.h"
#include <iostream>
#include <fstream>

#ifndef DOG_H
#define DOG_H

using namespace std;

class Dog:public Animal
{
public:
    Dog();

    char Size;

    bool writeToBase(){
        try{
        ofstream F ("dogs.txt", ios::app);
        F<<Moniker+","
           +BirthYear.toString("dd.MM.yyyy").toLocal8Bit().constData()+","
           +Size;
        F.close();
        }
        catch(exception){
            return false;
        }
        return true;
    }
};

#endif // DOG_H
