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

#include <stdio.h>
#include <string>
#include <list>
using namespace std;

class Node
{
public:
    Node *parent = NULL;
    list<Node> children;
    int value = 0;
    int visits = 0;
    int action = 0;
    int PlayerTookAction = 0;
    int depth = 0;
    bool ignore = false;
    
    //Game specific
    int state[9];;
    
    Node(Node* parent, int action, int PlayerTookAction, int depth);
    
    string ToString();
};

#endif /* Node_hpp */
