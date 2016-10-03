#include <QDateTime>
#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;
class Animal
{
public:
    Animal();

    string Moniker;
    QDate BirthYear;

    virtual bool writeToBase()= 0;
};

#endif // ANIMAL_H
