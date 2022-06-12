//
// Created by ofir1 on 11-Jun-22.
//

#include "Treasure.h"
Treasure::Treasure(const string& name):
Card(name)
{}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}

ostream& Treasure::operator<<(ostream& os) const{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
    return os;
}