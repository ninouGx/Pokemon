#ifndef AI_H
#define AI_H

#include <algorithm>
#include "trainer.h"

class AI : public Trainer
{
private:
    Trainer *itsOpponent = nullptr;
public:
    AI(const string &itsName);
    void AIattack(); //test son/ses type d'attaque et genre 1 tour /2 test pour changer de pokemon
    Type bestMove(Pokemon *attackPokemon);  //return the best multiplier of the pokemon over the opponent pokemon
    Pokemon* bestPokemon(); //si un pokemon qui permet de faire plus de degats sinon un pokemon qui peut mieux tanker et pas de changement sinon

    void setItsOpponent(Trainer *newItsOpponent);
};

#endif // AI_H
