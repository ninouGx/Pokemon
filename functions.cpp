#include "functions.h"

void strToUpper(string &aString)
{
    for (unsigned int i = 0; i < aString.length(); i++)
            aString[i] = toupper(aString[i]);
}


string typeToStr(Type aType)
{
    string finalType;
    switch(aType)
    {
        case WATER : finalType="WATER";
            break;
        case FIRE : finalType = "FIRE";
            break;
        case GRASS : finalType = "GRASS";
            break;
        case ELECTRIC : finalType = "ELECTRIC";
            break;
        case NORMAL : finalType = "NORMAL";
            break;
        case FIGHTING : finalType = "FIGHTING";
            break;
        case FLYING : finalType = "FLYING";
            break;
        case POISON : finalType = "POISON";
            break;
        case GROUND : finalType = "GROUND";
            break;
        case ROCK : finalType = "ROCK";
            break;
        case BUG : finalType = "BUG";
            break;
        case GHOST : finalType = "GHOST";
            break;
        case STEEL : finalType = "STEEL";
            break;
        case PSYCHIC : finalType = "PSYCHIC";
            break;
        case ICE : finalType = "ICE";
            break;
        case DRAGON : finalType = "DRAGON";
            break;
        case DARK : finalType = "DARK";
            break;
        case FAIRY : finalType = "FAIRY";
            break;
        default: finalType = "";
    }
    return finalType;
}

Type strToType(string aStrType)
{
    Type finalType;

    if ( aStrType == "WATER")
        finalType=WATER;

    else if ( aStrType == "FIRE")
        finalType = FIRE;

    else if ( aStrType == "GRASS")
        finalType = GRASS;

    else if ( aStrType == "ELECTRIC")
        finalType = ELECTRIC;

    else if ( aStrType == "NORMAL")
        finalType = NORMAL;

    else if ( aStrType == "FIGHTING")
        finalType = FIGHTING;

    else if ( aStrType == "FLYING")
        finalType = FLYING;

    else if ( aStrType == "POISON")
        finalType = POISON;

    else if ( aStrType == "GROUND")
        finalType = GROUND;

    else if ( aStrType == "ROCK")
        finalType = ROCK;

    else if ( aStrType == "BUG")
        finalType = BUG;

    else if ( aStrType == "GHOST")
        finalType = GHOST;

    else if ( aStrType == "STEEL")
        finalType = STEEL;

    else if ( aStrType == "PSYCHIC")
        finalType = PSYCHIC;

    else if ( aStrType == "ICE")
        finalType = ICE;

    else if ( aStrType == "DRAGON")
        finalType = DRAGON;

    else if ( aStrType == "DARK")
        finalType = DARK;

    else if ( aStrType == "FAIRY")
        finalType = FAIRY;
    else
        finalType = NONE;



    return finalType;
}


void nbBlank(int nb)
{
    for(int i=0; i<nb; i++)
        cout << " ";
}
