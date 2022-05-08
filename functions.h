#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
#include <utility>

using namespace std;

#define POKEDEXSIZE 151
#define TEAMSIZE 6

enum Type{WATER=0, FIRE=1, GRASS=2, ELECTRIC=3,
          NORMAL=4, FIGHTING=5, FLYING=6, POISON=7,
          GROUND=8, ROCK=9, BUG=10, GHOST=11,
          STEEL=12, PSYCHIC=13, ICE=14, DRAGON=15,
          DARK=16, FAIRY=17, NONE=18};

void strToUpper(string &aString);

string typeToStr(Type aType);

Type strToType(string aStrType);

#endif // FUNCTIONS_H
