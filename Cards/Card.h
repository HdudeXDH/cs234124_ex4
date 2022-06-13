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

    //todo:: there might be a problem with the << solution or overloading
    friend std::ostream& operator<<(ostream& os,const Card& card);

    Card(const std::string& name);
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;

protected:
    std::string m_name;
    virtual void printCardHelp(ostream& os) const;

};


#endif //CS234124_EX4_CARD_H
