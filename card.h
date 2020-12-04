//
// Created by Leaf on 2020/7/29.
//

#ifndef PROJECT_UNO_CARD_H
#define PROJECT_UNO_CARD_H

#include <string>

enum Suit {
    black, blue, red, yellow, green
};
enum Spot {
    zero, one, two, three, four, five, six, seven, eight, nine, skip, reverse, draw_two, draw_four, wild,
};

class Card {
private:
    Spot spot;
    Suit suit;
public:
    Card();

    Card(Suit col, Spot n);

    Spot get_spot();

    ~Card();

    void get_card();

    bool operator==(Card const &other) const;
};


#endif //PROJECT_UNO_CARD_H
