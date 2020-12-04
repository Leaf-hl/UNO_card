//
// Created by Leaf on 2020/7/29.
//
#include "deck.h"
#include <cstdlib>
#include <ctime>

Deck::Deck() {
    for (int n = 0; n < 2; n++) {
        for (int i = n; i <= 12; i++) {
            cards.emplace_back(blue, Spot(i));
            cards.emplace_back(red, Spot(i));
            cards.emplace_back(yellow, Spot(i));
            cards.emplace_back(green, Spot(i));
        }
    }
    for (int i = 0; i < 4; i++) {
        cards.emplace_back(black, draw_four);
        cards.emplace_back(black, wild);
    }
    shuffle_card();
    prev = cards.front();
}

Deck::~Deck() = default;

void Deck::create_new_deck() {
    srand(time(nullptr));
    Card temp;
    int k = 0;
    for (int i = 0; i < discards.size(); i++) {
        k = rand() % discards.size();
        temp = discards.at(i);
        discards.at(i) = discards.at(k);
        discards.at(k) = temp;
    }
    cards.swap(discards);
}

void Deck::shuffle_card() {
    srand(time(nullptr));
    Card temp;
    int k = 0;
    for (int i = 0; i < cards.size(); i++) {
        k = rand() % cards.size();
        temp = cards.at(i);
        cards.at(i) = cards.at(k);
        cards.at(k) = temp;
    }
}

Card Deck::draw_card() {
    if (cards.empty()) {
        create_new_deck();
    }
    Card temp = cards.front();
    cards.erase(cards.begin());
    return temp;
}

void Deck::play_card(Card &card) {
    prev = card;
    if (card.get_spot() != skip && card.get_spot() != reverse && card.get_spot() != draw_two
        && card.get_spot() != draw_four) {
        discards.emplace_back(ontable);
        ontable = card;
    } else {
        discards.push_back(card);
    }

}

void Deck::first_card() {
    Card first = draw_card();
    while (first.get_spot() == skip && first.get_spot() == reverse && first.get_spot() == draw_two
           && first.get_spot() == draw_four) {
        discards.push_back(first);
        first = draw_card();
    }
    ontable = first;
}

void Deck::pass_turn() {
    Card temp(black, one);
    prev = temp;
}

Card Deck::on_table() {
    return ontable;
}

Card Deck::prev_played() {
    return prev;
}