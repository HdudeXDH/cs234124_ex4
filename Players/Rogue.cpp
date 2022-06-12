//
// Created by ofir1 on 11-Jun-22.
//

#include "Rogue.h"
void Rogue::addCoins(int amount){
    if (amount<0) {
        amount =0;
    }
    this->m_coins+=2*amount;
};
std::string Rogue::type(){
    return "Rogue";
};
//Rogue::~Rogue() noexcept {
//
//}