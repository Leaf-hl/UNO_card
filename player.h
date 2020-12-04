//
// Created by Leaf on 2020/7/30.
//

#ifndef PROJECT_UNO_PLAYER_H
#define PROJECT_UNO_PLAYER_H


#include "hand.h"

struct player{
    player *next;
    player *prev;
    string name;
    Hand *play;
};

class lists{
private:
   player *head;
public:
    lists();
    void append(player *node);
    player* return_head();
};


#endif //PROJECT_UNO_PLAYER_H
