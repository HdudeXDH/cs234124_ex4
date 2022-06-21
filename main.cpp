

#include "Mtmchkin.h"
#include "Exception.h"

/// should run a game with 100 rounds top and started with deck.txt
int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("inFiles/test10.deck");
    //todo:check
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
        game.printLeaderBoard();
    }

}
