
#include "..\Mtmchkin.h"
/// should run a game with 100 rounds top and started with deck.txt
int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
            game.playRound();
            game.printLeaderBoard();
        }
    } catch( DeckFileNotFound &exc) {
        std::cout << exc.what() << endl;
        return -1;
    } catch( DeckFileFormatError &exc) {
        std::cout << exc.what() << endl;
        return -1;
    } catch( DeckFileInvalidSize &exc) {
        std::cout << exc.what() << endl;
        return -1;
    }

}
