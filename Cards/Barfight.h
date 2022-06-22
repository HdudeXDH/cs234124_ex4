
#ifndef CS234124_EX4_BARFIGHT_H
#define CS234124_EX4_BARFIGHT_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int BARFIGHT_DMG = 10;

class Barfight : public Card {
public:

    Barfight();
    Barfight(const Barfight&) = default;
    ~Barfight() = default;
    Barfight& operator=(const Barfight& other) = default;
    virtual std::string getName() const override;
    void applyEncounter(Player& player) const override;


};




#endif //CS234124_EX4_BARFIGHT_H
