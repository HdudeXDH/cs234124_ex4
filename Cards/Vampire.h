
#ifndef CS234124_EX4_VAMPIRE_H
#define CS234124_EX4_VAMPIRE_H


#include "Battlecards.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int VAMPIRE_FORCE = 10;
static const int VAMPIRE_HPLOSS = 10;
static const int VAMPIRE_COINS = 2;



class Vampire : public Battlecards {
public:


    Vampire();

    virtual std::string getName() const override;

    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;

};





#endif //CS234124_EX4_VAMPIRE_H
