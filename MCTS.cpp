//
//  MCTS.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "MCTS.hpp"

Node* MCTS::Selection(Node* current, Game* game)
{
    while(!game->isTerminal(current->state)){
        list<int> validMoves = game->getValidMoves(current->state);
        if(validMoves.size() > current->children.size()) {
            return Expand(current, game);
        }
        else {
            current = getBestChild(current, 1.44);
        }
    }
    return current;
}


Node* MCTS::Expand(Node* current, Game* game)
{
    list<int> validMoves = game->getValidMoves(current->state);
    
    for(int i=0; i<validMoves.size(); i++) {
        if(current->children.exist(validMoves[i])) continue;
        
        int playerActing = Opponent(current->PlayerTookAction);
        Node *node = new Node(current, validMoves[i], playerActing, current->depth+1);
        current->children.add(node);
        
        game->mark(playerActing, validMoves[i]);
        
        return node;
    }
}

int MCTS::Simulate(Node* current, Game* game)
{
    if(game->getWinner() == ...) {
        // not good
        return 0;
    }
    while(game->getWinner() == 0) {
        //Random
        list<int> moves = game>getValidMoves();
        int move = moves[r.Next(0, moves.size())];
        game->mark(player, move);
        player = Opponent(player);
    }
    
    if (game.getWinner() == startPlayer || game.GetWinner() == 3)
        return 1;
    
    return 0;
}

void MCTS::BackPropagation(Node* current)
{
    do
    {
        current->visits++;
        current->value += value;
        current = current->parent;
    }
    while (current != NULL);
}

Node MCTS::getBestChild(Node* current, int Cp)
{
    
}

int* MCTS::getBestAction(Game *game, int player)
{
    int bestMove[2] = {0,0};
    Node* root = new Node(NULL, player, , 0);
}
