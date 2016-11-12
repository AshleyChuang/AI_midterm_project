//
//  Node.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "Node.hpp"

Node::Node(Node* parent, coordinate action, int PlayerTookAction, int depth)
{
    this->parent = parent;
    this->action = action;
    this->PlayerTookAction = (int)PlayerTookAction;
    this->depth = depth;
}

string Node::ToString()
{
    if (parent == NULL)
        return "Root Node";
    stringstream information;
    information << "Action: [" << action.row << "," << action.column << "], wins/visits: " << wins << "/" << visits << ", Took action:  p" << PlayerTookAction << ", depth: " << depth;
    return information.str();
}
