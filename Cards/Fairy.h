
#ifndef CS234124_EX4_FAIRY_H
#define CS234124_EX4_FAIRY_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int FAIRY_HEAL = 10;

class Fairy : public Card {
public:

    void applyEncounter(Player& player) const override;


    Fairy();
    virtual std::string getName() const override;
    Fairy(const Fairy&) = default;
    ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;


private:
};




#endif //CS234124_EX4_FAIRY_H
