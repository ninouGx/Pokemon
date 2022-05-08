#include "ai.h"

void AI::setItsOpponent(Trainer *newItsOpponent)
{
    itsOpponent = newItsOpponent;
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
    Pokemon *bestOne = itsPokemonTeam->front();
    for(Pokemon *aPoke : *itsPokemonTeam)
    {
        if( aPoke->typeTable(bestMove(aPoke), itsOpponent->getItsActivePokemon()->getItsType(), itsOpponent->getItsActivePokemon()->getItsType2()) >
                bestOne->typeTable(bestMove(bestOne),itsOpponent->getItsActivePokemon()->getItsType(), itsOpponent->getItsActivePokemon()->getItsType2())){
            bestOne = aPoke;
        }
    }
    return bestOne;
}











