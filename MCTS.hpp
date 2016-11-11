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
    Node* getBestChild(); // by UCT
    
    int getBestAction(Node* current, Game* game);
private:
};

#endif /* MCTS_hpp */
