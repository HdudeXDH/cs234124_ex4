//
// Created by ofir1 on 11-Jun-22.
//


#include "Goblin.h"
Goblin::Goblin(const string& name):
        Battlecards(name,GOBLIN_FORCE,GOBLIN_HPLOSS,GOBLIN_COINS)
{}

void Goblin::applyEncounter(Player& player) const{

}
//todo: how to print?
void Goblin::printInfo() const{
    printCardDetails(std::cout,);
}