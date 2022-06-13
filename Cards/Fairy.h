//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_FAIRY_H
#define CS234124_EX4_FAIRY_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int FAIRY_HEAL = 10;

class Fairy : public Card {
public:

    void applyEncounter(Player& player) const override;


    Fairy(const std::string& name);

    Fairy(const Fairy&) = default;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;


private:
};




#endif //CS234124_EX4_FAIRY_H
