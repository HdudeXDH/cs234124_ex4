//
// Created by ofir1 on 11-Jun-22.
//

#include "Battlecards.h"

static const int VAMPIRE_BUFF_DMG = -1;

Battlecards::Battlecards(int force,int hpLoss,int coins):
Card(),
m_force(force),
m_hpLoss(hpLoss),
m_coins(coins)
{}

void Battlecards::applyEncounter(Player &player) const {
    bool isVampire = this->getName() == "Vampire";
    if(player.getAttackStrength()<this->m_force) {
        player.damage(this->m_hpLoss);
        if(isVampire) player.buff(VAMPIRE_BUFF_DMG);
        printLossBattle(player.getName(), this->getName());
    }
    else {
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->getName());
    }
}


void Battlecards::printCardHelp(ostream& os) const{
    bool isDragon = this->getName() == "Dragon";
    printCardDetails(os,this->getName());
    printMonsterDetails(os,this->m_force,this->m_hpLoss,this->m_coins,isDragon);
    printEndOfCardDetails(os);
}

