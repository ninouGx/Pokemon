#ifndef TRAINER_H
#define TRAINER_H

#include <vector>
#include <iterator>

#include "functionsPoke.h"

class Trainer
{
private:
    string itsName;
    vector<Pokemon*> *itsPokemonTeam;
public:
    Trainer(const string &itsName);

    void addPokemon(Pokemon *aPokemon);
    void rmPokemon(Pokemon *aPokemon);
    void createTeam();
    void save();
    tuple< vector<Pokemon*>::iterator, bool> findPokemonTeam(string aPokeName);


};

#endif // TRAINER_H
