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
#include "Game.hpp"
#include <math.h>

using namespace std;

class MCTS
{
public:
    MCTS(){
        
    }
    Node* Selection(Node* current, Game* game);
    Node* Expand(Node* current, Game* game);
    
    int Simulate(Node* current, Game* game, int player);
    void BackPropagation(Node* current, int value);
    Node* getBestChild(Node* current, int Cp); // by UCT
    
    coordinate getBestAction(Game* game, int player); // return a coordinate where is the best place to move.
    
    int opponent(int startPlayer);
private:
};

#endif /* MCTS_hpp */
