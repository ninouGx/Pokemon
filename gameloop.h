#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "ai.h"
#include "trainer.h"
int versusMenu();

Trainer *bootMenu();

void battleMenu(Trainer *aTrainer);

Pokemon* battleTurn(Trainer *aTrainer);

void battleSequence(Trainer *aTrainer, Trainer *aTrainer2);
void battleSequence1AI(Trainer *aTrainer, AI *aTrainer2);
void battleSequence2AI(AI *aTrainer, AI *aTrainer2);


void losingTrainer(Trainer *aTrainer, Trainer *aTrainer2);

void firstPokeToAttack(Trainer *aTrainer, Trainer *aTrainer2);
void firstPokeToAttack1AI(Trainer *aTrainer, AI *aTrainer2);
void firstPokeToAttack1AI(AI *aTrainer, AI *aTrainer2);

void displayPokemonVSPokemon(Pokemon *aPoke, Pokemon *aPoke2);

void hasFaintedPoke(Pokemon *aPoke, Trainer *aTrainer);



void clearScreen();
#endif // GAMELOOP_H
