#include"animal.h"
#include <iostream>
#include <fstream>

#ifndef PARROT_H
#define PARROT_H

using namespace std;

class Parrot: public Animal
{
public:
    Parrot();

    bool CanSpeak;

    bool writeToBase(){
        try{
        ofstream F ("parrots.txt", ios::app);
        F<<Moniker+","
           +BirthYear.toString("dd.MM.yyyy").toLocal8Bit().constData()+","
           +to_string(CanSpeak);
        F.close();
    }
    catch(exception){
        return false;
    }
    return true;
    }
};

#endif // PARROT_H
