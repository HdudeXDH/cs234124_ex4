#include "Card.h"




void Card::printCardHelp(ostream &os) const {
    printCardDetails(os,this->getName());
    printEndOfCardDetails(os);
}

std::ostream& operator<<(ostream& os,const Card& card){
    card.printCardHelp(os);
    return os;
}

