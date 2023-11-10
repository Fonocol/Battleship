#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define SIZE 10
#define WATHER 0
#define Nbr 8

typedef enum navir{
    Torpilleur=2,
    Contre_torpilleur,
    Croiseur,
    Porte_avions,
}Navir;

enum DIrection{
    left,
    right,
    up,
    down,
};

typedef struct PlayerInfo{
    char nom[20];
    int age;
    int matrice[SIZE][SIZE];
    int Print[SIZE][SIZE];
}PlayerInfo;


bool Enter(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE]);
void Empty(int matrice[SIZE][SIZE]);
void generate_sceen(int matrice[SIZE][SIZE]);
void print(PlayerInfo *player1,PlayerInfo *player2);
void creat_player(PlayerInfo *player1, PlayerInfo *player2);
void run(PlayerInfo *player1,PlayerInfo *player2);