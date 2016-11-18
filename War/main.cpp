/**
    Class:    CECS 282 C++ for Java Developer
    Filename: main.cpp
    Purpose:  Main program for starting a game of WAR

    @author Christian Schaf (016188534)
    @version 1.0 9/13/16
*/
#include <iostream>
#include "war.h"
using namespace std;

int main()
{   War game;
    int result = game.displayMainMenu();
    while(result < 4){
        result = game.displayMainMenu();
    }

    return 0;
}
