//
// Created by User on 6/11/2022.
//
#include <string>
#include <memory>
#include "HealthPoints.h"
#include <iostream>

using namespace std; //todo: delete
#ifndef CS234124_EX4_PLAYER_H
#define CS234124_EX4_PLAYER_H

static const int MAX_LVL = 10;
static const int FORCE_DEFAULT = 5;

class Player {
    std::string m_name;
protected:
    int m_level;
    int m_coins;
    int m_force;
    std::unique_ptr<HealthPoints> m_hp;
public:
    explicit Player(std::string name);
    Player(const Player &)=default;
    virtual ~Player() = default;
    Player & operator=(const Player &)=default;

    virtual std::string type() const= 0 ;

    /*
     * return current player strength (force + level)
     *  overloaded in Fighter
     */
    virtual int getAttackStrength();

    /*
     * Add coins to player,
     * overloaded in Rogue.
     */
    virtual void addCoins(int amount);

    /*
     * healing points to the player, if surpasses the maxhp will stay on maxhp
     * overloaded in Wizard.
     */
    virtual void heal(int points);

    /*
     * printing player info
     */
    void printInfo();

    /*
     * level up the player
     */
    void levelUp();

    /*
     * return current level player
     */
    int getLevel();

    /*
     * adding points to the player's force
     */
    void buff(int points);

    /*
     * Damage the player
     */
    void damage(int points);

    /*
     * check whether the player is knocked out (true/false)
     */
    bool isKnockedOut();


    /*
     * Pay the amount, if successful returns true
     */
    bool pay(int amount);

    int getCoins();


    std::string getName();
    bool isWinner();
    bool outOfGame();
    friend ostream& operator<<(ostream& os, const Player& p);
};



#endif //CS234124_EX4_PLAYER_H
