//
// Created by Leaf on 2020/7/30.
//

#ifndef PROJECT_UNO_HAND_H
#define PROJECT_UNO_HAND_H

#include "deck.h"

class Hand {
private:
    vector<Card> hand;
public:
    bool iscomputer= false;
    Hand();
    Hand(Deck *, bool);
    ~Hand();
    bool isempty();
    bool pass_turn = false;
    void draw(Deck *deck);
    void function_card(Card card, Deck *deck);
    void play_card(Deck *deck);
};


#endif //PROJECT_UNO_HAND_H
