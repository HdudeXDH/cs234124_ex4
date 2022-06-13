//
// Created by ofir1 on 11-Jun-22.
//


#include "Pitfall.h"
Pitfall::Pitfall():
        Card()
{}


void Pitfall::applyEncounter(Player& player) const{
    bool isRogue = player.type()=="Rogue";
    if(!isRogue)
        player.damage(PITFALL_DMG);
    printPitfallMessage(isRogue);
}

std::string Pitfall::getName() const{
    return "Pitfall";
}