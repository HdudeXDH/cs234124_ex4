
#include "Vampire.h"
Vampire::Vampire():
        Battlecards(VAMPIRE_FORCE,VAMPIRE_HPLOSS,VAMPIRE_COINS)
{}

std::string Vampire::getName() const{
    return "Vampire";
}