#ifndef WAR_H
#define WAR_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: war.h
    Purpose:  A game called WAR, which has a deck with 52 cards.
    It is played by 1 Player against the computer.
    The player decides if he want to take a new card from the deck.
    It will be compared to the card of the computer.
    If it has a higher value, player 1 wins this round.

    @author Christian Schaf
    @version 1.0 9/13/16
*/
#include "deck.h"
class War{
private:
    int player1Score;
    int player2Score;
    Deck deck;
    void handleMainMenuInput(int result);
    void handleRematchMenuInput(int result);
public:
    War();
    void start();
    int displayMainMenu();
    int displayRematchMenu();
};
#endif // WAR_H
