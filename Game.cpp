#include "Game.hpp"
#include "MCTS.hpp"

Game::Game(){
    mcts = new MCTS();
    int i,j;
    g_iPointLen = Length * Length;
    Point1.X = 0;
    Point1.Y = 0;
    Point1.iFlag = WHITE;
    Point2.X = 7;
    Point2.Y = 7;
    Point2.iFlag = BLACK;
    for( i=0; i <Length*Length; ++i )
        for(j=0;j<Length;++j)
            chessboard[i][j] = BLANK;
}


void Game:: MakePoint( Point * pPoint, int iGameFlag )
{
    if( iGameFlag )
    {
        char cor;
        printf("please place your coordinate\n ");
        
        
        while( scanf( "%d%c", &pPoint->X, &cor) )
        {
            pPoint->Y = cor-65;
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
    {
        char coy;
        coy=pPoint->Y+65;
        printf("The blackputer place at %d%c\n", pPoint->X, coy );
    }
}
void Game::mark(int (*board)[Length], int player, coordinate move)
{
    int cordinate_x = move.row;
    int cordinate_y = move.column;
    board[cordinate_x][cordinate_y] = player;
}


void Game::playGame()
{
    printf("\t\t\tPlease input the coordinate（ex:13H）\n\n\n");
    draw();
    printf("First step please input 1，Second step please input2：");
    int choice;
    while( scanf( "%d", &choice ), choice!=1 && choice!=2 )
        printf( "INPUT ERROR!PLEASE INPUT AGAIN!");
    if( choice == 2 )
        MakePoint( &Point2, 0 );
    choice = 1;
    while( g_iPointLen )
    {
        MakePoint( &Point1, 1 );
        coordinate temp;
        temp.row = Point1.X;
        temp.column = Point1.Y;
        if( getWinner( chessboard, temp )==1 ) {
            printf("YOU WIN!\n");
            return;
            
        }    /* 玩家赢 */
        
        if( choice == 1 )
            
        {
            player=3-player;
            
            AI( &Point2.Y, &Point2.X );
            
            MakePoint( &Point2, 0 );
            coordinate temp;
            temp.row = Point2.X;
            temp.column = Point2.Y;
            if( getWinner(chessboard,temp)==2)
                
            {               /* 电脑赢 */
                
                printf( "THE whitePUTER WIN!\n" );
                
                return;
                
            }
        }
    }
    printf("draw\n");
}

void Game::AI(int* y, int* x)
{
    coordinate move = mcts->getBestAction(this, WHITE);
    *y = move.column;
    *x = move.row;
}

void Game::draw() /* 画棋盘 */
{
    int i,j;
    char p[15][15][4];
    for(j=0;j<15;j++)
        for(i=0;i<15;i++){
            if(chessboard[j][i]==BLANK) strcpy(p[j][i],"  \0");
            if(chessboard[j][i]==BLACK) strcpy(p[j][i],"●\0");
            if(chessboard[j][i]==WHITE) strcpy(p[j][i],"◎\0");
        }
    
    printf("         A   B   C   D   E   F   G   H   I   J   K   L   M   N   0  \n");
    
    printf("       ┌─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┬─┐\n");
    
    for(i=0,j=0;i<14;i++,j++){
        
        printf("     %2d│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%d\n",j,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],p[i][5],p[i][6],p[i][7],p[i][8],p[i][9],p[i][10],p[i][11],p[i][12],p[i][13],p[i][14],j);
        
        printf("       ├─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┼─┤\n");
        
    }
    
    printf("     14│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│%s│0\n",p[14][0],p[14][1],p[14][2],p[14][3],p[14][4],p[14][5],p[14][6],p[14][7],p[14][8],p[14][9],p[14][10],p[14][11],p[14][12],p[14][13],p[14][14]);
    
    printf("       └─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┴─┘\n");
    printf("         A   B   C   D   E   F   G   H   I   J   K   L   M   N   0  \n");
    
}


int Game::getWinner(int (*board)[Length],coordinate coor)
{
    int x = coor.row;
    int y = coor.column;
    player = board[x][y];
    int i,w=1,mz=1,nz=1,z=1;
    for(i=1;i<5;i++)
    {
        if(y+i<15&&board[x][y+i]==player)
            w++;
        else break;//下
    }
    for(i=1;i<5;i++)
    {
        if(y-i>=0&&board[x][y-i]==player)
            w++;
        else break;//上
    }
    if(w>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&board[x+i][z]==player)
            mz++;
        else break;//右
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&board[x-i][y]==player)
            mz++;
        else break;//左
    }
    if(mz>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&y+i<15&&board[x+i][y+i]==player)
            nz++;
        else break;//右下
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&y-i>=0&&board[x-i][y-i]==player)
            nz++;
        else break;//左上
    }
    if(nz>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(x+i<15&&y-i>=0&&board[x+i][y-i]==player)
            z++;
        else break;//右上
    }
    for(i=1;i<5;i++)
    {
        if(x-i>=0&&y+i<15&&board[x-i][y+i]==player)
            z++;
        else break;//左下
    }
    if(z>=5)
        return player;
    return 0;
}


bool Game::isTerminal(int (*board)[Length], coordinate coor)
{
    if(getWinner(board, coor)==0)
        return true;//游戏尚未结束
    else
        return false;//游戏结束
}
// This is the starting point of Jonathan's code.

int temp_board[Length][Length];

void Game::manager(int (*board)[Length], int player)
{
    int i, j;
    std::copy(&temp_board[0][0], &temp_board[0][0] + Length*Length, &board[0][0]);
    
    if (player == 1) // black, AI
    {
        for (i = 0; i <= 14; i++)
        {
            for (j = 0; j <= 14; j++)
            {
                if (temp_board[i][j] == 2)
                {
                    temp_board[i][j] = 99;
                }
                else if (temp_board[i][j] == 1)
                {
                    temp_board[i][j] = 88;
                }
            }
        }
    }
    else if (player == 2)
    {
        for (i = 0; i <= 14; i++)
        {
            for (j = 0; j <= 14; j++)
            {
                if (temp_board[i][j] == 1)
                {
                    temp_board[i][j] = 99;
                }
                else if (temp_board[i][j] == 2)
                {
                    temp_board[i][j] = 88;
                }
            }
        }
    }
}

void Game::grader()
{
    int i, j, n, m, j_, i_, _j;
    
    for (i = 0; i <= 14; i++)
    {
        for (j = 0; j <= 14; j++)
        {
            if (temp_board[i][j] == 99)
            {
                for (n = -3; n <= 3; n++)
                {
                    j_ = j + n;
                    
                    i_ = i + n;
                    
                    _j = j - n;
                    
                    m = 4 - abs(n);
                    if (j_ >= 0 and j_ <= 14 and temp_board[i ][j_] < 88)
                    {
                        temp_board[i ][j_] += m;
                    }
                    if (i_ >= 0 and i_ <= 14 and temp_board[i_][j ] < 88)
                    {
                        temp_board[i_][j ] += m;
                    }
                    if (i_ >= 0 and i_ <= 14 and j_ >= 0 and j_ <= 14 and temp_board[i_][j_] < 88)
                    {
                        temp_board[i_][j_] += m;
                    }
                    if (i_ >= 0 and i_ <= 14 and _j >= 0 and _j <= 14 and temp_board[i_][_j] < 88)
                    {
                        temp_board[i_][_j] += m;
                    }
                }
            }
        }
    }
}

void Game::multiplier()
{
    int c = 0;
    
    int i, j, m, n;
    
    for (i = 0; i <= 14; i++) // →
    {
        for (j = 0; j <= 14; j++)
        {
            if (temp_board[i][j] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (j - 1 - c >= 0 and temp_board[i][j - 1 - c] != 88)
                {
                    temp_board[i][j - 1 - c] *= c;
                }
                if (j < 15 and temp_board[i][j] != 88)
                {
                    temp_board[i][j] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[i][j - c - 1] != 88)
        {
            temp_board[i][j - c - 1] *= c;
        }
        c = 0;
    }
    
    for (j = 0; j <= 14; j++) // ↓
    {
        for (i = 0; i <= 14; i++)
        {
            if (temp_board[i][j] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (i - 1 - c >= 0 and temp_board[i - 1 - c][j] != 88)
                {
                    temp_board[i - 1 - c][j] *= c;
                }
                if (i < 15 and temp_board[i][j] != 88)
                {
                    temp_board[i][j] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[i - c - 1][j] != 88)
        {
            temp_board[i - c - 1][j] *= c;
        }
        c = 0;
    }
    
    for (m = 0; m <= 13; m++) // ↘
    {
        for (n = 0; n <= 14 - m; n++)
        {
            if (temp_board[m + n][n] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (m + n - 1 - c >= 0 and n - 1 - c >= 0 and temp_board[m + n - 1 - c][n - 1 - c] != 88)
                {
                    temp_board[m + n - 1 - c][n - 1 - c] *= c;
                }
                if (m + n < 15 and n < 15 and temp_board[m + n][n] != 88)
                {
                    temp_board[m + n][n] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[m + n - c - 1][n - c - 1] != 88)
        {
            temp_board[m + n - c - 1][n - c - 1] *= c;
        }
        c = 0;
    }
    
    for (m = 1; m <= 13; m++) // ↘
    {
        for (n = 0; n <= 14 - m; n++)
        {
            if (temp_board[n][m + n] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (n - 1 - c >= 0 and m + n - 1 - c >= 0 and temp_board[n - 1 - c][m + n - 1 - c] != 88)
                {
                    temp_board[n - 1 - c][m + n - 1 - c] *= c;
                }
                if (n < 15 and m + n < 15 and temp_board[n][m + n] != 88)
                {
                    temp_board[n][m + n] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[n - c - 1][m + n - c - 1] != 88)
        {
            temp_board[n - c - 1][m + n - c - 1] *= c;
        }
        c = 0;
    }
    
    for (m = 0; m <= 13; m++) // ↗
    {
        for (n = 0; n <= 14 - m; n++)
        {
            if (temp_board[14 - n][m + n] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (14 - n + 1 + c < 15 and m + n - 1 - c >= 0 and temp_board[14 - n + 1 + c][m + n - 1 - c] != 88)
                {
                    temp_board[14 - n + 1 + c][m + n - 1 - c] *= c;
                }
                if (14 - n >= 0 and m + n < 15 and temp_board[14 - n][m + n] != 88)
                {
                    temp_board[14 - n][m + n] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[14 - n + c + 1][m + n - c - 1] != 88)
        {
            temp_board[14 - n + c + 1][m + n - c - 1] *= c;
        }
        c = 0;
    }
    
    for (m = 1; m <= 13; m++) // ↗
    {
        for (n = 0; n <= 14 - m; n++)
        {
            if (temp_board[14 - m - n][n] == 99)
            {
                c++;
            }
            else if (c != 0)
            {
                if (14 - m - n + 1 + c < 15 and n - 1 - c >= 0 and temp_board[14 - m - n + 1 + c][n - 1 - c] != 88)
                {
                    temp_board[14 - m - n + 1 + c][n - 1 - c] *= c;
                }
                if (14 - m - n >= 0 and n < 15 and temp_board[14 - m - n][n] != 88)
                {
                    temp_board[14 - m - n][n] *= c;
                }
                c = 0;
            }
        }
        if (c != 0 and temp_board[14 - m - n + c + 1][n - c - 1] != 88)
        {
            temp_board[14 - m - n + c + 1][n - c - 1] *= c;
        }
        c = 0;
    }
}


set<coordinate> Game::converter()
{
    set<coordinate> coordinates;

    int i, j, p = 3;
    
    for (i = 0; i <= 14; i++)
    {
        for (j = 0; j <= 14; j++)
        {
            if (temp_board[i][j] > 3)
            {
                p = temp_board[i][j];
            }
        }
    }
    for (i = 0; i <= 14; i++)
    {
        for (j = 0; j <= 14; j++)
        {
            if (temp_board[i][j] == p)
            {
                coordinate a;

                a.row = i;

                a.column = j;

                coordinates.insert(a);
            }
        }
    }
    return coordinates;
}

set<coordinate> Game::getValidMoves(int (*state)[Length], int player)
{
    manager(state, player);
    grader();
    multiplier();
    
    return converter();
}
