#include <iostream>
#include "Game.hpp"
#include <vector>
#include <map>


int main() {
    char k;
    system("color E0");//设置颜色
    do{
        Game *game = new Game();
        game->playGame();
        printf("Do you want a new turn?input y or n："); getchar(); scanf("%c",&k);
        while(k!='y'&&k!='n'){ printf("INPUT ERROR!\n"); scanf("%c",&k); }
        system("cls");
    }while(k=='y');
    printf("Thanks for using!\n");
    
    return 0;
}

