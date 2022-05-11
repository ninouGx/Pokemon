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

    if(bootChoice == "1V1"){
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

void battleMenu(Trainer *aTrainer)
{

    string inputChoice;
    Pokemon *tempPoke = aTrainer->getItsActivePokemon();

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
        if(aTrainer->getItsActivePokemon() != tempPoke){
            aTrainer->setAlreadyFightSwap(true);
        }

        //battleMenu(aTrainer);
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

        //if the pokemon exist in team and is not alive
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
        if (!aTrainer->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);

            cout << aTrainer->getItsName() << "!\n";
            aPoke->attack(aPoke2);

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke2->isAlive())
        {
            if(!aTrainer2->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);

                cout << aTrainer2->getItsName() << "!\n";
                aPoke2->attack(aPoke);

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
        }
    }
    else
    {
        if(!aTrainer2->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);

            cout << aTrainer2->getItsName() << "!\n";
            aPoke2->attack(aPoke);

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke->isAlive())
        {
            if (!aTrainer->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);

                cout << aTrainer->getItsName() << "!\n";
                aPoke->attack(aPoke2);

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
        }
    }
}

void firstPokeToAttack1AI(Trainer *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = aTrainer->getItsActivePokemon(),
            *aPoke2 = aTrainer2->getItsActivePokemon();

    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        if (!aTrainer->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);

            cout << aTrainer->getItsName() << "!\n";
            aPoke->attack(aPoke2);

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke2->isAlive())
        {
            if(!aTrainer2->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);

                cout << aTrainer2->getItsName() << "!\n";
                aTrainer2->AIattack();

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
        }
    }
    else
    {
        if(!aTrainer2->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);

            cout << aTrainer2->getItsName() << "!\n";
            aTrainer2->AIattack();

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke->isAlive())
        {
            if (!aTrainer->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);

                cout << aTrainer->getItsName() << "!\n";
                aPoke->attack(aPoke2);

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
        }
    }
}


void firstPokeToAttack2AI(AI *aTrainer, AI *aTrainer2)
{
    Pokemon *aPoke = aTrainer->getItsActivePokemon(),
            *aPoke2 = aTrainer2->getItsActivePokemon();

    if(aPoke->getItsSpeed() > aPoke2->getItsSpeed())
    {
        if (!aTrainer->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);
            cout << aTrainer->getItsName() << "!\n";
            aTrainer->AIattack();

            cout << "\n";
            aTrainer->displayTeam();
            cout << "\n";
            aTrainer->getItsOpponent()->displayTeam();

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke2->isAlive())
        {
            if(!aTrainer2->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);
                cout << aTrainer2->getItsName() << "!\n";
                aTrainer2->AIattack();

                cout << "\n";
                aTrainer2->displayTeam();
                cout << "\n";
                aTrainer2->getItsOpponent()->displayTeam();

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
        }
    }
    else
    {
        if(!aTrainer2->getAlreadyFightSwap()){
            clearScreen();
            displayPokemonVSPokemon(aPoke, aPoke2);
            cout << aTrainer2->getItsName() << "!\n";
            aTrainer2->AIattack();

            cout << "\n";
            aTrainer2->displayTeam();
            cout << "\n";
            aTrainer2->getItsOpponent()->displayTeam();

            cout << "\nPress Enter to continue!\n";
            cin.ignore();
        }

        if(aPoke->isAlive())
        {
            if (!aTrainer->getAlreadyFightSwap()){
                clearScreen();
                displayPokemonVSPokemon(aPoke, aPoke2);
                cout << aTrainer->getItsName() << "!\n";
                aTrainer->AIattack();

                cout << "\n";
                aTrainer->displayTeam();
                cout << "\n";
                aTrainer->getItsOpponent()->displayTeam();

                cout << "\nPress Enter to continue!\n";
                cin.ignore();
            }
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

            aTrainer->setAlreadyFightSwap(false);
            aTrainer2->setAlreadyFightSwap(false);
            battleMenu(aTrainer);
            battleMenu(aTrainer2);

            aPoke = aTrainer->getItsActivePokemon();
            aPoke2 = aTrainer2->getItsActivePokemon();

            firstPokeToAttack(aTrainer, aTrainer2);

            //cout << "\nPress Enter to continue!\n";
            //cin.ignore();
            clearScreen();
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
        //cout << "[" << aTrainer->getItsActivePokemon()->getItsName() << "] vs [" << aTrainer2->getItsActivePokemon()->getItsName() << "]\n";

        do
        {
            clearScreen();
            displayPokemonVSPokemon(aTrainer->getItsActivePokemon(), aTrainer2->getItsActivePokemon());
            aTrainer->setAlreadyFightSwap(false);
            aTrainer2->setAlreadyFightSwap(false);


            battleMenu(aTrainer);
            //aTrainer2->setItsActivePokemon(aTrainer2->bestPokemon());

            aPoke = aTrainer->getItsActivePokemon();
            aPoke2 = aTrainer2->getItsActivePokemon();



            firstPokeToAttack1AI(aTrainer, aTrainer2);

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
    clearScreen();
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



void displayPokemonVSPokemon(Pokemon *aPoke, Pokemon *aPoke2)
{
    string tempOutput, tempOutput2;

    map<string, unsigned int> indexPoke2 = indexPokeList();

    auto wantedPoke = indexPoke2.find(aPoke->getItsName()),
            wantedPoke2 = indexPoke2.find(aPoke2->getItsName());

    std::ifstream inFile("../PokeAscii/"+to_string(wantedPoke->second)+".txt"),
            inFile2("../PokeAscii/"+to_string(wantedPoke2->second)+".txt");

    int numberOfLine1 = 0, numberOfLine2 = 0, max1 = 0, max2 = 0, temp;
    std::string unused;
    while ( !inFile.eof() )
    {
        getline(inFile,unused);
        temp = unused.length();
        max1 = max(temp, max1);
       ++numberOfLine1;
    }
    while ( !inFile2.eof() )
    {
        getline(inFile2,unused);
        temp = unused.length();
        max2 = max(temp, max2);
       ++numberOfLine2;
    }
    inFile.clear();
    inFile2.clear();
    inFile.seekg(0,ios::beg);
    inFile2.seekg(0,ios::beg);


    for(int i = 0; i<max(numberOfLine1, numberOfLine2); i++)
    {
        getline(inFile, tempOutput);
        getline(inFile2, tempOutput2);
        if(numberOfLine1 > numberOfLine2)
        {
            cout << tempOutput;
            nbBlank(max1-tempOutput.length());
            cout << "\t\t\t\t" << tempOutput2 << endl;
        }
        else
        {
            cout << tempOutput2;
            nbBlank(max2-tempOutput2.length());
            cout << "\t\t\t\t" << tempOutput << endl;
        }
    }



    if(numberOfLine1 > numberOfLine2)
    {
        //first poke
        nbBlank(max1/3);
        cout << aPoke->getItsName() << " [" << typeToStr(aPoke->getItsType()) << "] ";
        if(aPoke->getItsType() != aPoke->getItsType2())
            cout << "[" << typeToStr(aPoke->getItsType2()) << "]";

        //second poke
        nbBlank(max1/2+max2/3);
        cout << aPoke2->getItsName() << " [" << typeToStr(aPoke2->getItsType()) << "] ";
        if(aPoke2->getItsType() != aPoke2->getItsType2())
            cout << "[" << typeToStr(aPoke2->getItsType2()) << "]";
    }
    else
    {
        //second poke
        nbBlank(max2/3);
        cout << aPoke2->getItsName() << " [" << typeToStr(aPoke2->getItsType()) << "] ";
        if(aPoke2->getItsType() != aPoke2->getItsType2())
            cout << "[" << typeToStr(aPoke2->getItsType2()) << "]";

        //first poke
        nbBlank(max2/2+max1/3);
        cout << aPoke->getItsName() << " [" << typeToStr(aPoke->getItsType()) << "] ";
        if(aPoke->getItsType() != aPoke->getItsType2())
            cout << "[" << typeToStr(aPoke->getItsType2()) << "]";
    }
    cout << endl;


    //print_pokemon(wantedPoke->second);

    if(numberOfLine1 > numberOfLine2)
        nbBlank(max1);
    else
        nbBlank(max2);
    cout <<   "  888  888 .d8888b  \n";
    if(numberOfLine1 > numberOfLine2)
        nbBlank(max1);
    else
        nbBlank(max2);
    cout << "  888  888 88K      \n";
    if(numberOfLine1 > numberOfLine2)
        nbBlank(max1);
    else
        nbBlank(max2);
    cout <<      "  Y88  88P \"Y8888b. \n";
    if(numberOfLine1 > numberOfLine2)
        nbBlank(max1);
    else
        nbBlank(max2);
       cout <<     "   Y8bd8P       X88 \n";
    if(numberOfLine1 > numberOfLine2)
        nbBlank(max1);
    else
        nbBlank(max2);
       cout << "    Y88P    88888P' \n\n";

    //print_pokemon(wantedPoke->second);
    inFile.close();
    inFile2.close();
}
