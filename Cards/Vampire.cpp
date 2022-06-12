//
// Created by ofir1 on 11-Jun-22.
//


#include "Vampire.h"
Vampire::Vampire(const string& name):
        Battlecards(name,VAMPIRE_FORCE,VAMPIRE_HPLOSS,VAMPIRE_COINS)
{}

void Vampire::applyEncounter(Player& player) const{

}
//todo: how to print?
void Vampire::printInfo() const{
    printCardDetails(std::cout,);
}