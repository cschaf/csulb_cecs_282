#ifndef CARD_H
#define CARD_H
/**
    Class:    CECS 282 C++ for Java Developer
    Filename: card.cpp
    Purpose:  Represents a card from a playing card game

    @author Christian Schaf
    @version 1.0 9/13/16
*/

class Card{
public:
    void display();
    Card(char s, int r);
    Card();
    int getRank();
    char getSuit();
    void setCard(char s, int r);
    ~Card();
private:
    char suit;
    int rank;
    char* getSimpleFormatedRank();
    char* getSimpleFormatedSuit();
};
#endif // CARD_H
