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
    while (true) {
        printInsertPlayerMessage();
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
            players.push_back(make_unique<Wizard>(name));
            break;
        }
        if (job=="Fighter"){
            players.push_back(make_unique<Fighter>(name));
            break;
        }
        if (job=="Rogue"){
            players.push_back(make_unique<Rogue>(name));
            break;
        }

        printInvalidClass();
    }
}


ostream& operator<<(ostream& os, const Player& p) {
    std::string job =p.type();
    printPlayerDetails(os,p.m_name,job, p.m_level, p.m_force, (*p.m_hp).getHp(), p.m_coins);
    return os;
}

Mtmchkin::Mtmchkin(const std::string fileName){

    printStartGameMessage();
    int teamSize = inputTeamSize();
    for (int i=0; i<teamSize;i++){
        inputPlayer();
    }
    loadDeck(fileName);
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
                cards.push_back(make_unique<Barfight>());
                break;
            case codeDragon:
                cards.push_back(make_unique<Dragon>());
                break;
            case codeFairy:
                cards.push_back(make_unique<Fairy>());
                break;
            case codeGoblin:
                cards.push_back(make_unique<Goblin>());
                break;
            case codeMerchant:
                cards.push_back(make_unique<Merchant>());
                break;
            case codePitfall:
                cards.push_back(make_unique<Pitfall>());
                break;
            case codeTreasure:
                cards.push_back(make_unique<Treasure>());
                break;
            case codeVampire:
                cards.push_back(make_unique<Vampire>());
                break;
            default:
                throw DeckFileFormatError(lineCount);

        }

    }
}

void Mtmchkin::playRound() {
    for (std::list<std::unique_ptr<Player>>::iterator p = players.begin(); p != players.end(); ++p){
//        bool out = p->get()->outOfGame();
        if (!(p->get()->outOfGame() )) {

            if (nextCard==cards.end()){
                nextCard=cards.begin();
            }
            else {
            cout << *p->get() << endl;
            cout << *nextCard->get() << endl;
            nextCard->get()->applyEncounter(*p->get());
            nextCard++;
            }

        }

    }
    rounds++;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->rounds;
}

bool Mtmchkin::isGameOver() const {
    for (std::list<std::unique_ptr<Player>>::const_iterator p = players.begin(); p != players.end(); ++p){
        if (!p->get()->outOfGame()) {
            return false;
        }
    return true;
    }
};