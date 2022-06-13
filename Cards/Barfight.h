//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_BARFIGHT_H
#define CS234124_EX4_BARFIGHT_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int BARFIGHT_DMG = 10;

class Barfight : public Card {
public:

    Barfight();
    virtual std::string getName() const override;
    void applyEncounter(Player& player) const override;


    Barfight(const std::string& name);

    Barfight(const Barfight&) = default;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& other) = default;


private:
};




#endif //CS234124_EX4_BARFIGHT_H
