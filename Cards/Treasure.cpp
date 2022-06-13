//
// Created by ofir1 on 11-Jun-22.
//

#include "Treasure.h"
Treasure::Treasure():
Card()
{}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}

std::string Treasure::getName() const{
    return "Treasure";
}