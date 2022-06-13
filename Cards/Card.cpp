//
// Created by User on 6/11/2022.
//

#include "Card.h"


Card::Card(const std::string& name):
m_name(name){
}

void Card::printCardHelp(ostream &os) const {
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(ostream& os,const Card& card){
    card.printCardHelp(os);
    return os;
}