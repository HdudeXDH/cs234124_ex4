//
// Created by ofir1 on 11-Jun-22.
//


#include "Vampire.h"
Vampire::Vampire():
        Battlecards(VAMPIRE_FORCE,VAMPIRE_HPLOSS,VAMPIRE_COINS)
{}

std::string Card::getName() const{
    return "Vampire";
}