//
//  Game.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#define BLACK 1
#define WHITE 2
using namespace std;

typedef struct coordinate
{
    int row;
    int column;
} coordinate;

class Game
{
public:
    vector<coordinate> getValidMoves(const int* state, int player);
    vector<coordinate> getValidMoves(int player);
    bool isTerminal(int* state);
    int getWinner(); // 1 is BLACK, 2 is WHITE, 0 is "no winner"
    void mark(int player, coordinate move);
    void mark(const int* board, int player, coordinate move);

    int chessboard[15][15];
};
#endif /* Game_hpp */
