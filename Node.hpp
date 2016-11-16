//
//  Node.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#define Length 15
// define all the possible action below
//
//
//#include "Coordinate.hpp"
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
typedef struct coordinate
{
    int row;
    int column;
} coordinate;

bool operator<(coordinate const& x, coordinate const& y){
    return (x.row < y.row)&&(x.column < y.column);
}

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
    int state[15][15] = {{0}}; // [15][15]
    int number_of_chess;
    
    Node(Node* parent, coordinate action, int player, int depth, int (*state)[Length], int number_of_chess);
    string ToString();
};

#endif /* Node_hpp */
