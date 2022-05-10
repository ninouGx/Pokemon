#include "pokemon.h"

bool Pokemon::isAlive()
{
    return itsHP;
}

float Pokemon::getItsSpeed() const
{
    return itsSpeed;
}

Type Pokemon::getItsType() const
{
    return itsType1;
}


void Pokemon::tank(int aNbDamage)
{
    itsHP -= aNbDamage;
    if (itsHP<0)
        itsHP=0;
}

Type Pokemon::getItsType2() const
{
    return itsType2;
}

const string &Pokemon::getItsName() const
{
    return itsName;
}

int Pokemon::getItsHP() const
{
    return itsHP;
}

int Pokemon::getItsTotalHP() const
{
    return itsTotalHP;
}

void Pokemon::healPoke()
{
    setItsHP(itsTotalHP);
}

Pokemon* Pokemon::copyPokemon()
{
    Pokemon *aNewPoke = new Pokemon(*this);
    return aNewPoke;
}

void Pokemon::setItsHP(int newItsHP)
{
    itsHP = newItsHP;
}

Pokemon::Pokemon(const string &itsName, float itsSize, float itsWeight, int itsHP, int itsAttack, int itsDefense, float itsSpeed, Type itsType1, Type itsType2, int itsCP) : itsName(itsName),
    itsSize(itsSize),
    itsWeight(itsWeight),
    itsCP(itsCP),
    itsHP(itsHP),
    itsAttack(itsAttack),
    itsDefense(itsDefense),
    itsSpeed(itsSpeed),
    itsType1(itsType1),
    itsType2(itsType2)
{
    itsTotalHP = itsHP;
}


//(itsCP * itsAttack / aPoke.itsDefense)  * Faiblesse
                                          //resitance
void Pokemon::attack(Pokemon *aPokemon)
{
    Type aTempType;
    string aTempStr, effectivSpeach;
    int aTotalDamage,  indexError = 0;
    float effectiveness;
    // si un seul type alors pas de demande, si deux types faire un choix entre les deux types
    if (itsType2 != itsType1)
    {
        do
        {
            if (indexError > 0)
                cout << "Invalid Move ! \n\n";
            cout << "Which Move ? " << endl
                << "[" << typeToStr(itsType1) << "] or [" << typeToStr(itsType2) << "]\n";

            getline(cin, aTempStr);
            strToUpper(aTempStr);
            indexError++;

        }while( (strToType(aTempStr) != itsType1) && (strToType(aTempStr) != itsType2) );

        aTempType = strToType(aTempStr);
    }
    else
    {
        aTempType = itsType1;
    }
    cout << "\n";
    //attack formula :     //(itsCP * itsAttack / opposite pokemon defence)  * effectiveness

    effectiveness = typeTable(aTempType, aPokemon->itsType1, aPokemon->itsType2);

    aTotalDamage = (itsCP * itsAttack / aPokemon->itsDefense) * effectiveness;

    aPokemon->tank(aTotalDamage);

    if(effectiveness >= 2)
        effectivSpeach = "super effective";

    else if(effectiveness == 0)
        effectivSpeach = "not effective ";

    else if(effectiveness == 1)
        effectivSpeach = "effective";

    else
        effectivSpeach = "not very effective";

    cout << itsName << " deal "  << aTotalDamage << " " << typeToStr(aTempType) << " damage to " << aPokemon->getItsName() << "\tHP: " << aPokemon->getItsHP() << "/" << aPokemon->getItsTotalHP() << endl
             << "It's " << effectivSpeach << endl;

    if(!aPokemon->isAlive())
    {
        cout << "\nThe foe's " << aPokemon->getItsName() << " fainted! \n";
    }

}

float Pokemon::typeTable(Type attackType, Type defType1, Type defType2)
{
    float factor = 1.0 ; // Initialisation du multiplicateur de dégâts
        switch (attackType)    // Gestion des cas en fonction du type de la capacité
        {
        case NORMAL :
            if (defType1 == GHOST or defType2 == GHOST)  // Cas immunité
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == STEEL or defType1 == ROCK) //
                {
                    factor *= 0.5 ;
                }
                if (defType1 != defType2 and (defType2 == STEEL or defType2 == ROCK))
                {
                    factor *= 0.5 ;
                }
            }
            break ;


        case BUG :
            if (defType1 == FIRE  or defType1 == POISON or defType1 == GHOST or defType1 == FIGHTING or defType1 == STEEL or defType1 == FLYING or defType1 == FAIRY )
            {
                factor *= 0.5 ;
            }
            else if (defType1 == GRASS or defType1 == PSYCHIC  or defType1 == DARK)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == FIRE  or defType2 == POISON or defType2 == GHOST or defType2 == FIGHTING or defType2 == STEEL or defType2 == FLYING or defType2 == FAIRY )
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == GRASS or defType2 == PSYCHIC  or defType2 == DARK)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case GRASS :
            if (defType1 == BUG or defType1 == GRASS or defType1 == FIRE or defType1 == POISON or defType1 == STEEL or defType1 == DRAGON or defType1 == FLYING)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == WATER or defType1 == ROCK or defType1 == GROUND)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == BUG or defType2 == GRASS or defType2 == FIRE or defType2 == POISON or defType2 == STEEL or defType2 == DRAGON or defType2 == FLYING)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == WATER or defType2 == ROCK or defType2 == GROUND)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case FIRE :
            if (defType1 == FIRE or defType1 == WATER or defType1 == ROCK or defType1 == DRAGON)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == BUG or defType1 == GRASS or defType1 == ICE or defType1 == STEEL)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == FIRE or defType2 == WATER or defType2 == ROCK or defType2 == DRAGON)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == BUG or defType2 == GRASS or defType2 == ICE or defType2 == STEEL)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case WATER :
            if (defType1 == GRASS or defType1 == WATER or defType1 == DRAGON)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == FIRE or defType1 == ROCK or defType1 == GROUND)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == GRASS or defType2 == WATER or defType2 == DRAGON)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == FIRE or defType2 == ROCK or defType2 == GROUND)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case ICE :
            if (defType1 == FIRE or defType1 == ICE or defType1 == WATER or defType1 == STEEL)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == GRASS or defType1 == GROUND or defType1 == FLYING or defType1 == DRAGON)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == FIRE or defType2 == ICE or defType2 == WATER or defType2 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == GRASS or defType2 == GROUND or defType2 == FLYING or defType2 == DRAGON)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case ELECTRIC :
            if (defType1 == GROUND or defType2 == GROUND)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == GRASS or defType1 == ELECTRIC or defType1 == DRAGON)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == WATER or defType1 == FLYING)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == GRASS or defType2 == ELECTRIC or defType2 == DRAGON)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == WATER or defType2 == FLYING)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case POISON :
            if (defType1 == STEEL or defType2 == STEEL)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == POISON or defType1 == GHOST or defType1 == ROCK or defType1 == GROUND)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == GRASS or defType1 == FAIRY)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == POISON or defType2 == GHOST or defType2 == ROCK or defType2 == GROUND)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == GRASS or defType2 == FAIRY)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case PSYCHIC :
            if (defType1 == DARK or defType2 == DARK)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == PSYCHIC or defType1 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == FIGHTING or defType1 == POISON)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == PSYCHIC or defType2 == STEEL)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == FIGHTING or defType2 == POISON)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case GHOST :
            if (defType1 == NORMAL or defType2 == NORMAL)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == DARK)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == GHOST or defType1 == PSYCHIC)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == DARK)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == GHOST or defType2 == PSYCHIC)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case GROUND :
            if (defType1 == FLYING or defType2 == FLYING)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == BUG or defType1 == GRASS)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == ELECTRIC or defType1 == FIRE or defType1 == POISON or defType1 == ROCK or defType1 == STEEL)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == BUG or defType2 == GRASS)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == ELECTRIC or defType2 == FIRE or defType2 == POISON or defType2 == ROCK or defType2 == STEEL)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case ROCK :
            if (defType1 == GROUND or defType1 == FIGHTING or defType1 == STEEL)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == BUG or defType1 == FIRE or defType1 == ICE or defType1 == FLYING)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == GROUND or defType2 == FIGHTING or defType2 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == BUG or defType2 == FIRE or defType2 == ICE or defType2 == FLYING)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case FIGHTING :
            if (defType1 == GHOST or defType2 == GHOST)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == BUG or defType1 == PSYCHIC or defType1 == POISON or defType1 == FLYING or defType1 == FAIRY)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == ICE or defType1 == ROCK or defType1 == DARK or defType1 == STEEL or defType1 == NORMAL)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == BUG or defType2 == PSYCHIC or defType2 == POISON or defType2 == FLYING or defType2 == FAIRY)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == ICE or defType2 == ROCK or defType2 == DARK or defType2 == STEEL or defType2 == NORMAL)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case DARK :
            if (defType1 == FIGHTING or defType1 == DARK or defType1 == FAIRY)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == PSYCHIC or defType1 == GHOST)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == FIGHTING or defType2 == DARK or defType2 == FAIRY)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == PSYCHIC or defType2 == GHOST)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case STEEL :
            if (defType1 == FIRE or defType1 == WATER or defType1 == ELECTRIC or defType1 == STEEL)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == ICE or defType1 == ROCK or defType1 == FAIRY)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == FIRE or defType2 == WATER or defType2 == ELECTRIC or defType2 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == ICE or defType2 == ROCK or defType2 == FAIRY)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case DRAGON :
            if (defType1 == FAIRY or defType2 == FAIRY)
            {
                factor = 0.0 ;
            }
            else
            {
                if (defType1 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType1 == DRAGON)
                {
                    factor *= 2.0 ;
                }
                if (defType1 != defType2)
                {
                    if (defType2 == STEEL)
                    {
                        factor *= 0.5 ;
                    }
                    else if (defType2 == DRAGON)
                    {
                        factor *= 2.0 ;
                    }
                }
            }
            break ;


        case FLYING :
            if (defType1 == ELECTRIC or defType1 == ROCK or defType1 == STEEL)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == BUG or defType1 == GRASS or defType1 == FIGHTING)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == ELECTRIC or defType2 == ROCK or defType2 == STEEL)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == BUG or defType2 == GRASS or defType2 == FIGHTING)
                {
                    factor *= 2.0 ;
                }
            }
            break ;


        case FAIRY :
            if (defType1 == STEEL or defType1 == POISON or defType1 == FIRE)
            {
                factor *= 0.5 ;
            }
            else if (defType1 == DRAGON or defType1 == FIGHTING or defType1 == DARK)
            {
                factor *= 2.0 ;
            }
            if (defType1 != defType2)
            {
                if (defType2 == STEEL or defType2 == POISON or defType2 == FIRE)
                {
                    factor *= 0.5 ;
                }
                else if (defType2 == DRAGON or defType2 == FIGHTING or defType2 == DARK)
                {
                    factor *= 2.0 ;
                }
            }
            break ;
        default:;
        }
        return factor;
}































