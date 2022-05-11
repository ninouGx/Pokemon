#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string trType(string aType)
{
    string finalType;

    if ( aType == "Eau")
        finalType="WATER";

    else if ( aType == "Feu")
        finalType = "FIRE";

    else if ( aType == "Plante")
        finalType = "GRASS";

    else if ( aType == "Électrik")
        finalType = "ELECTRIC";

    else if ( aType == "Normal")
        finalType = "NORMAL";

    else if ( aType == "Combat")
        finalType = "FIGHTING";

    else if ( aType == "Vol")
        finalType = "FLYING";

    else if ( aType == "Poison")
        finalType = "POISON";

    else if ( aType == "Sol")
        finalType = "GROUND";

    else if ( aType == "Roche")
        finalType = "ROCK";

    else if ( aType == "Insecte")
        finalType = "BUG";

    else if ( aType == "Spectre")
        finalType = "GHOST";

    else if ( aType == "Acier")
        finalType = "STEEL";

    else if ( aType == "Psy")
        finalType = "PSYCHIC";

    else if ( aType == "Glace")
        finalType = "ICE";

    else if ( aType == "Dragon")
        finalType = "DRAGON";

    else if ( aType == "Ténèbre")
        finalType = "DARK";

    else if ( aType == "Fée")
        finalType = "FAIRY";

    return finalType;
}

int main()
{
    string tempPoke, tempStat, tempType;
    ifstream inStats("../fichierModifPoke/listePStats.txt"),  //pokepedia
            inPokeNames("../fichierModifPoke/pokeENNames.txt"),
            inPokeType("../fichierModifPoke/pokemonWithTypes.txt"); //https://www.pokemontrash.com/pokedex/liste-pokemon.php#gen1

    ofstream outputFile("../fichierModifPoke/listFinalP.txt");
    do
    {

        //1er fichier pour les noms
        getline(inPokeNames, tempPoke);//Recupere les noms dans le premier fichier
        outputFile << tempPoke << "\n";


        //2eme fichier pour les stats
        for(int i = 0; i<3; i++) //vire les info de numeros et de noms(francais pas interessantes)
        {
            getline(inStats, tempStat, '\t');
            //cout << tempStat << "\n";
        }
        for(int i = 0; i<5; i++) //recupere les 5 stats
        {
            getline(inStats, tempStat, '\t');
            outputFile << tempStat << "\n";
        }

                //va jusqu'au bout de la ligne
        getline(inStats, tempStat, '\n');

        //3eme fichier pour les types
        for(int i = 0; i<4; i++) //vire les infos jusqu'au types
        {
            getline(inPokeType, tempType, '\t');
        }

        //1er type
        getline(inPokeType, tempType, '\t');
        if ( tempType.compare(tempType.size()-1,1,"\n") == 0)
            tempType.erase(tempType.end()-1);
        tempType = trType(tempType);

        outputFile << tempType;
        if (!inStats.eof()) //retour à la ligne si la fin du fichier n'est pas atteinte
            outputFile << "\n";

        //que si 2eme type present
        getline(inPokeType, tempType, '\n');
        if(tempType != "")
        {
            tempType.erase(0,2);//enleve le "/ " du debut
            tempType.erase(tempType.end()-1);//enleve le "\t" de la fin
            tempType = trType(tempType);
            outputFile << tempType;
            if (!inStats.eof())
                outputFile << "\n" << endl;
        }
        else
            if (!inStats.eof())
                outputFile << "\n";


    }while(!inStats.eof());

    inStats.close();
    inPokeNames.close();
    outputFile.close();
    return 0;
}
