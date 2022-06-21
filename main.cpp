#include <iostream>
//#include "utilities.h"
#include "Mtmchkin.h"
int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("inFiles/test10.deck");
//    for (int i=0;i<100;i++){
//        game.playRound();
//        game.printLeaderBoard();
//    }
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
        game.printLeaderBoard();
    }


//    ifstream infile;
//    infile.open("./deck.txt");
//    if (infile.fail()) {
//        cout << "alon";
//    }
//    std::string line;
//    int lineCount = 0;
//    while (std::getline(infile, line))
//    {
//        cout<<line;
//    }
}
/// should run a game with 100 rounds top and started with deck.txt