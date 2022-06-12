//
// Created by User on 6/11/2022.
//
#include "../Players/Player.h"
#include "../Players/HealthPoints.h"
#include <string>
#include <memory>
#include <iostream>

#ifndef CS234124_EX4_CARD_H
#define CS234124_EX4_CARD_H

using std::string;





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

    //todo: check if its legit to use << like this
    virtual ostream& operator<<(ostream& os) const = 0;

    Card(const string& name);
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;

protected:
    string m_name;

};


#endif //CS234124_EX4_CARD_H
