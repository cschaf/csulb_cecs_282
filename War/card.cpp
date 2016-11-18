/**
    Class:    CECS 282 C++ for Java Developer
    Filename: card.cpp
    Purpose:  Represents a card from a playing card game

    @author Christian Schaf
    @version 1.0 9/13/16
*/
#include <iostream>
#include <string>
#include "card.h"

using namespace std;

Card::Card(){
    suit = '-';
    rank = -1;
}

Card::Card(char s, int r){
    suit = s;
    rank = r;
}

int Card::getRank()
{
    return rank;
}

char Card::getSuit()
{
    return suit;
}

void Card::setCard(char s, int r)
{
    suit = s;
    rank = r;
}

Card::~Card()
{
}

char* Card::getSimpleFormatedRank()
{
    if(rank == 1) return "Ace";
    else if(rank == 11) return "Jack";
    else if(rank == 12) return "Queen";
    else if(rank == 13) return "King";

    else{
        char numbers[3];
        sprintf(numbers,"%d",rank);
        numbers[3] = '\0';
        return numbers;
    }

}

char* Card::getSimpleFormatedSuit()
{
    if(suit == 'D') return "Diamonds";
    else if(suit == 'H') return "Hearts";
    else if(suit == 'C') return "Clubs";
    else if(suit == 'S') return "Spades";
    else return "unknown";
}

void Card::display(){
    char cardRank = ' ';
    switch (rank) {
    case 1:
        cardRank = 'A';
        break;
    case 2:
        cardRank = '2';
        break;
    case 3:
        cardRank = '3';
        break;
    case 4:
        cardRank = '4';
        break;
    case 5:
        cardRank = '5';
        break;
    case 6:
        cardRank = '6';
        break;
    case 7:
        cardRank = '7';
        break;
    case 8:
        cardRank = '8';
        break;
    case 9:
        cardRank = '9';
        break;
    case 10:
        cardRank = 'X';
        break;
    case 11:
        cardRank = 'J';
        break;
    case 12:
        cardRank = 'Q';
        break;
    case 13:
        cardRank = 'K';
        break;
    default:
        break;
    }
    cout << getSimpleFormatedRank() << " of " << getSimpleFormatedSuit() << endl;
    cout << " -------- " << endl;
    cout << "[" <<cardRank << "       ]" << endl;
    cout << "[        ]" << endl;
    cout << "[        ]" << endl;
    cout << "[   " << suit << "    ]" << endl;
    cout << "[        ]" << endl;
    cout << "[        ]" << endl;
    cout << "[       " << cardRank <<"]" << endl;
    cout << " -------- " << endl;
}


