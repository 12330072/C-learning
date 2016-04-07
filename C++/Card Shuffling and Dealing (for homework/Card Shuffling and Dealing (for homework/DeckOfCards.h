//
//  DeskOfCards.hpp
//  Card Shuffling and Dealing (for homework
//
//  Created by 邱兆丰 on 16/3/19.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include <vector>
#include "Card.h"

// DeckOfCards class definition
class DeckOfCards {
public:
    DeckOfCards();  // constructor initializes deck
    Card dealCard();  // deals cards in deck
    bool moreCards() const;  // are there any more cards left
private:
    std::vector< Card > deck;  // represents deck of cards
    unsigned currentCard;  // index of next card to be dealt
};  // end class DeckOfCards

#endif