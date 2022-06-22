
#ifndef CS234124_EX4_PITFALL_H
#define CS234124_EX4_PITFALL_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int PITFALL_DMG = 10;

class Pitfall : public Card {
public:

    Pitfall();
    Pitfall(const Pitfall&) = default;
    ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& other) = default;
    void applyEncounter(Player& player) const override;
    virtual std::string getName() const override;

};


#endif //CS234124_EX4_PITFALL_H
