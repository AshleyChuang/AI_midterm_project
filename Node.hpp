//
//  Node.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

// define all the possible action below
//
//
#include "Game.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Node
{
public:
    Node *parent = NULL;
    vector<Node*> children;
    int wins = 0;
    int visits = 0;
    coordinate action;
    int player = -1;
    int depth = 0;
    bool ignore = false;
    
    //Game specific
    int state[15][15] = {0}; // [15][15]
    int number_of_chess;
    
    Node(Node* parent, coordinate action, int player, int depth, int* state, int number_of_chess);
    string ToString();
};

#endif /* Node_hpp */
