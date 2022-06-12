//
// Created by ofir1 on 11-Jun-22.
//

#include "Battlecards.h"

Battlecards::Battlecards(const string& name,int force,int hpLoss,int coins):
Card(name),
m_force(force),
m_hpLoss(hpLoss),
m_coins(coins)
{}

void Battlecards::applyEncounter(Player &player) const {
    if(player.getAttackStrength()<this->m_force) {
        player.damage(this->m_hpLoss);
        printLossBattle(player.getName(), this->m_name);
    }
    else {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
}


ostream& Battlecards::operator<<(ostream& os) const{
    bool isDragon = this->m_name == "Dragon";
    printCardDetails(os,this->m_name);
    printMonsterDetails(os,this->m_force,this->m_hpLoss,this->m_coins,isDragon);
    printEndOfCardDetails(os);
    return os;
}

