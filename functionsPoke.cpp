#include "functionsPoke.h"





//to get the list of all the pokemon database
vector<Pokemon*> retrievePoke()
{

    vector<Pokemon*> pokeList;
    ifstream inPokeList("../../MiniProjNoms/pokeData/listFinalP.txt");
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

        #ifdef __APPLE__
            aName.pop_back();
        //conversion des types string en TYPE
            aType1.pop_back();
            aType2.pop_back();
        #endif

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

    inPokeList.close();

    return pokeList;
}




tuple<Pokemon *, bool> findPokemon(string aPokeName)
{
    tuple<Pokemon *, bool> finalTuple;
    bool isFind = false;
    strToUpper(aPokeName);

    auto wantedPoke = indexPoke.find(aPokeName);
    if(wantedPoke != indexPoke.end())
    {
        isFind = true;
        finalTuple = make_tuple(totalPokeList[wantedPoke->second-1], isFind);
        //print_pokemon(wantedPoke->second);
        //cin.ignore();
    }
    else
    {
        finalTuple = make_tuple(nullptr, isFind);
    }

    return finalTuple;




    /*
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
    return make_tuple(it2, isFind);*/

}



map<string, unsigned int> indexPokeList()
{
    int index = 1;
    map<string, unsigned int> aTempIndex;
    for (Pokemon *aPoke : totalPokeList)
    {
        aTempIndex.insert({aPoke->getItsName(),index});
        index++;
    }

    return aTempIndex;
}
