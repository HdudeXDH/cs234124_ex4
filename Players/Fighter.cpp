//
// Created by ofir1 on 11-Jun-22.
//

#include "Fighter.h"
Fighter::Fighter(const std::string name):
        Player(name){
}
int Fighter::getAttackStrength() {
    return(this->m_level+2*this->m_force);
}
std::string Fighter::type() const{
    return "Fighter";
}