
#include "Player.h"

#ifndef CS234124_EX4_ROUGE_H
#define CS234124_EX4_ROUGE_H
class Rogue : public Player {
public:
    Rogue(const std::string name);
    virtual void addCoins(int amount);
    virtual std::string type() const;

};
#endif //CS234124_EX4_ROUGE_H
