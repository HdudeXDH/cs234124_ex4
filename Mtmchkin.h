#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <iostream>
#include <list>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "utilities.h"
enum cardCode {
    codeBarfight,
    codeDragon,
    codeFairy,
    codeGoblin,
    codeMerchant,
    codePitfall,
    codeTreasure,
    codeVampire,
    cardErrorCode
};
class Mtmchkin{
    /// ------ us -----
    int rounds;
    std::list<std::unique_ptr<Player>> players;
    std::list<std::unique_ptr<Card>> cards;
    std::list<std::unique_ptr<Card>>::iterator nextCard;
    ///
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    ///---us----
    int inputTeamSize();
    void inputPlayer();
    void loadDeck(const std::string fileName);
    cardCode strCardMap(const std::string);
};



#endif /* MTMCHKIN_H_ */
