//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_BATTLECARDS_H
#define CS234124_EX4_BATTLECARDS_H

#include "Card.h"
#include "../Players/Player.h"
#include <string>
#include <memory>



class Battlecards : public Card {
public:

    Battlecards(int force,int hpLoss,int coins);
    Battlecards(const Battlecards &)=default;
    virtual ~Battlecards(){}
    Battlecards& operator=(const Battlecards &) = default;
    virtual std::string getName() const = 0;



    void printInfo() const;
    virtual void applyEncounter(Player& player) const override;


protected:
    int m_force;
    int m_hpLoss;
    int m_coins;
    virtual void printCardHelp(ostream& os) const override;

};


#endif //CS234124_EX4_BATTLECARDS_H
