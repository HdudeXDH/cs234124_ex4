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

static const int GOBLIN_FORCE = 6;
static const int GOBLIN_HPLOSS = 10;
static const int GOBLIN_COINS = 2;



class Goblin : public Battlecards {
public:

    Goblin();
    virtual std::string getName() const override;
    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;



};



#endif //CS234124_EX4_GOBLIN_H
