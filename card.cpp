//
// Created by Leaf on 2020/7/29.
//
#include "card.h"
#include <iostream>
#include <sstream>

using namespace std;

const char *SuitNames[] = {"Black", "Blue", "Red", "Yellow", "Green"};

const char *SpotNames[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
                           "Skip", "Reverse", "Draw Two", "Draw Four", "Wild"};

Card::Card() : suit(black), spot(zero) {
}

Card::Card(Suit col, Spot n) : suit(col), spot(n) {

}

Card::~Card() = default;


Spot Card::get_spot() { return spot; }

void Card::get_card() {
    stringstream out;
    out << SuitNames[suit] << " (" << SpotNames[spot]<<")";
    cout << out.str();
}

bool Card::operator==(Card const &com) const {
    return (com.suit == suit || com.spot == spot || com.suit == black || suit == black);
}

