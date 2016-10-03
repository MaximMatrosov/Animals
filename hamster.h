#include"animal.h"
#include <iostream>
#include <fstream>

#ifndef HAMSTER_H
#define HAMSTER_H

using namespace std;

class Hamster: public Animal
{
public:
    Hamster();

    char Color;

    bool writeToBase(){
        try{
        ofstream F ("hamsters.txt", ios::app);
        F<<Moniker+","
           +BirthYear.toString("dd.MM.yyyy").toLocal8Bit().constData()+","
           +Color;
        F.close();}
    catch(exception){
        return false;
    }
    return true;
    }
};

#endif // HAMSTER_H
