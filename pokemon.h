#ifndef POKEMON_H
#define POKEMON_H

#include "functions.h"

#define POKEDEXSIZE 151
#define TEAMSIZE 6



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
    float typeTable(Type attackType, Type defType1, Type defType2);
    void attack(Pokemon *aPokemon);
    void tank(int aNbDamage);
    void healPoke();
    bool isAlive();

    float getItsSpeed() const;

    Type getItsType() const;
    Type getItsType2() const;

    const string &getItsName() const;

    int getItsHP() const;
    void setItsHP(int newItsHP);

    int getItsTotalHP() const;



    Pokemon* copyPokemon(); //copy a Pokemon from the general vector to have a unique pokemon each time (team of a single kind of pokemon)

    //nom pv force defence vitesse type1 type2
    friend ostream &operator << (ostream &os, const Pokemon &aPoke)
    {
        return os << "\nName:   " << aPoke.itsName
                  << "\nHealth: " << aPoke.itsHP <<               "\tSpeed:   " << aPoke.itsSpeed
                  << "\nAttack: " << aPoke.itsAttack <<           "\tDefense: " << aPoke.itsDefense
                  << "\nType1:  " << typeToStr(aPoke.itsType1) << "\tType2:   " << typeToStr(aPoke.itsType2) << endl;
    }

};



#endif // POKEMON_H
