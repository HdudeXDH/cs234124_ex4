//
// Created by ofir1 on 11-Jun-22.
//
#include "Player.h"

#ifndef CS234124_EX4_WIZARD_H
#define CS234124_EX4_WIZARD_H
class Wizard : public Player {
public:
    Wizard(const std::string name);
    virtual void heal(int points);
    virtual std::string type() const;
};

#endif //CS234124_EX4_WIZARD_H
