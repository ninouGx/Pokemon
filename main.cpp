#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <filesystem> //Afin d'indexer les fichiers d'un dossier     https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

#include "functionsTrainer.h"
#include "trainer.h"

using namespace std;

int main()
{
    srand(time(0));

    string aPokeName, aPokeName2, aTrainerName, bootChoice;
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE),
            *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);
//loop start menu to create a trainer and its team
    do
    {
        cout << "[new]\n[load]\n";
        getline(cin, bootChoice);
    }while ((bootChoice != "new") && (bootChoice != "load"));

    cout << "What's your name ?\n";
    getline(cin,aTrainerName);

    Trainer *aTrainer = new Trainer(aTrainerName);

    if (bootChoice == "load")
    {
        *aTrainer = load(aTrainerName);
    }
    else
        aTrainer->createTeam();


    aTrainer->save();
    do
    {
        //ensure to select a valid pokemon
        do
        {
            cout << "Who attack ?\n";
            getline(cin,aPokeName);
            cout << "\n";
        }while( !(get<1>(aTrainer->findPokemonTeam(aPokeName))));

        aPoke = *get<0>(aTrainer->findPokemonTeam(aPokeName));

        do
        {
            cout << "Who defend ?\n";
            getline(cin,aPokeName2);
            cout << "\n";
        }while( !(get<1>(aTrainer->findPokemonTeam(aPokeName2))));

        aPoke2 = *get<0>(aTrainer->findPokemonTeam(aPokeName2));

        aPoke->attack(aPoke2);
    }while((aPoke2->isAlive()) && (aPoke->isAlive()));

    //test operator DONE!
    //cout << *aPoke;

    delete aPoke;
    delete aPoke2;


    //A faire: overload << pour les pokemons : dire noms type et ses stats (propre style tableau) DONE
    //TRainer:  save de sa team avec son nom DONE   +  selection random DONE
    //GERE LES FINDS POUR QUE CELA FONCTIONNE POUR UN TRAINER ET LA LISTE TOTAL DES POKEMONS !! DONE
    //Pour les combats: soit se dire qu'un pokemon est unique sinon meme HP tous (si deux fois le meme pokemon selectione) sinon il faut creer une fctn copy afin d'avoir un nouveau pokemon a partir de la list general en recuperant toutes ses stats.

    // + boucle de jeu pour savoir qui affronte qui
    //pokedex avec image pokemon (qgraphic view / scene)


    //cout << "\ntest " << totalPokeList[28]->getItsName() << endl;


    cout << "\n";
    return 0;
}
