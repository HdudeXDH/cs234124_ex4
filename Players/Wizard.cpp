//
// Created by ofir1 on 11-Jun-22.
//
#include "Wizard.h"

void Wizard::heal(int points){
    *this->m_hp += 2*points;
};

std::string Wizard::type(){
    return "Wizard";
}