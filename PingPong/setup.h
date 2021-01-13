//
// Created by bmondal on 26/12/20.
//

#ifndef PINGPONG_SETUP_H
#define PINGPONG_SETUP_H

#include "Player.h"
#include "Ball.h"


class setup {
public:
    setup();
    void draw();
    void input();
    void logic();

public:
    int ch;
    int width = 80;
    int height = 24;
    int dir = 1;
    int player1Points, player2Points = 0;
    bool quit;
    char wallTexture, playerTexture;
    bool player1Serve, player2Serve = false;

    Player player1{height / 2, 2};
    Player player2{height / 2, width - 3};

    Ball ball{static_cast<double>(height/2), 3, 1};
};


#endif //PINGPONG_SETUP_H
