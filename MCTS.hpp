//
//  MCTS.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef MCTS_hpp
#define MCTS_hpp

#include <stdio.h>
#include "Node.hpp"
#include "Game.hpp"
#include <list>

class MCTS
{
public:
    
    Node* Selection(Node* current, Game* game);
    Node* Expand(Node* current, Game* game);
    
    int Simulate(Node* current, Game* game);
    void BackPropagation(Node* current);
    Node* getBestChild(Node* current, int Cp); // by UCT
    
    int* getBestAction(Game* game, int player); // return a coordinate where is the best place to move.
private:
};

#endif /* MCTS_hpp */
