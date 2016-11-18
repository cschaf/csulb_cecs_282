#ifndef DECK_H
#define DECK_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: deck.h
    Purpose:  Represents a Deck of playing cards

    @author Christian Schaf
    @version 1.0 9/13/16
*/
#include "card.h"



class Deck
{
public:
    Deck();
    void shuffle();
    Card deal();
    void displayDeck();
    int cardsLeft();
    void initialize();
private:
    int size;
    Card cards[52];
    void swapRandom2Cards();

};
#endif // DECK_H
