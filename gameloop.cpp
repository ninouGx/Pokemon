#include "gameloop.h"

Trainer *bootMenu()
{
    string bootChoice, aTrainerName;
    //loop start menu to create a trainer and its team
    do
    {
        cout << "[new]\n[load]\n";
        getline(cin, bootChoice);
    }while ((bootChoice != "new") && (bootChoice != "load"));

    cout << "What's your name ?\n";
    getline(cin,aTrainerName);
    cout << "\n";

    Trainer *aTrainer = new Trainer(aTrainerName);

    if (bootChoice == "load")
    {
        aTrainer->load(aTrainerName);
    }
    else
    {
        aTrainer->createTeam();
    }
    clearScreen();

    aTrainer->save();

    return aTrainer;
}

/*if(newItsActivePokemon == itsActivePokemon)
    {
        cout << itsActivePokemon->getItsName() << " is already fighting!\n";
    }
    else
    {
        itsActivePokemon = newItsActivePokemon;
    }*/
void battleMenu(Trainer *aTrainer)
{

    string inputChoice;

    cout << aTrainer->getItsName() << "!" << endl;
    do
    {
        cout << "[attack] [team]\n";
        getline(cin, inputChoice);
        cout << "\n";
    }while((inputChoice != "attack") && (inputChoice != "team"));

    if (inputChoice == "team")
    {
        aTrainer->setItsActivePokemon(battleTurn(aTrainer));
        battleMenu(aTrainer);
    }
    clearScreen();
}

Pokemon *battleTurn(Trainer *aTrainer)
{
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);
    string aPokeName="";

    aTrainer->save();
    cout << aTrainer->getItsName() << "!" << endl;
    //ensure to select a valid pokemon
    do
    {

        cout << "Who attack ?\n";
        aTrainer->displayTeam();
        getline(cin,aPokeName);
        cout << "\n";

        if ( get<1>(aTrainer->findPokemonTeam(aPokeName)) && !((*get<0>(aTrainer->findPokemonTeam(aPokeName)))->isAlive()))
        {
            aPoke = *get<0>(aTrainer->findPokemonTeam(aPokeName));
            cout <<  aPoke->getItsName() << " is KO you can't choose him!\n";
        }
    }while( !(get<1>(aTrainer->findPokemonTeam(aPokeName))) || !(*get<0>(aTrainer->findPokemonTeam(aPokeName)))->isAlive());

    clearScreen();

    return aPoke = *get<0>(aTrainer->findPokemonTeam(aPokeName));
}



void clearScreen()
{
    #ifdef linux
        system("clear");
    #endif
    #ifdef _WIN32
        system("cls");
    #endif
    #ifdef __APPLE__
        system ("clear");
    #endif
}

void losingTrainer(Trainer *aTrainer, Trainer *aTrainer2)
{
    if ( aTrainer->isTeamKO()){
        cout << aTrainer->getItsName() << " is out of usable Pokemon!\n"
             << aTrainer2->getItsName() << " has won!";
        //aTrainer->healTeam();
    }
    else{
        cout << aTrainer2->getItsName() << " is out of usable Pokemon!\n"
             << aTrainer->getItsName() << " has won!";
        //aTrainer2->healTeam();
    }
}


void firstPokeToAttack(Pokemon *aPoke, Pokemon *aPoke2)
{
    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        aPoke->attack(aPoke2);
        if(aPoke2->isAlive())
        {
            aPoke2->attack(aPoke);
        }
    }
    else
    {
        aPoke2->attack(aPoke);
        if(aPoke->isAlive())
        {
            aPoke->attack(aPoke2);
        }
    }
}


void hasFaintedPoke(Pokemon *aPoke, Trainer *aTrainer)
{
    if(!aPoke->isAlive())
    {

        cout << aTrainer->getItsName() << "!" << endl
             << aPoke->getItsName() << " is KO, you have to change!\n\n";
        aTrainer->setItsActivePokemon(battleTurn(aTrainer));
    }
}
