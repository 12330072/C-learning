//
//  main.cpp
//  Card Shuffling and Dealing (for homework
//
//  Created by 邱兆丰 on 16/3/19.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

// Exercise 10.10 Solution: DeckOfCards.h
// Class DeckOfCards represents a deck of 52 playing cards.
// Exercise 10.10 Solution: ex10_10.cpp
// Card shuffling and dealing program.
#include <iostream>
#include <iomanip>
#include "DeckOfCards.h"  // DeckOfCards class definition

int main() {
    DeckOfCards myDeckOfCards;
    
    // print all 52 Cards in the order in which they are dealt
    for (int i = 1; myDeckOfCards.moreCards() && i < 25; ++i) {
        // deal and display a Card
        std::cout << std::left << std::setw(19)
        << myDeckOfCards.dealCard().toString();
        
        if (i % 4 == 0)  // output newline every 4 cards
            std::cout << std::endl;
    }  // end for
    
    std::cout << std::endl;
    DeckOfCards newDeckOfCards;
    for (int i = 1; newDeckOfCards.moreCards() && i < 55; ++i) {
        // deal and display a Card
        std::cout << std::left << std::setw(19)
        << newDeckOfCards.dealCard().toString();
        
        if (i % 4 == 0)  // output newline every 4 cards
            std::cout << std::endl;
    }  // end for
    
    
}  // end main

