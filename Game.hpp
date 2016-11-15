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
# include<string.h>//字符数组的函数定义的头文件
# include<stdlib.h>//stdlib 头文件即standard library标准库头文件stdlib 头文件里包含了C、C++语言的最常用的系统函数该 ,文件包含了C语言标准库函数的定义.

#define BLACK 1
#define WHITE 2

#define Length 15

# define BLANK 0//
# define HUMAN 1
# define AI_Number   2
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

// This is the starting point of Jonathan's code.

void grader()
{
	int i, j, n, m, j_, i_, _j;
	for (i = 0; i <= 14; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (board[i][j] == 99 || board[i][j] == 66)
			{
				for (n = -3; n <= 3; n++)
				{
					j_ = j + n;
                    i_ = i + n;
                    _j = j - n;
                    m = 4 - abs(n);
					
                    if (j_ >= 0 && j_ <= 14 && board[i ][j_] != 99 && board[i ][j_] != 66)
                    {
                    	board[i ][j_] += m;
                    }
                    if (i_ >= 0 && i_ <= 14 && board[i_][j ] != 99 && board[i_][j ] != 66)
                    {
                    	board[i_][j ] += m;
                    }
                    if (i_ >= 0 && i_ <= 14 && j_ >= 0 && j_ <= 14 && board[i_][j_] != 99 && board[i_][j_] != 66)
                    {
                    	board[i_][j_] += m;
                    }
                    if (i_ >= 0 && i_ <= 14 && _j >= 0 && _j <= 14 && board[i_][_j] != 99 && board[i_][_j] != 66)
                    {
                    	board[i_][_j] += m;
                    }
				}
			}
		}
	}
}

void multiplier()
{
	int c = 0;
	
	for (i = 0; i <= 14; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (board[i][j] == 99 || board[i][j] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (j - 1 - c >= 0)
				{
					board[i][j - 1 - c] *= c / 1.6;
				}
				if (j < 15)
				{
					board[i][j] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
	for (j = 0; j <= 14; j++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (board[i][j] == 99 || board[i][j] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (i - 1 - c >= 0)
				{
					board[i - 1 - c][j] *= c / 1.6;
				}
				if (i < 15)
				{
					board[i][j] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
	for (m = 0; m <= 13; m++)
	{
		for (n = 0; n <= 14 - m; n++)
		{
			if (board[m + n][n] == 99 || board[m + n][n] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (m + n - 1 - c >= 0 && n - 1 - c >= 0)
				{
					board[m + n - 1 - c][n - 1 - c] *= c / 1.6;
				}
				if (m + n < 15 && n < 15)
				{
					board[m + n][n] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
	for (m = 1; m <= 13; m++)
	{
		for (n = 0; n <= 14 - m; n++)
		{
			if (board[n][m + n] == 99 || board[n][m + n] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (n - 1 - c >= 0 && m + n - 1 - c >= 0)
				{
					board[n - 1 - c][m + n - 1 - c] *= c / 1.6;
				}
				if (n < 15 && m + n < 15)
				{
					board[n][m + n] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
	for (m = 0; m <= 13; m++)
	{
		for (n = 0; n <= 14 - m; n++)
		{
			if (board[14 - n][m + n] == 99 || board[14 - n][m + n] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (14 - n + 1 + c < 15 && m + n - 1 - c >= 0)
				{
					board[14 - n + 1 + c][m + n - 1 - c] *= c / 1.6;
				}
				if (14 - n >= 0 and m + n < 15)
				{
					board[14 - n][m + n] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
	for (m = 1; m <= 13; m++)
	{
		for (n = 0; n <= 14 - m; n++)
		{
			if (board[14 - m - n][n] == 99 or board[14 - m - n][n] == 66)
			{
				c++;
			}
			else if (c != 0)
			{
				if (14 - m - n + 1 + c < 15 and n - 1 - c >= 0)
				{
					board[14 - m - n + 1 + c][n - 1 - c] *= c / 1.6;
				}
				if (14 - m - n >= 0 and n < 15)
				{
					board[14 - m - n][n] *= c / 1.6;
				}
				c = 0;
			}
		}
	}
}

int getValidMoves()
{
	grader(board);
	multiplier(board);
	converter(board);
	// I'm still figuring how to return coordinates.
}

// Jonathan's ending point    

class Game
{
public:
    Game();
    
    set<coordinate> getValidMoves(const int* state, int player);
    set<coordinate> getValidMoves(int player);
    
    bool isTerminal(int* state);
    int getWinner(); // 1 is BLACK, 2 is WHITE, 0 is "no winner"
    void mark(int player, coordinate move);
    void mark(const int* board, int player, coordinate move);
    
    int Victory(int x,int y)
    void draw();
    void playGame();
    int value(int p,int q);
    int qXing(int n,int p,int q);    /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */
    void yiwei(int n,int *i,int *j);   /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数  */
    void MakePoint( Point * pPoint, int iGameFlag );
    int chessboard[Length][Length];
    int g_iPointLen;
    Point Point1,Point2;
};
#endif /* Game_hpp */
