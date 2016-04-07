//
//  DeskOfCards.cpp
//  Card Shuffling and Dealing (for homework
//
//  Created by 邱兆丰 on 16/3/19.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() {
    currentCard = 52;
    for (int i = 3; i >= 0; i--) {
        for (int j = 12; j >= 0; j--) {
            deck.push_back(Card(j, i));
        }
    }
}

bool DeckOfCards::moreCards() const {
    return (currentCard > 0);
}

Card DeckOfCards::dealCard() {
    return deck[--currentCard];
}
