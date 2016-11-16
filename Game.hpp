//
//  Game.hpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include<string.h>//字符数组的函数定义的头文件
#include<stdlib.h>//stdlib 头文件即standard library标准库头文件stdlib 头文件里包含了C、C++语言的最常用的系统函数该 ,文件包含了C语言标准库函数的定义.
#include <map>
#include "MCTS.hpp"

#define BLACK 1
#define WHITE 2

#define Length 15

# define BLANK 0//
# define HUMAN 1 // white
# define AI_Number   2 // black
# define TIE 3
/* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为2 */
using namespace std;

typedef struct coordinate
{
    int row;
    int column;
} coordinate;

typedef struct//typedef的作用是在C中定义一个结构体类型
{
    int iFlag;
    int X, Y;
}Point;


class Game
{
public:
    Game();
    
    set<coordinate> getValidMoves(const int* state, int player);
    set<coordinate> getValidMoves(int player);
    
    bool isTerminal(int (*board)[Length], coordinate move);
    int getWinner(int (*board)[Length], coordinate move); // 1 is BLACK, 2 is WHITE, 0 is "no winner", 3 is TIE
    //void mark(int player, coordinate move);
    void mark(int (*board)[Length], int player, coordinate move);
    
    int Victory(int x,int y);
    void draw();
    void playGame();
    int value(int p,int q);
    int qXing(int n,int p,int q);    /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */
    void yiwei(int n,int *i,int *j);   /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数  */
    void MakePoint( Point * pPoint, int iGameFlag );
    void AI(int* y, int* x);
    
    
    int chessboard[Length][Length];
    int g_iPointLen;
    Point Point1,Point2;
    MCTS *mcts;
};
#endif /* Game_hpp */
