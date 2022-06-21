//
// Created by ofir1 on 21-Jun-22.
//

#include "Gang.h"

Gang::Gang(int force,int hpLoss,int coins):
        Card(),

{}

void Gang::applyEncounter(Player &player) const {
    int index = 0;
    for (std::vector<std::unique_ptr<Gang>>::iterator g = gang.begin(); g != gang.end(); ++g, ++index){

    }


void Gang::printCardHelp(ostream& os) const{
    bool isDragon = this->getName() == "Dragon";
    printCardDetails(os,this->getName());
    printMonsterDetails(os,this->m_force,this->m_hpLoss,this->m_coins,isDragon);
    printEndOfCardDetails(os);
}

