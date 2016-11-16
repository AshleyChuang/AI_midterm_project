//
//  MCTS.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef MCTS_hpp
#define MCTS_hpp

#include "Node.hpp"
#include <stdlib.h>
#include <math.h>
#include <set>
#define BLACK 1
#define WHITE 2
#define BLANK 0

using namespace std;

class MCTS
{
public:
    Node* Selection(Node* current, int (*board)[Length]);
    Node* Expand(Node* current, int (*board)[Length]);
    
    int Simulate(Node* current, int (*board)[Length], int player);
    void BackPropagation(Node* current, int value);
    Node* getBestChild(Node* current, int Cp); // by UCT
    
    coordinate getBestAction(int (*board)[Length], int player, int g_iPointLen); // return a coordinate where is the best place to move.
    
    int opponent(int startPlayer);
    
    set<coordinate> getValidMoves(int (*state)[Length], int player);
    
    bool isTerminal(int (*board)[Length], coordinate move);
    int getWinner(int (*board)[Length], coordinate move); // 1 is BLACK, 2 is WHITE, 0 is "no winner", 3 is TIE
    void mark(int (*board)[Length], int player, coordinate move);
    
};

#endif /* MCTS_hpp */
