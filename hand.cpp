//
// Created by Leaf on 2020/7/30.
//
#include "hand.h"
#include <iostream>

using namespace std;
Hand::Hand() = default;
Hand::Hand(Deck *deck, bool computer) {
    iscomputer = computer;
    deck->shuffle_card();
    for (int i = 0; i < 7; i++) {
        draw(deck);
    }
}

Hand::~Hand() = default;

bool Hand::isempty() {
    return hand.empty();
}

void Hand::draw(Deck *deck) {
    Card temp = deck->draw_card();
    hand.push_back(temp);
    if (iscomputer) {
        cout << "The computer drew a card." << endl;
    } else {
        cout << "You drew a card: ";
        temp.get_card();
        cout << endl;
    }
}

void Hand::function_card(Card card, Deck *deck) {
    if (card.get_spot() == skip) {
        pass_turn = true;
//    } else if (card.get_spot() == reverse) {
//        deck->reverse=abs(reverse-1);
    } else if (card.get_spot() == draw_two) {
        draw(deck);
        draw(deck);
        pass_turn = true;
    } else if (card.get_spot() == draw_four) {
        draw(deck);
        draw(deck);
        draw(deck);
        draw(deck);
        pass_turn = true;
    } else { return; }
}

void Hand::play_card(Deck *deck) {
    std::cout << "Card on the table: ";
    deck->on_table().get_card();
    std::cout << "\n";
    function_card(deck->prev_played(), deck);
    if (iscomputer) {
        if (pass_turn) {
            cout << "The computer passes its turn." << endl;
            deck->pass_turn();
            pass_turn = false;
        } else {
            bool can_play = false;
            for (int i = 0; i < hand.size(); i++) {
                if (hand.at(i) == deck->on_table()) {
                    can_play = true;
                    if (hand.at(i).get_spot()==reverse){
                        deck->reverse=abs(deck->reverse-1);
                    }
                    deck->play_card(hand.at(i));
                    cout << "The computer plays: ";
                    hand.at(i).get_card();
                    hand.erase(hand.begin() + i);
                    cout << endl;
                    cout << "The computer has " << hand.size() << " cards left." << endl;
                    if (hand.size() == 1) {
                        cout << "UNO!!!" << endl;
                    }
                    break;
                }
            }
            if (!can_play) {
                cout << "The computer cannot play any card. Draw a card." << endl;
                draw(deck);
                cout << "The computer has " << hand.size() << " cards left." << endl;
            }
        }
    } else {
        if (pass_turn) {
            std::cout << "You cannot play any card, pass turn." << endl;
            deck->pass_turn();
            pass_turn = false;
            cout<<endl;
        } else {
            int choice = 0;
            cout << "You have " << hand.size() << " cards left" << endl;
            vector<Card> cards_can_play;
            vector<int> index;
            for (int i = 0; i < hand.size(); i++) {
                hand.at(i).get_card();
                cout << ", ";
                if (hand.at(i) == deck->on_table()) {
                    cards_can_play.push_back(hand.at(i));
                    index.push_back(i);
                }
            }
            cout << endl;
            if (cards_can_play.empty()) {
                std::cout << "You cannot play any card." << endl;
                draw(deck);
                cout<<endl;
            } else {
                cout << "Cards your can play: " << endl;
                for (int i = 1; i <= cards_can_play.size(); i++) {
                    cout << i << ":";
                    cards_can_play.at(i - 1).get_card();
                    cout << "; ";
                }
                cout << endl;
                while (true) {
                    cout << "Choose one card to play: ";
                    cin >> choice;
                    if (choice >= 1 && choice <= cards_can_play.size()) {
                        break;
                    } else {
                        cout << "You cannot play that card, try again!(see the hints above)" << endl;
                    }
                }
                if (cards_can_play.at(choice - 1).get_spot()==reverse){
                    deck->reverse=abs(deck->reverse-1);
                }
                deck->play_card(cards_can_play.at(choice - 1));
                hand.erase(hand.begin() + index.at(choice - 1));
                if (hand.size() == 1) {
                    cout << "UNO!!!" << endl;
                }
                cout << endl;
            }
        }
    }
}
