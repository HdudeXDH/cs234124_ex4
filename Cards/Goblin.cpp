//
// Created by ofir1 on 11-Jun-22.
//


#include "Goblin.h"
Goblin::Goblin():
        Battlecards(GOBLIN_FORCE,GOBLIN_HPLOSS,GOBLIN_COINS)
{}

std::string Goblin::getName() const{
    return "Goblin";
}
