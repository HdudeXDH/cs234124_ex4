
#include "Dragon.h"
Dragon::Dragon():
        Battlecards(DRAGON_FORCE,DRAGON_HPLOSS,DRAGON_COINS)
{}
std::string Dragon::getName() const{
    return "Dragon";
}
