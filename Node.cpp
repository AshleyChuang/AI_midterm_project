//
//  Node.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "Node.hpp"

Node::Node(Node parent, int action, int PlayerTookAction, int depth)
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
    
    return "Action: " + action + " Vi/Va: " + visits + "/" + value + " (Took Action: p" + PlayerTookAction + ") depth: " + depth;
}
