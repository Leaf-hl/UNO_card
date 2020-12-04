#include <iostream>
#include <string.h>
#include "player.h"

using namespace std;

void game() {
    Deck deck;
    cout << "Welcome to the UNO GAME." << endl;
    cout << "-----------------------------------------" << endl;
    int demo;
    string name;
    int n;
    cout << "computer vs. computer(1) OR human vs. computer(2) :" << endl;
    cin >> demo;
    string computer_name[4] = {"computer_1", "computer_2", "computer_3", "computer_4"};
    if (demo == 2) {
        auto *players = new lists();
        cout << "What's your name(no space): ";
        cin >> name;
        cout << "How many computers you want to add(1-3): ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            struct player com;
            com.name = computer_name[i];
            Hand *comp = new Hand(&deck, true);
            com.play = comp;
            players->append(&com);
        }
        struct player person;
        Hand player(&deck, false);
        person.name = name;
        person.play = &player;
        players->append(&person);
        deck.first_card();
        cout << "The game is starting..." << endl;
        cout << "Shuffling the card..." << endl;
        cout << "Game begin" << endl;
        cout << "Each computer draw 7 cards." << endl;
        cout << "You draw 7 cards." << endl;
        struct player *temp = players->return_head();
        while (true) {
            cout << "#######################" << endl;
            if (temp->play->iscomputer) {
                cout << "## " << temp->name << "'s Turn ##" << endl;
            } else {
                cout << "##     Your Turn     ##" << endl;
            }
            cout << "#######################" << endl;
            temp->play->play_card(&deck);
            if (temp->play->isempty()) {
                if (temp->play->iscomputer) {
                    cout << "" << temp->name << " win!" << endl;
                    break;
                } else {
                    cout << "Congratulations! You win!" << endl;
                    break;
                }
            }
            cout << endl;
            if (deck.reverse == 0) {
                temp = temp->next;
            } else {
                temp = temp->prev;
            }
        }
        delete players;
    } else {
        auto *players = new lists();
        cout << "How many computers you want to add(2-4): ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            struct player com;
            com.name = computer_name[i];
            Hand *comp = new Hand(&deck, true);
            com.play = comp;
            players->append(&com);
        }
        deck.first_card();
        cout << "The game is starting..." << endl;
        cout << "Shuffling the card..." << endl;
        cout << "Game begin" << endl;
        cout << "Each computer draw 7 cards." << endl;
        struct player *temp = players->return_head();
        while (true) {
            cout << "#######################" << endl;
            cout << "## " << temp->name << "'s Turn ##" << endl;
            cout << "#######################" << endl;
            temp->play->play_card(&deck);
            if (temp->play->isempty()) {
                cout << "" << temp->name << " win!" << endl;
                break;
            }
            cout << endl;
            if (deck.reverse == 0) {
                temp = temp->next;
            } else {
                temp = temp->prev;
            }
        }
        delete players;
    }
}

int main() {
    string again;
    again = "Yes";
    while (again == "Yes") {
        game();
        cout << "Play again? (Yes or No)" << endl;
        cin >> again;
    }
    return 0;
}