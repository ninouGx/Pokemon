#include "gameloop.h"

int versusMenu()
{
    int finalValue;
    string bootChoice;
    do
    {
        cout << "[1V1]\n[1AI]\n[2AI]\n";
        getline(cin, bootChoice);
        strToUpper(bootChoice);
    }while ( (bootChoice != "1V1") && (bootChoice != "1AI") &&  (bootChoice != "2AI") );

    if(bootChoice == "1v1"){
        finalValue = 0;
    }
    else if (bootChoice == "1AI"){
        finalValue = 1;
    }
    else{
        finalValue = 2;
    }
    clearScreen();
    return finalValue;
}


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



void firstPokeToAttack(Trainer *aTrainer, Trainer *aTrainer2)
{
    Pokemon *aPoke = aTrainer->getItsActivePokemon(),
            *aPoke2 = aTrainer2->getItsActivePokemon();

    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        cout << aTrainer->getItsName() << "!\n";
        aPoke->attack(aPoke2);


        if(aPoke2->isAlive())
        {
            clearScreen();
            cout << aTrainer2->getItsName() << "!\n";
            aPoke2->attack(aPoke);
        }
    }
    else
    {
        cout << aTrainer2->getItsName() << "!\n";
        aPoke2->attack(aPoke);

        if(aPoke->isAlive())
        {
            clearScreen();
            cout << aTrainer->getItsName() << "!\n";
            aPoke->attack(aPoke2);
        }
    }
}

void firstPokeToAttack1AI(Trainer *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = aTrainer->getItsActivePokemon(),
            *aPoke2 = aTrainer2->getItsActivePokemon();
    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        cout << aTrainer->getItsName() << "!\n";
        aPoke->attack(aPoke2);

        if(aPoke2->isAlive())
        {
            clearScreen();
            cout << aTrainer2->getItsName() << "!\n";
            aTrainer2->AIattack();
        }
    }
    else
    {
        cout << aTrainer2->getItsName() << "!\n";
        aTrainer2->AIattack();

        if(aPoke->isAlive())
        {
            clearScreen();
            cout << aTrainer->getItsName() << "!\n";
            aPoke->attack(aPoke2);

        }
    }
}


void firstPokeToAttack2AI(AI *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = aTrainer->getItsActivePokemon(),
            *aPoke2 = aTrainer2->getItsActivePokemon();

    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        cout << aTrainer->getItsName() << "!\n";
        aTrainer->AIattack();

        if(aPoke2->isAlive())
        {
            clearScreen();
            cout << aTrainer2->getItsName() << "!\n";
            aTrainer2->AIattack();
        }
        cin.ignore();
    }
    else
    {
        cout << aTrainer2->getItsName() << "!\n";
        aTrainer2->AIattack();

        if(aPoke->isAlive())
        {
            clearScreen();
            cout << aTrainer->getItsName() << "!\n";
            aTrainer->AIattack();

        }
        cin.ignore();
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

void battleSequence(Trainer *aTrainer, Trainer *aTrainer2)
{
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE),
            *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);
    do
    {
        aPoke = aTrainer->getItsActivePokemon();
        aPoke2 = aTrainer2->getItsActivePokemon();

        //if a pokemon has fainted in the last turn and to make sure each trainer using a pokemon with some hp left
        hasFaintedPoke(aPoke, aTrainer);
        hasFaintedPoke(aPoke2, aTrainer2);
        do
        {


            battleMenu(aTrainer);
            battleMenu(aTrainer2);

            aPoke = aTrainer->getItsActivePokemon();
            aPoke2 = aTrainer2->getItsActivePokemon();

            firstPokeToAttack(aTrainer, aTrainer2);

            cin.ignore();
        }while(aPoke->isAlive() && aPoke2->isAlive());

    }while(!aTrainer->isTeamKO() && !aTrainer2->isTeamKO());

    losingTrainer(aTrainer, aTrainer2);

    aPoke->setItsHP(1);

    delete aPoke;
    delete aPoke2;
}

void battleSequence1AI(Trainer *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE),
            *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);
    do
    {
        aPoke = aTrainer->getItsActivePokemon();
        aPoke2 = aTrainer2->getItsActivePokemon();

        //if a pokemon has fainted in the last turn and to make sure each trainer using a pokemon with some hp left
        hasFaintedPoke(aPoke, aTrainer);
        if (!aPoke2->isAlive()){
            aTrainer2->setItsActivePokemon(aTrainer2->bestPokemon());
        }
        cout << "[" << aTrainer2->getItsActivePokemon()->getItsName() << "]" << endl;
        do
        {


            battleMenu(aTrainer);
            //aTrainer2->setItsActivePokemon(aTrainer2->bestPokemon());


            aPoke = aTrainer->getItsActivePokemon();
            aPoke2 = aTrainer2->getItsActivePokemon();

            firstPokeToAttack1AI(aTrainer, aTrainer2);

            cin.ignore();
        }while(aPoke->isAlive() && aPoke2->isAlive());

    }while(!aTrainer->isTeamKO() && !aTrainer2->isTeamKO());

    losingTrainer(aTrainer, aTrainer2);

    aPoke->setItsHP(1);

    delete aPoke;
    delete aPoke2;
}

void battleSequence2AI(AI *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = new Pokemon("test",1,1,1,1,1,1, NONE, NONE),
            *aPoke2 = new Pokemon("test",1,1,1,1,1,1, NONE, NONE);
    do
    {
        aPoke = aTrainer->getItsActivePokemon();
        aPoke2 = aTrainer2->getItsActivePokemon();

        //if a pokemon has fainted in the last turn and to make sure each trainer using a pokemon with some hp left
        if (!aPoke->isAlive()){
            aTrainer->setItsActivePokemon(aTrainer->bestPokemon());
        }
        if (!aPoke2->isAlive()){
            aTrainer2->setItsActivePokemon(aTrainer2->bestPokemon());
        }

        do
        {

            //aTrainer->setItsActivePokemon(aTrainer->bestPokemon());
            //aTrainer2->setItsActivePokemon(aTrainer2->bestPokemon());

            aPoke = aTrainer->getItsActivePokemon();
            aPoke2 = aTrainer2->getItsActivePokemon();

            firstPokeToAttack2AI(aTrainer, aTrainer2);


        }while(aPoke->isAlive() && aPoke2->isAlive());

    }while(!aTrainer->isTeamKO() && !aTrainer2->isTeamKO());

    losingTrainer(aTrainer, aTrainer2);

    aPoke->setItsHP(1);

    delete aPoke;
    delete aPoke2;
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


