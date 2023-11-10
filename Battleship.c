#include "header.h"


bool Enter(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE]){
    if (Direction == left)
    {
        if (col-navir < 0)
        {
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line][col-i] != 0)
                {
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line][col-i]=1; 
            }
            
        }
    }
    else if (Direction == right)
    {
        if ((SIZE-col)-navir < 0)
        {
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line][col+i] != 0)
                {
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line][col+i]=1; 
            }
            
        }
    }
    else if (Direction == up)
    {
        if (line-navir < 0)
        {
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line-i][col] != 0)
                {
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line-i][col]=1; 
            }
            
        }
    }
    else if (Direction == down)
    {
        if ((SIZE-line)-navir < 0)
        {
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line+i][col] != 0)
                {
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line+i][col]=1;
            }
            
        }
    }
    return true;
}

void Empty(int matrice[SIZE][SIZE]){
    
    for (int line = 0; line < SIZE; line++){
        for (int colone = 0; colone < SIZE; colone++){
            matrice[line][colone] = WATHER;
        } 
    }
}


void print(PlayerInfo *player1,PlayerInfo *player2){
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                              BATTLESHIP                                                                     \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------Player1---------------------------------------------------------Player2---------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                printf("||%d|||",j+1);
            }
            else{
                
                if (j==-1){
                    if (i==SIZE-1)
                    {
                        printf("||%d||",i+1);
                    }
                    else
                    {
                        printf("||%d|||",i+1);
                    }
                    
                    
                    
                }
                else if (j==SIZE-1)
                {
                    if (player1->Print[i][j]==WATHER){
                        printf("     ||");
                    }
                    else if(player1->Print[i][j]==1){
                        printf("  x  ||");
                    }
                    else
                    {
                        printf("  o  ||");
                    }
                    
                }
                
                else{
                    if (player1->Print[i][j]==WATHER){
                        printf("     |");
                    }
                    else if(player1->Print[i][j]==1){
                        printf("  x  |");
                    }
                    else
                    {
                        printf("  o  |");
                    }
                }
            }  
        }
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                printf("||%d|||",j+1);
            }
            else{
                
                if (j==-1){
                    if (i==SIZE-1)
                    {
                        printf("||%d||",i+1);
                    }
                    else
                    {
                        printf("||%d|||",i+1);
                    }
                    
                    
                    
                }
                else if (j==SIZE-1)
                {
                    if (player2->Print[i][j]==WATHER){
                        printf("     ||");
                    }
                    else if(player2->Print[i][j]==1){
                        printf("  x  ||");
                    }
                    else
                    {
                        printf("  o  ||");
                    }
                    
                }
                
                else{
                    if (player2->Print[i][j]==WATHER){
                        printf("     |");
                    }
                    else if(player2->Print[i][j]==1){
                        printf("  x  |");
                    }
                    else
                    {
                        printf("  o  |");
                    }
                }
            }  
        }
        printf("\n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}

void generate_sceen(int matrice[SIZE][SIZE]){

    int _Navir[Nbr] = {Torpilleur,Contre_torpilleur,Croiseur,Porte_avions,Torpilleur,Contre_torpilleur,Croiseur,Porte_avions};

    Empty(matrice);

    for (int navir = 0; navir < Nbr; navir++)
    {
        //int navir =rand()%Nbr;
        do
        {
            int line = rand()%SIZE;
            int col = rand()%SIZE;
            int Direction = rand()%4;
            if (Enter(_Navir[navir],line,Direction,col,matrice))
            {
                break;
            }
            
        } while (1);
        
    } 
}

void creat_player(PlayerInfo *player1, PlayerInfo *player2){
    printf("Nom du joueur 1 :");
    scanf("%s",player1->nom);
    printf("age du joueur 1 :");
    scanf("%d",&player1->age);
    printf("Nom du joueur 2 :");
    scanf("%s",player2->nom);
    printf("age du joueur 2 :");
    scanf("%d",&player2->age);
    generate_sceen(player1->matrice);
    generate_sceen(player2->matrice);
    Empty(player1->Print);
    Empty(player2->Print);
}

bool winplayer_i(PlayerInfo *player_j){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (player_j->matrice[i][j]==1){
                return false;
            }
        }
    }
    return true;
}

void run(PlayerInfo *player1,PlayerInfo *player2){
    int x;
    int y;
    while (!winplayer_i(player1) && !winplayer_i(player2))
    {
        print(player1,player2);
        printf("au joueur 1 de jouer :\n");
        printf("position x :");
        scanf("%d",&x);
        printf("position y :");
        scanf("%d",&y);
        if (player2->matrice[x-1][y-1])
        {
            //player 2 est toucher
            player2->Print[x-1][y-1]= 1;
            player2->matrice[x-1][y-1]= 0;
        }else
        {
            player2->Print[x-1][y-1]= -1;
        }
        system("cls");
        print(player1,player2);

        printf("au joueur 2 de jouer :\n");
        printf("position x :");
        scanf("%d",&x);
        printf("position y :");
        scanf("%d",&y);
        if (player1->matrice[x-1][y-1])
        {
            //player 2 est toucher
            player1->Print[x-1][y-1]= 1;
            player1->matrice[x-1][y-1]= 0;
        }else
        {
            player1->Print[x-1][y-1]= -1;
        }
        Sleep(100);
        system("cls");

    }
    

}