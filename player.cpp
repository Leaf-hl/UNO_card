//
// Created by Leaf on 2020/7/30.
//

#include "player.h"


lists::lists() {
    head = nullptr;
}

//lists::~lists() {
//    player *temp=head;
//    while (temp){
//        player *a=temp;
//        delete temp;
//        temp=a->next;
//    }
//
//}

void lists::append(player *node) {
    if (head == nullptr) {
        auto *new_node = new player();
        new_node->name = node->name;
        new_node->play = node->play;
        new_node->next = new_node->prev = new_node;
        head = new_node;
        return;
    } else {
        player *last = head->prev;
        auto *new_node = new player();
        new_node->name = node->name;
        new_node->play = node->play;
        new_node->next = head;
        head->prev = new_node;
        new_node->prev = last;
        last->next = new_node;
    }
}

player* lists::return_head() { return head; }