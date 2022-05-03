#include "functionsPoke.h"





//to get the list of all the pokemon database
vector<Pokemon*> retrievePoke()
{

    vector<Pokemon*> pokeList;
    ifstream inPokeList("../MiniProjNoms/fichierModifPoke/listFinalP.txt");
    string aName,
            anHP,
            anAttack,
            aDefense,
            aSpeed,
            aSpecial,
            aType1,
            aType2;
    Type theType1, theType2;
    int theHP,
            theAttack,
            theDefense,
            theSpeed,
            theSpecial;


    do
    {
        getline(inPokeList, aName);
        getline(inPokeList, anHP);
        getline(inPokeList, anAttack);
        getline(inPokeList, aDefense);
        getline(inPokeList, aSpeed);
        getline(inPokeList, aSpecial);
        getline(inPokeList, aType1);
        getline(inPokeList, aType2);

        //conversion des types string en TYPE
        theType1 = strToType(aType1);
        theType2 = strToType(aType2);

        if ( theType2 == NONE)
        {
                theType2 = theType1;
        }
        else //car il reste un vide encore apres la position du second type
            getline(inPokeList, aType2);

        //Conversion en valeur des strings
        theHP = stoi(anHP);
        theAttack = stoi(anAttack);
        theDefense = stoi(aDefense);
        theSpeed = stoi(aSpeed);
        theSpecial = stoi(aSpecial);


        Pokemon *aNewPoke = new Pokemon(aName, float(rand()%50+1), float(rand()%4+1), theHP*2, int((theAttack + theSpecial)/2), theDefense, theSpeed, theType1, theType2);
        pokeList.push_back(aNewPoke);
    }while(!inPokeList.eof());

    return pokeList;
}




tuple<vector<Pokemon*>::iterator, bool> findPokemon(string aPokeName, vector<Pokemon*> aPokeList)
{
    strToUpper(aPokeName);
    bool isFind = false;
    vector<Pokemon*>::iterator it, it2;
    for (it=aPokeList.begin(); (it != aPokeList.end()) && !(isFind); it++ )
    {
        if ((*it)->getItsName() == aPokeName)
        {
            isFind = true;
            it2 = it;
        }
    }
    if ((it == aPokeList.end()) && !isFind)
        cout << "This Pokemon do not exist !\n\n";
    return make_tuple(it2, isFind);
}

