//
// Created by User on 6/12/2022.
//

#include "Mtmchkin.h"
#include <string>
#include <iostream>
#include "utilities.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Cards/Barfight.h"
#include "Cards/Vampire.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Merchant.h"
#include "Cards/Goblin.h"
#include "Cards/Fairy.h"
#include "Cards/Dragon.h"

int Mtmchkin::inputTeamSize(){
    printEnterTeamSizeMessage();
    int teamSize;
    while ((!(std::cin >> teamSize)) || (teamSize <2) || (teamSize>6))
    {
        printInvalidTeamSize();
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    return teamSize;
}

void Mtmchkin::inputPlayer(){
    std::string name, job;
    printInsertPlayerMessage();
    while (true) {
        std::cin >> name >>job;

        bool validChars = true;
        for (char const &c: name) {
            if (!std::isalpha(c)) {
                validChars=false;
            }

        }
        bool validLength = (name.size()<=15);

        if (!(validLength & validChars)){
            printInvalidName();
            continue;
        }

        if (job=="Wizard"){
            players.push_back(std::unique_ptr<Wizard>(new Wizard(name)));
            return;
        }
        if (job=="Fighter"){
            players.push_back(std::unique_ptr<Fighter>(new Fighter(name)));
            return;
        }
        if (job=="Rogue"){
            players.push_back(std::unique_ptr<Rogue>(new Rogue(name)));
            return;
        }

        printInvalidClass();
    }
}


ostream& operator<<(ostream& os, const Player& p) {
    std::string job =p.type();
    printPlayerDetails(os,p.m_name,job, p.m_level, p.m_force, (*p.m_hp).getHp(), p.m_coins);
    return os;
}

Mtmchkin::Mtmchkin(const std::string fileName):
rounds(0)
{

    printStartGameMessage();
    loadDeck(fileName);
    int teamSize = inputTeamSize();
    for (int i=0; i<teamSize;i++){
        inputPlayer();
    }
    nextCard=cards.begin();
}

cardCode Mtmchkin::strCardMap(const std::string raw){
    if (raw=="Barfight") return codeBarfight;
    if (raw=="Dragon") return codeDragon;
    if (raw=="Fairy") return codeFairy;
    if (raw=="Goblin") return codeGoblin;
    if (raw=="Merchant") return codeMerchant;
    if (raw=="Pitfall") return codePitfall;
    if (raw=="Treasure") return codeTreasure;
    if (raw=="Vampire") return codeVampire;
    return cardErrorCode;
}
void Mtmchkin::loadDeck(const std::string fileName) {
    // read cards:
    std::ifstream infile(fileName);
    if (infile.fail()) {
       throw DeckFileNotFound();
    }
    std::string line;
    int lineCount = 0;
    while (std::getline(infile, line))
    {
        lineCount++;
        switch(strCardMap(line)) {
            case cardCode::codeBarfight:
                cards.push_back(std::unique_ptr<Barfight>(new Barfight()));
                break;
            case codeDragon:
                cards.push_back(std::unique_ptr<Dragon>(new Dragon()));
                break;
            case codeFairy:
                cards.push_back(std::unique_ptr<Fairy>(new Fairy()));
                break;
            case codeGoblin:
                cards.push_back(std::unique_ptr<Goblin>(new Goblin()));
                break;
            case codeMerchant:
                cards.push_back(std::unique_ptr<Merchant>(new Merchant()));
                break;
            case codePitfall:
                cards.push_back(std::unique_ptr<Pitfall>(new Pitfall()));
                break;
            case codeTreasure:
                cards.push_back(std::unique_ptr<Treasure>(new Treasure()));
                break;
            case codeVampire:
                cards.push_back(std::unique_ptr<Vampire>(new Vampire()));
                break;
            default:
                throw DeckFileFormatError(lineCount);

        }


    }
    if(lineCount<5)
        throw DeckFileInvalidSize();
}

void Mtmchkin::playRound() {
    int index = 0;
    printRoundStartMessage(rounds+1);
    for (std::vector<std::unique_ptr<Player>>::iterator p = players.begin(); p != players.end(); ++p, ++index){
        if (!(p->get()->outOfGame() )) {

            if (nextCard==cards.end()) {
                nextCard = cards.begin();
            }
//            cout << *p->get() << endl;
//            cout << *nextCard->get() << endl;
            printTurnStartMessage(p->get()->getName());
            nextCard->get()->applyEncounter(*p->get());
            nextCard++;
            if (p->get()->isKnockedOut()){
                losers.push_front(index);
            }
            if (p->get()->isWinner()){
                winners.push_back(index);
            }
//            }
//            else {
//            cout << *p->get() << endl;
//            cout << *nextCard->get() << endl;
//            nextCard->get()->applyEncounter(*p->get());
//            nextCard++;
//            }

        }
//        for (std::vector<std::unique_ptr<Player>>::iterator p = players.begin(); p != players.end(); ++p){
//            std::vector<std::unique_ptr<Player>>::iterator temp = ++p;
//            if ((--p)->get()->isKnockedOut()){
//                moveLoserPosition(p);
//            }
//            p=temp;
//        }

    }
    if (isGameOver()){
        printGameEndMessage();
    }
    rounds++;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->rounds;
}

bool Mtmchkin::isGameOver() const {
    for (std::vector<std::unique_ptr<Player>>::const_iterator p = players.begin(); p != players.end(); ++p){
        if (!(p->get()->outOfGame())) {
            return false;
        }
    }
    return true;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rank = 1;
    for (std::list<int>::const_iterator it = winners.begin() ; it != winners.end(); ++it){
        printPlayerLeaderBoard(rank,*players[*it].get());
        rank++;
    }

    for (std::vector<std::unique_ptr<Player>>::const_iterator p = players.begin(); p != players.end(); ++p) {
        if (!(p->get()->outOfGame())){
            printPlayerLeaderBoard(rank,*p->get());
            rank++;
        }

    }
    for (std::list<int>::const_iterator it = losers.begin() ; it != losers.end(); ++it){
        printPlayerLeaderBoard(rank,*players[*it].get());
        rank++;
    }
//    for (std::vector<std::unique_ptr<Player>>::const_iterator p = losers.begin(); p != losers.end(); ++p) {
//        printPlayerLeaderBoard(rank,*p->get());
//        rank++;
//    }

}
//
//void Mtmchkin::moveLoserPosition(std::vector<std::unique_ptr<Player>>::iterator loser) {
//
//    }
//}
//
//void Mtmchkin::moveWinnerPosition(std::vector<std::unique_ptr<Player>>::iterator winner) {
//
////    for (std::vector<std::unique_ptr<Player>>::iterator p = players.begin(); p != winner; ++p) {
////        if (!(p->get()->isWinner())) {
////            players.splice(winners.end(),winners,winner);
////            return;
////        }
////    }
//};