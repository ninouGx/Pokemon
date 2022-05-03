#include <iostream>
#include "trainer.h"
#include "functionsPoke.h"
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));

    string aPokeName, aPokeName2;
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE), *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);

    vector<Pokemon*> totalPokeList = retrievePoke();

    //ensure to select a valid pokemon
    do
    {
        cout << "Who attack ?\n";
        getline(cin,aPokeName);
        cout << "\n";
    }while( !(get<1>(findPokemon(aPokeName, totalPokeList))));

    aPoke = (*get<0>(findPokemon(aPokeName, totalPokeList)));

    do
    {
        cout << "Who defend ?\n";
        getline(cin,aPokeName2);
        cout << "\n";
    }while( !(get<1>(findPokemon(aPokeName2, totalPokeList))));

    aPoke2 = (*get<0>(findPokemon(aPokeName2, totalPokeList)));

    aPoke->attack(aPoke2);

    delete aPoke;
    delete aPoke2;

    //A faire: overload << pour les pokemons : dire noms type et ses stats (propre style tableau)
    //TRainer: selection random + save de sa team avec son nom
    // + boucle de jeu pour savoir qui affronte qui
    cout << "\ntest " << totalPokeList[28]->getItsName() << endl;


    cout << "\n";
    return 0;
}
