//
// Created by User on 6/11/2022.
//
#include "../Players/Player.h"
#include "../Players/HealthPoints.h"
#include "../utilities.h"
#include <string>
#include <memory>
#include <iostream>

#ifndef CS234124_EX4_CARD_H
#define CS234124_EX4_CARD_H




class Card {
public:
/*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */

    friend std::ostream& operator<<(ostream& os,const Card& card);

    Card() = default;
    Card(const Card&) = default;
    virtual ~Card(){}
    Card& operator=(const Card& other) = default;

    virtual std::string getName() const {return "";};

protected:
    virtual void printCardHelp(ostream& os) const;

};


#endif //CS234124_EX4_CARD_H
