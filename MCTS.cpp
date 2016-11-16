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
    Node *root = new Node(NULL, *new coordinate, opponent(player), 0, game->chessboard, 225-game->g_iPointLen);
    
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
    do{
        set<coordinate> validMoves = game->getValidMoves(current->state, current->player);
        if(validMoves.size() > current->children.size()) { // current node has other coordinates to move, try them all!
            return Expand(current, game);
        }
        else {
            double Cp = 1.44;
            current = getBestChild(current, Cp);
        }
    }while(!game->isTerminal(current->state, current->action) || current->number_of_chess>0);
    return current;
}

Node* MCTS::Expand(Node* current, Game* game)
{
    set<coordinate> validMoves = game->getValidMoves(current->state, current->player); // get all the valid moves of current node
    set<coordinate>::const_iterator move_iterator;
    
    vector<Node*>::const_iterator iterator;
    for (iterator = current->children.begin(); iterator!=current->children.end(); iterator++) {
        coordinate temp;
        temp.row = (*iterator)->action.row;
        temp.column = (*iterator)->action.column;
        validMoves.erase(temp);
    }
    
    move_iterator = validMoves.begin();
    int playerActing = opponent(current->player);
    Node *node = new Node(current, *move_iterator, playerActing, current->depth+1, current->state, current->number_of_chess-1);
    current->children.push_back(node);
    
    game->mark(node->state, playerActing, *move_iterator);
    
    return node;
}

int MCTS::Simulate(Node* current, Game* game, int startPlayer)
{
    int temp_board[Length][Length];
    int number_of_chess = current->number_of_chess;
    
    std::copy(&(current->state[0][0]), &(current->state[0][0]) + 15*15, &temp_board[0][0]);
    
    if(game->getWinner(temp_board, current->action) == opponent(startPlayer)) {
        // not good
        //current->parent->wins = -1;
        return 0;
    }
    if (number_of_chess==0) { // the game is tie
        return 1;
    }
    
    int player = opponent(startPlayer);
    coordinate move = current->action;
    int winner = game->getWinner(temp_board, move);
    while( winner == 0 && number_of_chess) {
        //Random
        set<coordinate> moves = game->getValidMoves(temp_board, player);
        int r = rand() % moves.size();
        set<coordinate>::const_iterator move = moves.begin();
        advance(move, r);
        game->mark(temp_board, player, *move);
        player = opponent(player);
        number_of_chess--;
        winner = game->getWinner(temp_board, *move);
    }
    
    if (winner == startPlayer)
        return 1;
    else if (winner == opponent(startPlayer)) {
        return 0;
    }
    else { // TIE
        return 1;
    }
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
