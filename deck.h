//
// Created by Leaf on 2020/7/29.
//

#ifndef PROJECT_UNO_DECK_H
#define PROJECT_UNO_DECK_H

#include "card.h"
#include <vector>

using namespace std;

class Deck {
private:
    vector<Card> cards;
    vector<Card> discards;
    Card ontable;
    Card prev;
public:
    int reverse=0;
    Deck();
    virtual ~Deck();

    void create_new_deck();
    void shuffle_card();
    Card draw_card();
    void play_card(Card &card);
    void first_card();
    void pass_turn();
    Card on_table();
    Card prev_played();
};


#endif //PROJECT_UNO_DECK_H
