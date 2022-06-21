//
// Created by ofir1 on 12-Jun-22.
//

#include "Merchant.h"

Merchant::Merchant():
        Card()
{}


void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int Answer;
//    std::cin >> Answer;

    while((std::cin >> Answer).fail() || ((Answer!=LEAVE) && (Answer!=BUY_HP) && (Answer!=BUY_FORCE))) {
//        bool check =;
        printInvalidInput();
        std::cin.clear();
        std::cin.ignore(CHUNK_SIZE, '\n');
//        std::cin >> Answer;
    }

    switch (Answer) {
        case(LEAVE):{
            printMerchantSummary(std::cout,player.getName(),LEAVE,LEAVE);
            break;
        }
        case(BUY_HP):{
            if(player.getCoins()>=HP_COST) {
                player.heal(HP);
                player.pay(HP_COST);
                printMerchantSummary(std::cout,player.getName(),BUY_HP,HP_COST);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),BUY_HP,LEAVE); //todo: whether we agree
            }
            break;
        }
        case(BUY_FORCE):{
            if(player.getCoins()>=FORCE_COST) {
                player.buff(FORCE);
                player.pay(FORCE_COST);
                printMerchantSummary(std::cout,player.getName(),BUY_FORCE,FORCE_COST);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout,player.getName(),BUY_FORCE,LEAVE); //todo: whether we agree
            }
            break;
        }

    }

}

std::string Merchant::getName() const{
    return "Merchant";
}