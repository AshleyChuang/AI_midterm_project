//
//  Game.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "Game.hpp"

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



void MakePoint( Point * pPoint, int iGameFlag )
{
    if( iGameFlag )
    {
        printf("please place your coordinate\n ");
        while( scanf( "%d%d", &pPoint->X, &pPoint->Y ) )
        {
            if( ( pPoint->X < 0 || pPoint->X >Length-1 ) || ( pPoint->Y < 0 || pPoint->Y >Length-1 ) )
                printf( "WRONG coordinate!PLEASE INPUT AGAIN：");
            else if( chessboard[pPoint->X][pPoint->Y] )
                printf( "THE PLACE IS ALREADY OCCUPIED!PLEASE INPUT AGAIN：");
            else break;
        }
    }

   chessboard[pPoint->X][pPoint->Y] = pPoint->iFlag;
    --g_iPointLen;
    system("cls");
    draw();
    if( iGameFlag == 0 )
        printf("The AI_Numberputer place at %d %d\n", pPoint->X, pPoint->Y );
}


void Game()
{                                
    printf("\t\t\tPlease input the coordinate（ex:13 6）interval by bankBLANKce。\n\n\n");
    draw();
    printf("First step please input 1，Second step please input2：");
    while( scanf( "%d", &choice ), choice!=1 && choice!=2 )
        printf( "INPUT ERROR!PLEASE INPUT AGAIN!");
    if( choice == 2 )
        MakePoint( &Point2, 0 );
    choice = 1;

    while( g_iPointLen )
    {
        MakePoint( &Point1, 1 );
        if( Victory( &Point1 ) )
        
            printf("YOU WIN!\n");
            return;

        }    /* 玩家赢 */

        if( choice == 1 )

        {

            AI( &Point2.Y, &Point2.X );

            MakePoint( &Point2, 0 );

            if( Victory( &Point2 ) )

            {               /* 电脑赢 */

                    printf( "THE AI_NumberPUTER WIN!\n" );

                    return;

                }
            }
        }
       else
        {
            MakePoint( &Point2, 1 );
            if( Victory( &Point2 ) )
            {
                printf("THE Game DRAWS!!!!\n");
                return;
            }
        }
    }
    printf("draw\n");
}


void draw() /* 画棋盘 */
{
    int i,j;
    char p[15][15][4];
    for(j=0;j<15;j++)
        for(i=0;i<15;i++){
            if(chessboard[j][i]==BLANK) strcpy(p[j][i],"  \0");
            if(chessboard[j][i]==HUMAN) strcpy(p[j][i],"●\0");
            if(chessboard[j][i]==AI_Number) strcpy(p[j][i],"◎\0");
        }

    printf("       A    B   C    D   E   F   G   H   I   J   K   L   M   N    O  \n");

    printf("       ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");

    for(i=0,j=0;i<14;i++,j++){

    printf("     %2d│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);

    printf("       ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤\n");

    }

    printf("     14│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│0\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14]);

    printf("       └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");

}


int Victory(int x,int y)
{
    int i,w=1,mz=1,nz=1,z=1;
    for(i=1;i<5;i++)
    {
        if(y+i<15&&chessboard[x][y+i]==player)
            w++;
        else break;//下
    }
    for(i=1;i<5;i++)
    {
        if(y-i>=0&&chessboard[x][y-i]==player)
            w++;
        else break;//上
    }
    if(w>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&chessboard[x+i][z]==player)
            mz++;
        else break;//右
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&chessboard[x-i][y]==player)
            mz++;
        else break;//左
    }
        if(mz>=5)
            return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&y+i<15&&chessboard[x+i][y+i]==player)
            nz++;
        else break;//右下
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&y-i>=0&&chessboard[x-i][y-i]==player)
            nz++;
        else break;//左上
    }
    if(nz>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&y-i>=0&&chessboard[x+i][y-i]==player)
            z++;
        else break;//右上
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&y+i<15&&chessboard[x-i][y+i]==player)
            z++;
        else break;//左下
    }
    if(z>=5)
        return player;
    return 0;
}
