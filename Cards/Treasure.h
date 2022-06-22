
#ifndef CS234124_EX4_TREASURE_H
#define CS234124_EX4_TREASURE_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int TREASURE_COINS = 10;

class Treasure : public Card {
public:

void applyEncounter(Player& player) const override;

Treasure();
    virtual std::string getName() const override;
Treasure(const Treasure&) = default;
~Treasure() = default;
Treasure& operator=(const Treasure& other) = default;


};


#endif //CS234124_EX4_TREASURE_H
