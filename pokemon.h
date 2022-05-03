#ifndef POKEMON_H
#define POKEMON_H

#include "functions.h"



float typeTable(Type attackType, Type defType1, Type defType2);

class Pokemon
{
protected:
    string itsName;
    float itsSize;
    float itsWeight;

    //STATS
    int itsCP;
    int itsHP;
    int itsTotalHP;
    int itsAttack;
    int itsDefense;
    float itsSpeed;

    Type itsType1;
    Type itsType2;

    //(itsCP * itsAttack / aPoke.itsDefense)  * Faiblesse
                                              //resitance

public:
    Pokemon(const string &itsName, float itsSize, float itsWeight, int itsHP, int itsAttack, int itsDefense, float itsSpeed, Type itsType1, Type itsType2, int itsCP = 50);
    /*virtual */void attack(Pokemon *aPokemon)/*=0*/;
    void tank(int aNbDamage);
    bool isAlive();
    float getItsSpeed() const;
    Type getItsType() const;
    Type getItsType2() const;
    const string &getItsName() const;
    int getItsHP() const;
    int getItsTotalHP() const;
};



#endif // POKEMON_H
