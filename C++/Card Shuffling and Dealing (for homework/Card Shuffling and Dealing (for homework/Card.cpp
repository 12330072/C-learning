//
//  Card.cpp
//  Card Shuffling and Dealing (for homework
//
//  Created by 邱兆丰 on 16/3/19.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "Card.h"

Card::Card(int cardFace, int cardSuit) {
    face = cardFace;
    suit = cardSuit;
}

std::string Card::toString() const {
    std::string SC = "";
    SC = SC + faceNames[face] + " of " + suitNames[suit];
    return  SC;
}

const char* Card::faceNames[totalFaces] = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six","Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const char* Card::suitNames[ totalSuits ] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

int Card::getFace() const {
    return face;
}

int Card::getSuit() const {
    return suit;
}