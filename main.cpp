#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
//#include <filesystem> //Afin d'indexer les fichiers d'un dossier     https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

#include "gameloop.h"
#include "ai.h"

using namespace std;

int main()
{
    srand(time(0));

    string aPokeName, aPokeName2, aTrainerName, bootChoice;

    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE),
            *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);

    Trainer *aTrainer = new Trainer(aTrainerName),
            *aTrainer2 = new Trainer(aTrainerName);

    AI anAI("testAI");

    cout << "Player 1:\n";
    aTrainer = bootMenu();
    //cout << aTrainer->isTeamKO() << endl;
    cout << "Player 2:\n";
    aTrainer2 = bootMenu();

    aPoke = aTrainer->getItsActivePokemon();
    aPoke2 = aTrainer2->getItsActivePokemon();
    do
    {
        //if a pokemon has fainted in the last turn and to make sure each trainer using a pokemon with some hp left
        hasFaintedPoke(aPoke, aTrainer);
        hasFaintedPoke(aPoke2, aTrainer2);
        do
        {
            battleMenu(aTrainer);
            battleMenu(aTrainer2);

            firstPokeToAttack(aPoke, aPoke2);

            cin.ignore();
        }while(aPoke->isAlive() && aPoke2->isAlive());

    }while(!aTrainer->isTeamKO() && !aTrainer2->isTeamKO());

    losingTrainer(aTrainer, aTrainer2);

    aPoke->setItsHP(1);

    aTrainer->save();
    aTrainer2->save();

    delete aPoke;
    delete aPoke2;
    delete aTrainer;
    delete aTrainer2;

    cout << "\n";
    return 0;
}

 //cout << "\ntest " << totalPokeList[28]->getItsName() << endl;

/* faire sortir de la boucle au ko du pokemon et pas de la team!!!
 * faire choisir un pokemon au debut du combat et doit rester jusqu'a un changement quelconque
 * Permettre le changement de pokemon durant le combat
si pokemon est KO  oblige le changement
penser a ne pas pouvoir choisir un pokemon KO
mettre un pokemon avec de la vie en tant qu'actif*********
si equipe ko mais FIN du combat et soigne l'equipe
preciser le nom du joueur effectuant les actions
*/

//A faire: overload << pour les pokemons : dire noms type et ses stats (propre style tableau) DONE
//TRainer:  save de sa team avec son nom DONE   +  selection random DONE
//GERE LES FINDS POUR QUE CELA FONCTIONNE POUR UN TRAINER ET LA LISTE TOTAL DES POKEMONS !! DONE
//Pour les combats: soit se dire qu'un pokemon est unique sinon meme HP tous (si deux fois le meme pokemon selectione)
//sinon il faut creer une fctn copy afin d'avoir un nouveau pokemon a partir de la list general en recuperant toutes ses stats.DONE

// + boucle de jeu pour savoir qui affronte qui
//pokedex avec image pokemon (qgraphic view / scene)
