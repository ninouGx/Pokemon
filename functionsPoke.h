#ifndef FUNCTIONSPOKE_H
#define FUNCTIONSPOKE_H

#include "pokemon.h"

#include <cstdlib>
#include <ctime>
#include <tuple>


//To get the whole pokemon list from the file
vector<Pokemon*> retrievePoke();
//assign the pokedex number to the pokemon
map<string, unsigned int> indexPokeList();

//find function for the total pokeList
tuple< Pokemon*, bool> findPokemon(string aPokeName/*, vector<Pokemon*> aPokeList*/);

//find function for trainer


const vector<Pokemon*> totalPokeList = retrievePoke(); //use Q_GLOBAL_STATIC

const map<string, unsigned int> indexPoke = indexPokeList();

#endif // FUNCTIONSPOKE_H
