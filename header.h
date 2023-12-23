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

enum{
    humain,
    machine,
};

typedef struct PlayerInfo{
    char nom[20];
    int age;
    int matrice[SIZE][SIZE];
    int Print[SIZE][SIZE];
}PlayerInfo;

typedef struct BATTLESHIP{
    char name[50];
    int enemy;
    int currentplayer;
    PlayerInfo player1;
    PlayerInfo player2;
}BATTLESHIP;


bool Enter(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE]);
void Empty(int matrice[SIZE][SIZE]);
void generate_sceen(int matrice[SIZE][SIZE],int enemy);
void print(BATTLESHIP *battaille);
void printdebug(BATTLESHIP *battaille);
void creat_player(BATTLESHIP *battaille);
void run(BATTLESHIP *battaille);
int loadpartie(const char *folderPath, const char *gameName, BATTLESHIP *battaille) ;
void savepartie(char *folderPath,const BATTLESHIP *battaille) ;