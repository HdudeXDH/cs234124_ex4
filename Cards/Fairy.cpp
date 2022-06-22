

#include "Fairy.h"
Fairy::Fairy():
Card() {}


void Fairy::applyEncounter(Player& player) const{
    bool isWizard = player.type()=="Wizard";
    if(isWizard)
        player.heal(FAIRY_HEAL);
    printFairyMessage(isWizard);
}

std::string Fairy::getName() const{
    return "Fairy";
}


