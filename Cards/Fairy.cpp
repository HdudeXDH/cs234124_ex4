//
// Created by ofir1 on 11-Jun-22.
//

#include "Fairy.h"
Fairy::Fairy(const string& name):
Card(name)
{}


void Fairy::applyEncounter(Player& player) const{
    bool isWizard = player.type()=="Wizard";
    if(isWizard)
        player.heal(FAIRY_HEAL);
    printFairyMessage(isWizard);
}
//todo: check if its ok, there might be a problem implementing << as a member
ostream& Fairy::operator<<(ostream& os) const{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
    return os;
}


