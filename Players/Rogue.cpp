
#include "Rogue.h"

Rogue::Rogue(const std::string name):
        Player(name){
}
void Rogue::addCoins(int amount){
    if (amount<0) {
        amount =0;
    }
    this->m_coins+=2*amount;
}
std::string Rogue::type() const{
    return "Rogue";
}
