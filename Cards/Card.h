//
// Created by User on 6/11/2022.
//
#include "../Players/Player.h"

#ifndef CS234124_EX4_CARD_H
#define CS234124_EX4_CARD_H


class Card {
/*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const;
};


#endif //CS234124_EX4_CARD_H
