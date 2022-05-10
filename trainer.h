#ifndef TRAINER_H
#define TRAINER_H

#include <vector>
#include <iterator>

#include "functionsPoke.h"

class Trainer
{
protected:

    string itsName;
    vector<Pokemon*> *itsPokemonTeam;
    Pokemon *itsActivePokemon = nullptr; //the pokemon who's fighting

public:
    Trainer(const string &itsName);

    void addPokemon(Pokemon *aPokemon);
    void rmPokemon(Pokemon *aPokemon);
    void createTeam();
    void save();
    void displayTeam();
    tuple< vector<Pokemon*>::iterator, bool> findPokemonTeam(string aPokeName);
    bool canAddPokemon(string aPokeName);
    bool isTeamKO();
    void load(string aTrainerName);
    void healTeam();
    void setItsName(const string &newItsName);
    Pokemon *getItsActivePokemon() const;
    void setItsActivePokemon(Pokemon *newItsActivePokemon);
    const string &getItsName() const;
};

#endif // TRAINER_H
