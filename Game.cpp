//
//  Game.cpp
//  AI_HW
//
//  Created by Ashley on 11/10/16.
//  Copyright © 2016 Ashley. All rights reserved.
//

#include "Game.hpp"


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
