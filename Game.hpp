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
<<<<<<< HEAD
#include <string.h>//字符数组的函数定义的头文件
#include <stdlib.h>//stdlib 头文件即standard library标准库头文件stdlib 头文件里包含了C、C++语言的最常用的系统函数该 ,文件包含了C语言标准库函数的定义.
=======
#include<string.h>//字符数组的函数定义的头文件
#include<stdlib.h>//stdlib 头文件即standard library标准库头文件stdlib 头文件里包含了C、C++语言的最常用的系统函数该 ,文件包含了C语言标准库函数的定义.
#include <map>
<<<<<<< HEAD
=======
#include "MCTS.hpp"
>>>>>>> origin/master
>>>>>>> 7890d9efedf5bacfac8af6f28515bf73a6fc432f

#define BLACK 1
#define WHITE 2

#define Length 15

# define BLANK 0//

/* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为2 */
using namespace std;

class MCTS;

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
    
    set<coordinate> getValidMoves(const int (*state)[Length], int player);
    set<coordinate> getValidMoves(int player);
    
    bool isTerminal(int (*board)[Length], coordinate move);
    int getWinner(const int (*board)[Length], coordinate move); // 1 is BLACK, 2 is WHITE, 0 is "no winner", 3 is TIE
    void mark(int (*board)[Length], int player, coordinate move);
    
    void draw();
    void playGame();
    //int value(int p,int q);
    //int qXing(int n,int p,int q);    /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */
    //void yiwei(int n,int *i,int *j);   /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数  */
    void MakePoint( Point * pPoint, int iGameFlag );
    void AI(int* y, int* x);
    
    void manager(const int (*board)[Length], int player);
    void grader();
    void multiplier();
    set<coordinate> converter();
    
    int chessboard[Length][Length];
    int g_iPointLen;
    int player;
    Point Point1,Point2;
    MCTS *mcts;
};
#endif /* Game_hpp */
