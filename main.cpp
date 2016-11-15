#include <iostream>
#include "Game.hpp"
# include<stdio.h>//插入输入输出头文件
# include<string.h>//字符数组的函数定义的头文件
# include<stdlib.h>//stdlib 头文件即standard library标准库头文件stdlib 头文件里包含了C、C++语言的最常用的系统函数该 ,文件包含了C语言标准库函数的定义.
# define BLANK 0//
# define HUMAN 1
# define AI_Number   2
    /* 空位置设为0 ，玩家下的位置设为1 ，电脑下的位置设为2 */
#define Length 15
int chessboard[Length][Length];  //自己定义的预处理函数，以二维数组形式构建棋盘  /* 15*15的棋盘 */

typedef struct//typedef的作用是在C中定义一个结构体类型
{
    int iFlag;
    int X, Y;
}Point;


int g_iPointLen;
Point Point1,Point2;
void Game();  /* 程序的主要控制函数 */
void draw();   /* 画棋盘 */
int Victory(int x,int y);  /* 判断胜利 p q为判断点坐标 */
void AI(int *p,int *q);     /* 电脑下子 p q返回下子坐标 */
int value(int p,int q);     /* 计算空点p q的价值 */
int qXing(int n,int p,int q);    /* 返回空点p q在n方向上的棋型 n为1-8方向 从右顺时针开始数 */
void yiwei(int n,int *i,int *j);   /* 在n方向上对坐标 i j 移位 n为1-8方向 从右顺时针开始数  */


void InitGame(){
    int i,j;
    g_iPointLen = Length * Length;
    Point1.X = 0;
    Point1.Y = 0;
    Point1.iFlag = AI_Number;
    Point2.X = 7;
    Point2.Y = 7;
    Point2.iFlag = HUMAN;
    for( i=0; i <Length*Length; ++i )
        for(j=0;j<length;++j)
            chessboard[i][j] = BLANK;
}

int main() {
    char k;
    system("color E0");//设置颜色
    do{
        InitGame();
        int player=1;
        Game();
        printf("Do you want a new turn?input y or n："); getchar(); scanf("%c",&k);
        while(k!='y'&&k!='n'){ printf("INPUT ERROR!\n"); scanf("%c",&k); }
        system("cls");
    }while(k=='y');
    printf("Thanks for using!\n");
    return 0;
}

