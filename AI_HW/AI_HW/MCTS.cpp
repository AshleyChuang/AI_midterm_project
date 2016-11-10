//
//  MCTS.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "MCTS.hpp"

class MCTS
{
public:
    public Node Selection(Node current, Game game) {
        while(!game.isTerminal(current.state)){
            List<Action> validMoves = game.getValidMoves(current.state);
            if(validMoves.size() > current.children.size()) {
                return Expand(current, game)
            }
        }
        return current;
    }
    
    public Node Expand(Node current, Game game){
        
    }
    
    public int Simulate(Node current, Game game) {
        
    }
    
    public BackPropagation(Node current) {
        
    }
private:
};
