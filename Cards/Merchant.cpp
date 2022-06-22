
#include <string>
#include <set>
#include <map>
#include "Merchant.h"
std::map<std::string, int> m { {"0", 0}, {"1", 1}, {"2", 2}, };

Merchant::Merchant():
        Card()
{}

std::set<std::string> myset{"0", "1", "2"};

void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int Answer;
    string RawAnswer;
//    cin.ignore();
    while (true) {
        string response;
        getline(cin, response);
//        std::size_t listsize = sizeof mylist / sizeof mylist[0];
        if (myset.find(response) != myset.end()){
            Answer = m[response];
            break;
        }
        printInvalidInput();
//        std::cin.clear();
//        std::cin.ignore(CHUNK_SIZE, '\n');
    }
//    while((std::cin >> Answer).fail() || ((Answer!=LEAVE) && (Answer!=BUY_HP) && (Answer!=BUY_FORCE))) {
//        printInvalidInput();
//        std::cin.clear();
//        std::cin.ignore(CHUNK_SIZE, '\n');
//    }

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