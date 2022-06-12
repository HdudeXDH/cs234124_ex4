//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_VAMPIRE_H
#define CS234124_EX4_VAMPIRE_H


#include "Battlecards.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>
using std::string;

static const int VAMPIRE_FORCE = 10;
static const int VAMPIRE_HPLOSS = 10;
static const int VAMPIRE_COINS = 2;


//todo: how to type it here
class Vampire : public Battlecards {
public:

    void applyEncounter(Player& player) const override;

    void printInfo() const override;

    Vampire(const string& name);

    Vampire(const Dragon&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;


private:
};





#endif //CS234124_EX4_VAMPIRE_H
