//
// Created by ofir1 on 11-Jun-22.
//


#include "Barfight.h"
Barfight::Barfight(const std::string& name):
        Card(name)
{}


void Barfight::applyEncounter(Player& player) const{
    bool isFighter = player.type()=="Fighter";
    if(!isFighter)
        player.damage(BARFIGHT_DMG);
}

ostream& Barfight::operator<<(ostream& os) const{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
    return os;
}
