//
// Created by ofir1 on 11-Jun-22.
//


#include "Dragon.h"
Dragon::Dragon():
        Battlecards(DRAGON_FORCE,DRAGON_HPLOSS,DRAGON_COINS)
{}
std::string Dragon::getName() const{
    return "Dragon";
}
