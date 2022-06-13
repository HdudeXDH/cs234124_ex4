//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_PITFALL_H
#define CS234124_EX4_PITFALL_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int PITFALL_DMG = 10;

class Pitfall : public Card {
public:

    void applyEncounter(Player& player) const override;



    Pitfall(const std::string& name);

    Pitfall(const Pitfall&) = default;
    ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& other) = default;


private:
};


#endif //CS234124_EX4_PITFALL_H
