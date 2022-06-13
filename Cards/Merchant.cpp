//
// Created by ofir1 on 12-Jun-22.
//

#include "Merchant.h"

Merchant::Merchant():
        Card()
{}


void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int Answer = 0;
    std::cin >> Answer;

    while(Answer!=LEAVE && Answer!=BUY_HP && Answer!=BUY_FORCE) {
        printInvalidInput();
        std::cin >> Answer;
    }

    switch (Answer) {
        case(LEAVE):{
            printMerchantSummary(std::cout,player.getName(),LEAVE,LEAVE);
        }
        case(BUY_HP):{
            if(player.getCoins()>=HP_COST) {
                player.heal(HP);
                player.addCoins(HP_COST);
                printMerchantSummary(std::cout,player.getName(),BUY_HP,HP_COST);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),LEAVE,LEAVE);
            }
        }
        case(BUY_FORCE):{
            if(player.getCoins()>=FORCE_COST) {
                player.buff(FORCE);
                player.addCoins(FORCE_COST);
                printMerchantSummary(std::cout,player.getName(),BUY_FORCE,FORCE_COST);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),LEAVE,LEAVE);
            }
        }

    }

}

std::string Merchant::getName() const{
    return "Merchant";
}