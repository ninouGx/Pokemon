#ifndef TRAINER_H
#define TRAINER_H

#include <vector>
#include <iterator>

#include "functionsPoke.h"
#include "pokemon.h"

class Trainer
{
private:
    string itsName;
    vector<Pokemon*> *itsPokemonTeam;
public:
    Trainer(const string &itsName, vector<Pokemon *> *itsPokemonTeam);

    void addPokemon(Pokemon *aPokemon);
    void rmPokemon(Pokemon *aPokemon);

};

#endif // TRAINER_H
