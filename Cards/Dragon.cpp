//
// Created by ofir1 on 11-Jun-22.
//


#include "Dragon.h"
Dragon::Dragon(const string& name):
        Battlecards(name,DRAGON_FORCE,DRAGON_HPLOSS,DRAGON_COINS)
{}

void Dragon::applyEncounter(Player& player) const{

}
//todo: how to print?
void Dragon::printInfo() const{
    printCardDetails(std::cout,);
}