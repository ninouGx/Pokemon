#include "trainer.h"



void Trainer::addPokemon(Pokemon *aPokemon)
{
    itsPokemonTeam->push_back(aPokemon);
}

void Trainer::rmPokemon(Pokemon *aPokemon)
{

    vector<Pokemon*>::iterator it =  get<0>(findPokemon(aPokemon->getItsName(), *itsPokemonTeam));
    itsPokemonTeam->erase(it);
}

Trainer::Trainer(const string &itsName, vector<Pokemon *> *itsPokemonTeam) : itsName(itsName),
    itsPokemonTeam(itsPokemonTeam)
{}
