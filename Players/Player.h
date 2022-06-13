//
// Created by User on 6/11/2022.
//
#include <string>
#include <memory>
#include "HealthPoints.h"
#include <iostream>

#ifndef CS234124_EX4_PLAYER_H
#define CS234124_EX4_PLAYER_H

static const int MAX_LVL = 10;
static const int FORCE_DEFAULT = 5;
//enum Type { Fighter, Rogue, Wizard};

class Player {
    std::string m_name;
//    std::unique_ptr<std::string> m_name;
protected:
//    std::string m_name;
    std::unique_ptr<HealthPoints> m_hp;
    int m_coins;
    int m_level;
    int m_force;
public:
    explicit Player(std::string name); // , int hp=HP_DEFAULT, int force=FORCE_DEFAULT)
    Player(const Player &)=default;
    virtual ~Player() = default;
    Player & operator=(const Player &)=default;

    virtual std::string type() const= 0 ;

//    virtual void heal(int points); //should be overloaded in Wizard

    /*
     * return current player strength (force + level)
     * should be overloaded in Fighter
     */
    virtual int getAttackStrength();

    /*
     * Add coins to player,
     * should be overloaded in Rogue.
     */
    virtual void addCoins(int amount);

    /*
     * healing points to the player, if surpasses the maxhp will stay on maxhp
     * should be overloaded in Wizard.
     */
    virtual void heal(int points);

    /*
     * printing player info
     */
    void printInfo(); //todo: maybe remove

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

    friend ostream& operator<<(ostream& os, const Player& p);
};



#endif //CS234124_EX4_PLAYER_H
