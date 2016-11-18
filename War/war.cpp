/**
    Class:    CECS 282 C++ for Java Developer
    Filename: war.cpp
    Purpose:  A game called WAR, which has a deck with 52 cards.
    It is played by 1 Player against the computer.
    The player decides if he want to take a new card from the deck.
    It will be compared to the card of the computer.
    If it has a higher value, player 1 wins this round.

    @author Christian Schaf
    @version 1.0 9/13/16
*/
#include <iostream>
#include <cstdlib>
#include "war.h"
#include "deck.h"
#include "card.h"

using namespace std;

void War::handleMainMenuInput(int result)
{
    switch (result) {
    case 1:
        deck.initialize();
        break;
    case 2:
        deck.displayDeck();
        break;
    case 3:
        deck.shuffle();
        break;
    case 4:
        start();
        break;
    case 5:
        cout << "Goodbye!" << endl;
        exit(0);
        break;
    default:
        break;
    }
}

void War::handleRematchMenuInput(int result){
    switch (result) {
    case 1: //yes
//        if(deck.cardsLeft()<=0){
//            start();
//        }
        break;
    case 2: // no
        displayMainMenu();
        break;
    default:
        break;
    }
}

War::War(){
    player1Score = 0;
    player2Score = 0;
}

void War::start()
{
    cout << "Get ready to play WAR!!!\n" << endl;
    while (deck.cardsLeft()> 1) {
        cout << "There are " << deck.cardsLeft() << " cards left in the deck.\n" << endl;
        cout << "...dealing cards..." << endl;
        cout << "\nOne card for you..." <<endl;
        Card one = deck.deal();
        int card1Value = one.getRank();
        one.display();
        cout << "\nOne card for me..." <<endl;
        Card two = deck.deal();
        int card2Value = two.getRank();
        two.display();
        if(card1Value > card2Value) player1Score++;
        else player2Score++;
        if(card1Value > card2Value) cout << "\nYou win!\n" << endl;
        else cout << "\nYou loose!\n" << endl;
        displayRematchMenu();
    }
    cout << "There are " << deck.cardsLeft() << " cards left in the deck.\n" << endl;
    cout << "Your score: " << player1Score << endl;
    cout << "My score: " << player2Score << endl;
    if(player1Score > player2Score) cout << "\nYou won!" << endl;
    else cout << "\nYou lost!" << endl;
    displayMainMenu();




}

int War::displayMainMenu()
{
    int result;
    bool resultIsInt = false;
    cout << "\n1) Get a new card deck" << endl;
    cout << "2) Show all remaining cards in the deck" << endl;
    cout << "3) Shuffle" << endl;
    cout << "4) Play WAR" << endl;
    cout << "5) Exit\n" << endl;
    cout << "Choose menu option (1-5): " << endl;

    while(!resultIsInt){
        resultIsInt = true;
        cin >> result;

        if(cin.fail() || result > 5){
            cin.clear();
            cin.ignore();
            cout << "Please enter an Integer (1-5) only: " << endl;
            resultIsInt = false;
        }
    }
    handleMainMenuInput(result);
    return result;
}

int War::displayRematchMenu()
{
    int result;
    bool resultIsInt = false;
    cout << "Wanna play again?" << endl;
    cout << "1) yes" << endl;
    cout << "2) no" << endl;
    cout << "" << endl;
    cout << "Choose menu option (1 or 2): " << endl;

    while(!resultIsInt){
        resultIsInt = true;
        cin >> result;

        if(cin.fail() || result > 2){
            cin.clear();
            cin.ignore();
            cout << "Please enter an Integer (1-2) only: " << endl;
            resultIsInt = false;
        }
        if(result == 2)break;
    }
    handleRematchMenuInput(result);
    return result;
}

