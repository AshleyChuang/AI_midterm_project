//
//  Node.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "Node.hpp"

Node::Node(Node* parent, coordinate action, int PlayerTookAction, int depth, int* state, int number_of_chess)
{
    this->parent = parent;
    this->action = action;
    this->player = (int)PlayerTookAction;
    this->depth = depth;
    std::copy(state, state + 15*15, this->state);
    this->number_of_chess = number_of_chess;
}

string Node::ToString()
{
    if (parent == NULL)
        return "Root Node";
    stringstream information;
    information << "Action: [" << action.row << "," << action.column << "], wins/visits: " << wins << "/" << visits << ", Took action:  p" << player << ", depth: " << depth;
    return information.str();
}
