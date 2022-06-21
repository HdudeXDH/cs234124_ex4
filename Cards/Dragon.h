//
// Created by ofir1 on 11-Jun-22.
//

#ifndef CS234124_EX4_DRAGON_H
#define CS234124_EX4_DRAGON_H


#include "Battlecards.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <string>
#include <memory>


static const int DRAGON_FORCE = 25;
static const int DRAGON_HPLOSS = 100;
static const int DRAGON_COINS = 1000;



class Dragon : public Battlecards {
public:

    Dragon();
    virtual std::string getName() const override;
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;


};




#endif //CS234124_EX4_DRAGON_H
