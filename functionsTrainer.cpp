#include "functionsTrainer.h"


Trainer load(string aTrainerName)
{
    string tempPokeName;
    ifstream loadFile("../Save/"+aTrainerName+".txt");
    Trainer *aTrainer = new Trainer(aTrainerName);
    for(int i = 0; i<6; i++)
    {
        getline(loadFile, tempPokeName);
        aTrainer->addPokemon(get<0>(findPokemon(tempPokeName)));
    }
    return *aTrainer;
}


