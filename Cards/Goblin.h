//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_GOBLIN_H
#define CS234124_EX4_GOBLIN_H


#include "Battlecards.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>
using std::string;

static const int GOBLIN_FORCE = 6;
static const int GOBLIN_HPLOSS = 10;
static const int GOBLIN_COINS = 2;


//todo: how to type it here
class Goblin : public Battlecards {
public:

    void applyEncounter(Player& player) const override;

    void printInfo() const override;

    Goblin(const string& name);

    Goblin(const Dragon&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;


private:
};



#endif //CS234124_EX4_GOBLIN_H
