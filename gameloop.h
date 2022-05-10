#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "trainer.h"

Trainer *bootMenu();

Pokemon* battleTurn(Trainer *aTrainer);

void battleMenu(Trainer *aTrainer);

void losingTrainer(Trainer *aTrainer, Trainer *aTrainer2);

void firstPokeToAttack(Pokemon *aPoke, Pokemon *aPoke2);

void hasFaintedPoke(Pokemon *aPoke, Trainer *aTrainer);

void clearScreen();
#endif // GAMELOOP_H
