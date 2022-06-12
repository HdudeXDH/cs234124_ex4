//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_BATTLECARDS_H
#define CS234124_EX4_BATTLECARDS_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>
using std::string;


class Battlecards : public Card {
public:

    Battlecards(const string& name,int force,int hpLoss,int coins);
    Battlecards(const Battlecards &)=default;
    ~Battlecards() = default;
    Battlecards& operator=(const Battlecards &) = default;

    void printInfo() const;
    virtual void applyEncounter(Player& player) const;

    ostream& operator<<(ostream& os) const;


private:
    int m_force;
    int m_hpLoss;
    int m_coins;
};


#endif //CS234124_EX4_BATTLECARDS_H
