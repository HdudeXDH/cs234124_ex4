//
// Created by ofir1 on 21-Jun-22.
//

#ifndef CS234124_EX4_GANG_H
#define CS234124_EX4_GANG_H


#include "Card.h"
#include "../Players/Player.h"
#include <string>
#include <memory>
#include <list>
#include <vector>



class Gang : public Card {
public:

    Gang(int force,int hpLoss,int coins);
    Gang(const Battlecards &)=default;
    ~Gang();
    Gang& operator=(const Gang &) = default;
    virtual std::string getName() const = 0;



    void printInfo() const;
    virtual void applyEncounter(Player& player) const override;


private:
    std::vector<std::unique_ptr<Gang>> gang;

    virtual void printCardHelp(ostream& os) const override;

};



#endif //CS234124_EX4_GANG_H
