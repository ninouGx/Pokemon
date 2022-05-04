#include "trainer.h"



void Trainer::addPokemon(Pokemon *aPokemon)
{
    itsPokemonTeam->push_back(aPokemon);
}

void Trainer::rmPokemon(Pokemon *aPokemon)
{
    vector<Pokemon*>::iterator it =  get<0>(findPokemonTeam(aPokemon->getItsName()));
    itsPokemonTeam->erase(it);
}

void Trainer::createTeam()
{
    string teamChoice, chosenPoke;
    do
    {
        cout << "Do you want to [choose] or have a [random] team ?\n";
        getline(cin, teamChoice);
    }while((teamChoice != "choose") && (teamChoice != "random"));

    if (teamChoice == "random")
    {
        for(int i=0; i<6; i++)
        {
            addPokemon(totalPokeList[rand()%POKEDEXSIZE]);
        }
    }
    else
    {
        for(int i=0; i<6; i++)
        {
            do
            {
                cout << "Which Pokemon do you want ?\n";
                getline(cin, chosenPoke);
            }while(!(get<1>(findPokemon(chosenPoke))));

            addPokemon(get<0>(findPokemon(chosenPoke)));
        }

    }
}

void Trainer::save()
{
    ofstream trainerSave("../Save/" + itsName + ".txt");

    for(Pokemon* aPoke : *itsPokemonTeam)
    {
        trainerSave << aPoke->getItsName() << endl;
    }

    trainerSave.close();
}

tuple<vector<Pokemon *>::iterator, bool> Trainer::findPokemonTeam(string aPokeName)
{
    bool isFind = false;
    strToUpper(aPokeName);
    vector<Pokemon*>::iterator it, it2;
    for (it=itsPokemonTeam->begin() ; (it != itsPokemonTeam->end()) && !(isFind); it++ )
    {
        if ((*it)->getItsName() == aPokeName)
        {
            isFind = true;
            it2 = it;
        }
    }
    if ((it == itsPokemonTeam->end()) && !isFind)
        cout << "You don't have this Pokemon in your team!\n\n";
    return make_tuple(it2, isFind);
}


Trainer::Trainer(const string &itsName) : itsName(itsName)
{
    vector<Pokemon *> *aTeam = new  vector<Pokemon *>;
    itsPokemonTeam = aTeam;
}
