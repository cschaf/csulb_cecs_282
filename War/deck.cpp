/**
    Class:    CECS 282 C++ for Java Developer
    Filename: deck.cpp
    Purpose:  Represents a Deck of playing cards

    @author Christian Schaf
    @version 1.0 9/13/16
*/
#include <random>
#include <iostream>
#include <ctime>
#include "deck.h"

using namespace std;
Deck::Deck()
{
    this->initialize();
}
void Deck::initialize(){
    size = 52;
    char suits[4] = {'H','D','C','S'};
    int currentIndex = 0;
    for (int suitCounter=0; suitCounter < 4; suitCounter++) {
        for(int value=1; value<14;value++){
            cards[currentIndex] = Card(suits[suitCounter], value);
            currentIndex++;
        }

    }
}

void Deck::shuffle(){
    srand(time(0));
    for(int i = 0; i < 1000; i++){
        int firstRandomIndex = rand() % 52;
        int secondRandomIndex = rand() % 52;
        Card temp = cards[firstRandomIndex];
        cards[firstRandomIndex] = cards[secondRandomIndex];
        cards[secondRandomIndex] = temp;
    }
}

Card Deck::deal(){
    if(size >= 0){
        return cards[--size];
    }
}

void Deck::displayDeck(){
  for(int i = 0; i < size; i++){
     cards[i].display();
  }

}

int Deck::cardsLeft(){
    return size;
}
