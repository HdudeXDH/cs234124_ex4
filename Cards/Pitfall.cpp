//
// Created by ofir1 on 11-Jun-22.
//


#include "Pitfall.h"
Pitfall::Pitfall(const string& name):
        Card(name)
{}


void Pitfall::applyEncounter(Player& player) const{
    bool isRogue = player.type()=="Rogue";
    if(!isRogue)
        player.damage(PITFALL_DMG);
    printPitfallMessage(isRogue);
}

ostream& Pitfall::operator<<(ostream& os) const{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
    return os;
}