
#include "Player.h"

#ifndef CS234124_EX4_FIGHTER_H
#define CS234124_EX4_FIGHTER_H
class Fighter : public Player {
public:
    Fighter(const std::string name);
    virtual int getAttackStrength();
    virtual std::string type() const;
//    virtual ~Fighter();
};
#endif //CS234124_EX4_FIGHTER_H
