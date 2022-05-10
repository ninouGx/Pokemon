#include "ai.h"

void AI::setItsOpponent(Trainer *newItsOpponent)
{
    itsOpponent = newItsOpponent;
}

Trainer *AI::getItsOpponent() const
{
    return itsOpponent;
}

AI::AI(const string &itsName) : Trainer(itsName)
{
    int indexChoosePoke;
    for(int i=0; i<6; i++)
    {
        do
        {
            indexChoosePoke = rand()%POKEDEXSIZE;
        }while(!canAddPokemon(totalPokeList[indexChoosePoke]->getItsName()));

        addPokemon(totalPokeList[indexChoosePoke]->copyPokemon());
    }
    itsActivePokemon = itsPokemonTeam->front();
}

void AI::AIattack()
{
    int aTotalDamage;
    Type aTempType;
    float effectiveness;
    string effectivSpeach;

    Pokemon *attacker = getItsActivePokemon(), *defender = itsOpponent->getItsActivePokemon();

    aTempType = bestMove(attacker);

    effectiveness = attacker->typeTable(aTempType, defender->getItsType(), defender->getItsType2());

    aTotalDamage = (attacker->getItsCP() * attacker->getItsAttack() / defender->getItsDefense()) * effectiveness;

    defender->tank(aTotalDamage);

    if(effectiveness >= 2)
        effectivSpeach = "super effective";

    else if(effectiveness == 0)
        effectivSpeach = "not effective ";

    else if(effectiveness == 1)
        effectivSpeach = "effective";

    else
        effectivSpeach = "not very effective";

    cout << attacker->getItsName() << " deal "  << aTotalDamage << " " << typeToStr(aTempType) << " damage to " << defender->getItsName() << "\tHP: " << defender->getItsHP() << "/" << defender->getItsTotalHP() << endl
             << "It's " << effectivSpeach << endl;

    if(!defender->isAlive())
    {
        cout << "\nThe foe's " << defender->getItsName() << " fainted! \n";
    }
}

Type AI::bestMove(Pokemon *attackPokemon)
{
    Type bestType;
    if (attackPokemon->getItsType() == attackPokemon->getItsType2()){
        bestType = attackPokemon->getItsType();
    }
    else{
        if(attackPokemon->typeTable(attackPokemon->getItsType(),
                                    itsOpponent->getItsActivePokemon()->getItsType(),
                                    itsOpponent->getItsActivePokemon()->getItsType2() )
                > attackPokemon->typeTable(attackPokemon->getItsType2(),
                                           itsOpponent->getItsActivePokemon()->getItsType(),
                                           itsOpponent->getItsActivePokemon()->getItsType2())){
            bestType = attackPokemon->getItsType();
        }
        else{
            bestType = attackPokemon->getItsType2();
        }

    }
    return bestType;
}

Pokemon *AI::bestPokemon()
{
    Pokemon *bestOne = nullptr;
    for (Pokemon *aPoke : *itsPokemonTeam)
    {
        if(aPoke->isAlive() && (bestOne == nullptr)){
            bestOne = aPoke;
        }
    }
    for(Pokemon *aPoke : *itsPokemonTeam)
    {
        if(aPoke->isAlive()){
            if( aPoke->typeTable(bestMove(aPoke), itsOpponent->getItsActivePokemon()->getItsType(), itsOpponent->getItsActivePokemon()->getItsType2()) >
                    bestOne->typeTable(bestMove(bestOne),itsOpponent->getItsActivePokemon()->getItsType(), itsOpponent->getItsActivePokemon()->getItsType2())){
                bestOne = aPoke;
            }
        }

    }
    return bestOne;
}











