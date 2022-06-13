//
// Created by ofir1 on 12-Jun-22.
//

#ifndef CS234124_EX4_MERCHANT_H
#define CS234124_EX4_MERCHANT_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int LEAVE = 0;

static const int BUY_HP = 1;
static const int HP = 1;
static const int HP_COST = 5;

static const int BUY_FORCE = 2;
static const int FORCE = 1;
static const int FORCE_COST = 10;

class Merchant : public Card {
public:

    void applyEncounter(Player& player) const override;


    Merchant();
    virtual std::string getName() const override;
    Merchant(const Merchant&) = default;
    ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;


private:
};


#endif //CS234124_EX4_MERCHANT_H
