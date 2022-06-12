//
// Created by ofir1 on 11-Jun-22.
//
#include "Player.h"

#ifndef CS234124_EX4_FIGHTER_H
#define CS234124_EX4_FIGHTER_H
class Fighter : public Player {
public:
    virtual int getAttackStrength();
    virtual std::string type();
//    virtual ~Fighter();
};
#endif //CS234124_EX4_FIGHTER_H
