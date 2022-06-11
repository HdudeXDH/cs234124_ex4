//
// Created by User on 6/11/2022.
//
#include <string>
#include "HealthPoints.h"
#ifndef CS234124_EX4_PLAYER_H
#define CS234124_EX4_PLAYER_H
using namespace std;

static const int MAX_LVL = 10;

class Player {
    string m_name;
    string m_className;
    HealthPoints m_hp;
//    int m_maxHP;
    int m_level;
    int m_force;
    int m_coins;
public:
    virtual void heal(); //should be overloaded in Wizard

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


    Player(const char *name, int hp=HP_DEFAULT, int force=FORCE_DEFAULT);
    Player(const Player &)=default;
    ~Player() = default;
    Player & operator=(const Player &)=default;
};


#endif //CS234124_EX4_PLAYER_H
