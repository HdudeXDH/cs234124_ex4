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

void Battlecards::printInfo()  {

}