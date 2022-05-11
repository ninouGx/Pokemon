#include "trainer.h"



void Trainer::addPokemon(Pokemon *aPokemon)
{
    itsPokemonTeam->push_back(aPokemon);
}

void Trainer::rmPokemon(Pokemon *aPokemon)
{
    vector<Pokemon*>::iterator it =  get<0>(findPokemonTeam(aPokemon->getItsName()));
    itsPokemonTeam->erase(it);
    if(aPokemon == itsActivePokemon)
    {
        itsActivePokemon = nullptr;
    }
}

void Trainer::createTeam()
{
    int indexChoosePoke;
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
            do
            {
                indexChoosePoke = rand()%POKEDEXSIZE;
            }while(!canAddPokemon(totalPokeList[indexChoosePoke]->getItsName()));

            addPokemon(totalPokeList[indexChoosePoke]->copyPokemon());
        }
    }
    else
    {
        for(int i=0; i<6; i++)
        {
            do
            {


                //ensure to select a valid pokemon
                do
                {
                    cout << i+1 <<") Which Pokemon do you want ?\n";
                    getline(cin, chosenPoke);
                    cout << "\n";

                }while( !get<1>(findPokemon(chosenPoke)));

                if ( !canAddPokemon(chosenPoke) )
                {
                    cout << "You already have this Pokemon!\n";
                }
            }while(!canAddPokemon(chosenPoke));

            addPokemon(get<0>(findPokemon(chosenPoke))->copyPokemon());
        }

    }
    itsActivePokemon = itsPokemonTeam->front();
}

void Trainer::save()
{
    ofstream trainerSave("../Save/" + itsName + ".txt");

    for(Pokemon* aPoke : *itsPokemonTeam)
    {
        trainerSave << aPoke->getItsName() << "-" << aPoke->getItsHP() << endl;
    }

    trainerSave.close();
}

void Trainer::displayTeam()
{
    cout << itsName << " Team: ";
    for(Pokemon* aPoke : *itsPokemonTeam)
    {
        cout << "[" << aPoke->getItsName() << "  " << aPoke->getItsHP() << "/" << aPoke->getItsTotalHP() << "]   ";
    }
    cout << "\n";
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
    //if ((it == itsPokemonTeam->end()) && !isFind)
        //cout << "You don't have this Pokemon in your team!\n\n";
    return make_tuple(it2, isFind);
}

bool Trainer::canAddPokemon(string aPokeName)
{
    //si le isFind de findPoke est vrai alors on ne peut pas add
    return !get<1>(findPokemonTeam(aPokeName));
}

bool Trainer::isTeamKO()
{
    bool isKO = false;
    int andSum = 0;
    for(Pokemon* aPoke : *itsPokemonTeam)
    {
        if (!aPoke->isAlive())
        {
            andSum++;
        }
    }
    if(andSum == TEAMSIZE)
    {
        isKO = true;
    }
    return isKO;
}

void Trainer::load(string aTrainerName)
{
    int tempLife;
    string tempPokeName, tempStrLife;
    ifstream loadFile("../Save/"+aTrainerName+".txt");
    for(int i = 0; i<6; i++)
    {
        getline(loadFile, tempPokeName, '-');
        getline(loadFile, tempStrLife);
        tempLife = stoi(tempStrLife);
        addPokemon(get<0>(findPokemon(tempPokeName))->copyPokemon());
        (*get<0>(findPokemonTeam(tempPokeName)))->setItsHP(tempLife);
        if(i == 0)
        {
            itsActivePokemon = itsPokemonTeam->front();
        }
    }
    setItsName(aTrainerName);



    loadFile.close();
}

void Trainer::healTeam()
{
    for(Pokemon* aPoke : *itsPokemonTeam)
    {
        aPoke->healPoke();
    }
}




void Trainer::setItsName(const string &newItsName)
{
    itsName = newItsName;
}

Pokemon *Trainer::getItsActivePokemon() const
{
    return itsActivePokemon;
}

void Trainer::setItsActivePokemon(Pokemon *newItsActivePokemon)
{
    itsActivePokemon = newItsActivePokemon;
}

const string &Trainer::getItsName() const
{
    return itsName;
}

bool Trainer::getAlreadyFightSwap() const
{
    return alreadyFightSwap;
}

void Trainer::setAlreadyFightSwap(bool newAlreadyFightSwap)
{
    alreadyFightSwap = newAlreadyFightSwap;
}

Trainer::Trainer(const string &itsName) : itsName(itsName)
{
    vector<Pokemon *> *aTeam = new  vector<Pokemon *>;
    itsPokemonTeam = aTeam;
}
