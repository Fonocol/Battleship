#include "header.h"


int main()
{
    PlayerInfo player1;
    PlayerInfo player2;

    srand(time(NULL));
    creat_player(&player1,&player2);
    run(&player1,&player2);
    
    return 0;
}
