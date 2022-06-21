//
// Created by ofir1 on 11-Jun-22.
//


#include "Barfight.h"
Barfight::Barfight():
Card()
{}


void Barfight::applyEncounter(Player& player) const {
    bool isFighter = player.type() == "Fighter";
    if (!isFighter) {
        player.damage(BARFIGHT_DMG);

    }
    printBarfightMessage(isFighter);

}

std::string Barfight::getName() const{
    return "Barfight";
}