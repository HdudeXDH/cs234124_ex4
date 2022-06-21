//
// Created by ofir1 on 12-Jun-22.
//
#include <string>
#include "Merchant.h"

Merchant::Merchant():
        Card()
{}

//bool checkMerchantInput(string raw){
//    for (char const &c: raw) {
//        if (!std::isdigit(c)) {
//            return false;
//        }
//
//    }
//    if (raw.length()==0) {
//        return false;
//    }
//    int Answer = std::stoi(raw);
//    if ((Answer!=LEAVE) && (Answer!=BUY_HP) && (Answer!=BUY_FORCE))
//        return false;
//    return true;
//}

void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int Answer;
    string RawAnswer;

    while((std::cin >> Answer).fail() || ((Answer!=LEAVE) && (Answer!=BUY_HP) && (Answer!=BUY_FORCE))) {
//        bool check =;
//        std::getline(std::cin , RawAnswer);
//        if (RawAnswer.empty()){
//            continue;
//        }
//        std::istringstream iss(RawAnswer);
//        if ((!RawAnswer.empty()) ||(std::cin >> Answer).good() || !((Answer!=LEAVE) && (Answer!=BUY_HP) && (Answer!=BUY_FORCE))){
//            break;
//        }
//        if (checkMerchantInput(RawAnswer)){
//            Answer = std::stoi(RawAnswer);
//            break;
//        }
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