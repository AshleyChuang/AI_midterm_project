//
//  MCTS.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "MCTS.hpp"

Node* MCTS::getBestChild(Node* current, int Cp)
{
    Node *bestChild = NULL;
    double bestUBT = -1000;
    vector<Node*> child = current->children;
    vector<Node*>::const_iterator child_iterator;
    for(child_iterator = child.begin(); child_iterator != child.end(); child_iterator++) {
        double UBT = ((*child_iterator)->wins / (*child_iterator)->visits) + 2*Cp*sqrt((2*log(current->visits))/(*child_iterator)->visits);
        if (UBT > bestUBT) {
            bestChild = *child_iterator;
            bestUBT = UBT;
        }
    }
    return bestChild;
}

coordinate MCTS::getBestAction(Game *game, int player)
{
    Node *root = new Node(NULL, *new coordinate, opponent(player), 0, &(game->chessboard[0][0]));
    
    for(int i=0; i<1000; i++) {
        Node *current = Selection(root, game);
        int value = Simulate(current, game, player);
        BackPropagation(current, value);
    }
    
    return getBestChild(root, 0)->action;
}

int MCTS::opponent(int startPlayer)
{
    if(startPlayer == BLACK)
        return WHITE;
    else
        return BLACK;
}

Node* MCTS::Selection(Node* current, Game* game)
{
    while(!game->isTerminal(&(current->state[0][0]))){
        vector<coordinate> validMoves = game->getValidMoves(&(current->state[0][0]), current->player);
        if(validMoves.size() > current->children.size()) { // current node has other coordinates to move, try them all!
            return Expand(current, game);
        }
        else {
            double Cp = 1.44;
            current = getBestChild(current, Cp);
        }
    }
    return current;
}

Node* MCTS::Expand(Node* current, Game* game)
{
    vector<coordinate> validMoves = game->getValidMoves(&(current->state[0][0]), current->player); // get all the valid moves of current node
    
    for(int i=0; i<validMoves.size(); i++) {
        vector<Node*>::const_iterator iterator;
        bool action_exist = false;
        for (iterator = current->children.begin(); iterator!=current->children.end(); iterator++) {
            if (((*iterator)->action.row == validMoves[i].row) && ((*iterator)->action.column == validMoves[i].column)) {
                action_exist = true;
                break;
            }
        }
        if (action_exist) {
            continue;
        }
        int playerActing = opponent(current->player);
        Node *node = new Node(current, validMoves[i], playerActing, current->depth+1, &(current->state[0][0]));
        current->children.push_back(node);
        
        game->mark(&(node->state[0][0]), playerActing, validMoves[i]);
        
        return node;
    }
    exit(1);
}

int MCTS::Simulate(Node* current, Game* game, int startPlayer)
{
    if(game->getWinner() == opponent(startPlayer)) {
        // not good
        current->parent->wins = -100;
        return 0;
    }
    int player = opponent(startPlayer);

    while(game->getWinner() == 0) {
        //Random
        vector<coordinate> moves = game->getValidMoves();
        coordinate move; // random
        game->mark(player, move);
    }
    
    if (game->getWinner() == startPlayer || game->getWinner() == 0)
        return 1;
    
    return 0;
}

void MCTS::BackPropagation(Node* current, int value)
{
    do
    {
        current->visits++;
        current->wins += value;
        current = current->parent;
    }
    while (current != NULL);
}
