#include <iostream>
//#include "utilities.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
//    printStartGameMessage();
//    printEnterTeamSizeMessage();
    int teamSize;
    while ((!(std::cin >> teamSize)) || (teamSize <2) || (teamSize>6))
    {
        std::cout << "Please enter an integer:\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    return 0;
}
