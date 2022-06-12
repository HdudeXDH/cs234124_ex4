//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_DRAGON_H
#define CS234124_EX4_DRAGON_H


#include "Battlecards.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>
using std::string;

static const int DRAGON_FORCE = 25;
static const int DRAGON_HPLOSS = 0;
static const int DRAGON_COINS = 1000;


//todo: how to type it here
class Dragon : public Battlecards {
public:

    void applyEncounter(Player& player) const override;

    void printInfo() const override;

    Dragon(const string& name);

    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;


private:
};




#endif //CS234124_EX4_DRAGON_H
