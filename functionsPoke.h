#ifndef FUNCTIONSPOKE_H
#define FUNCTIONSPOKE_H

#include "pokemon.h"

#include <cstdlib>
#include <ctime>
#include <tuple>





vector<Pokemon*> retrievePoke();

tuple< vector<Pokemon*>::iterator, bool> findPokemon(string aPokeName, vector<Pokemon*> aPokeList);



#endif // FUNCTIONSPOKE_H
