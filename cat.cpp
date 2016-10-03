#include "cat.h"
#include <iostream>
#include <fstream>

using namespace std;

Cat::Cat()
{

}

bool Cat::writeToBase(){
        try{
        ofstream F;
        F.open("cats.txt", ios::app);
        F<<Moniker+","
           +BirthYear.toString("dd.MM.yyyy").toLocal8Bit().constData()+","
           +Color+"\n";
        F.close();
        }
        catch(exception){
           return false;
        }
        return true;
    }

