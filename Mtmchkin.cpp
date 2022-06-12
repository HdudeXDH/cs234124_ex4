//
// Created by User on 6/12/2022.
//

#include "Mtmchkin.h"
#include <string>
#include <fstream>
#include <iostream>
#include "utilities.h"

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

int Mtmchkin::inputPlayer(){
    printInsertPlayerMessage();
//    while ((!(std::cin >> teamSize)) || (teamSize <2) || (teamSize>6))
//    {
//        std::cout << "Please enter an integer:\n";
//
//        std::cin.clear();
//        std::cin.ignore(256, '\n');
//    }
}
ostream& operator<<(ostream& os, Player& p) {
//    std::string job = p.type();

    printPlayerDetails(os,p.m_name,job, p.m_level, (*p.m_hp).getHp(), p.m_coins);
    return os;
}

Mtmchkin::Mtmchkin(const std::string fileName){

    printStartGameMessage();
    int teamSize = inputTeamSize();


    // read cards:

    std::ifstream infile(fileName);
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { break; } // error

        // process pair (a,b)
    }

};