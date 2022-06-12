//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_TREASURE_H
#define CS234124_EX4_TREASURE_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>
using std::string;

static const int TREASURE_COINS = 10;

class Treasure : public Card {
public:

void applyEncounter(Player& player) const override;

    ostream& operator<<(ostream& os) const override;

Treasure(const string& name);

Treasure(const Treasure&) = default;
~Treasure() = default;
Treasure& operator=(const Treasure& other) = default;


private:


};


#endif //CS234124_EX4_TREASURE_H
