#include "header.h"


bool Enter(int navir, int line,int Direction,int col,int matrice[SIZE][SIZE]){
    if (Direction == left)
    {
        if (col-navir < 0)
        {
            printf("le bateaux est trop long pour la direction left\n");
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line][col-i] != 0)
                {
                    printf("collision entre deux bateaux\n");
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line][col-i]=navir; 
            }
            
        }
    }
    else if (Direction == right)
    {
        if ((SIZE-col)-navir < 0)
        {
            printf("le bateaux est trop long pour la direction right\n");
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line][col+i] != 0)
                {
                    printf("collision entre deux bateaux\n");
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line][col+i]= navir; 
            }
            
        }
    }
    else if (Direction == up)
    {
        if (line-navir < 0)
        {
            printf("le bateaux est trop long pour la direction up\n");
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line-i][col] != 0)
                {
                    printf("collision entre deux bateaux\n");
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line-i][col]=navir; 
            }
            
        }
    }
    else if (Direction == down)
    {
        if ((SIZE-line)-navir < 0)
        {
            printf("le bateaux est trop long pour la direction down\n");
            return false;
        }else
        {
            for (int i = 0; i < navir; i++)
            {
                if (matrice[line+i][col] != 0)
                {
                    printf("collision entre deux bateaux\n");
                    return false;
                }   
            }
            for (int i = 0; i < navir; i++)
            {
                matrice[line+i][col]= navir;
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


void printmatrice(int matrice[SIZE][SIZE]){

    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }     
            }
            else{
                
                if (j==-1){
                    printf(" %d ", i ); 
                }  
                else{
                    if (matrice[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else{
                        printf("\033[47m   ");
                        printf("\033[0m");
                    }
                }
            }  
        }
        printf("\n");
    }
}



void print(BATTLESHIP *battaille){
    printf("---------------------------------------------------------------------\n");
    printf("|                         BATTLESHIP                                 |\n");
    printf("|                                                                    |\n");
    printf("|        %s                                    %s          |\n",battaille->player1.nom,battaille->player2.nom);
    printf("---------------------------------------------------------------------\n");

    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }     
            }
            else{
                
                if (j==-1){
                    printf(" %d ", i ); 
                }  
                else{
                    if (battaille->player1.Print[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else if(battaille->player1.Print[i][j] == 1){
                        printf("\033[47m   ");
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[40m\033[31m x ");
                        printf("\033[0m");
                    }
                }
            }  
        }
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }     
            }
            else{
                
                if (j==-1){
                    printf("|%d|", i ); 
                }  
                else{
                    if (battaille->player2.Print[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else if(battaille->player2.Print[i][j] == 1){
                        printf("\033[47m   ");
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[40m\033[31m x ");
                        printf("\033[0m");
                    }
                }
            }  
        }
        printf("\n");
        //printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}



void printdebug(BATTLESHIP *battaille){
    printf("---------------------------------------------------------------------\n");
    printf("|                             DEBUG                                  |\n");
    printf("|                                                                    |\n");
    printf("|        %s                                    %s          |\n",battaille->player1.nom,battaille->player2.nom);
    printf("---------------------------------------------------------------------\n");

    for (int i = -1; i < SIZE; i++){
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }     
            }
            else{
                
                if (j==-1){
                    printf(" %d ", i ); 
                }  
                else{
                    if (battaille->player1.matrice[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else if(battaille->player1.matrice[i][j] != WATHER){
                        printf("\033[47m\033[32m %d ",battaille->player1.matrice[i][j]);
                        printf("\033[0m");
                    }
                    else
                    {
                        printf(" o ");
                    }
                }
            }  
        }
        for (int j = -1; j < SIZE; j++){
            if (i==-1){
                if (j== -1)
                {
                    printf("   ");
                }
                else{
                    printf(" %d ", j );
                }     
            }
            else{
                
                if (j==-1){
                    printf("|%d|", i ); 
                }  
                else{
                    if (battaille->player2.matrice[i][j]==WATHER){
                        printf("\033[40m   ");
                        printf("\033[0m");
                    }
                    else if(battaille->player2.matrice[i][j] != WATHER){
                        printf("\033[47m\033[32m %d ",battaille->player2.matrice[i][j]);
                        printf("\033[0m");
                    }
                    else
                    {
                        printf(" o ");
                    }
                }
            }  
        }
        printf("\n");
        //printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
    }
}



void generate_sceen(int matrice[SIZE][SIZE],int mode){

    int _Navir[Nbr] = {Torpilleur,Contre_torpilleur,Croiseur,Porte_avions,Torpilleur,Contre_torpilleur,Croiseur,Porte_avions};

    Empty(matrice);

    for (int navir = 0; navir < Nbr; navir++)
    {
        //int navir =rand()%Nbr;
        if (mode == 0)
        {
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
              ///aff

        }else
        {
            int line ;
            int col ;
            int Direction ;
            do
            {
                //system("cls");
                printmatrice(matrice);
                
                
                printf("valeur de x\n");
                scanf("%d",&line);

                printf("valeur de y\n");
                scanf("%d",&col);

                printf("direction left(0),right(1),up(2),down(3),\n");
                scanf("%d",&Direction);
                
            } while (col<0 || col>=SIZE  || line<0 || line>=SIZE  ||Direction <0 || Direction >=4 || !Enter(_Navir[navir],line,Direction,col,matrice));
            
        }
        
        
    } 
}

void creat_player(BATTLESHIP *battaille){
    
    int humainoumachine;
    int mode;
    int partie;
    printf("continuer une partie (0) cree une partie (1)\n");
    scanf("%d",&partie);

    if (partie == 0)
    {
        char gameName[50];
        printf("Entrez le nom de la partie que vous souhaitez continuer : \n");
        scanf("%s", gameName);
        if (loadpartie("data", gameName, battaille)) {
            printf("Chargement reussi : Nom : %s", gameName);
            run(battaille);
        } else {
            printf("Chargement de la partie échoué.\n");
        }

    }
    else
    {
        
        
        printf("jouer contre un humain(0) contre la machine(1)\n");
        scanf("%d",&humainoumachine);
        printf("placement automatique des bateaux tape (0) sinon tape (1)\n");
        scanf("%d",&mode);
        printf("donner un nom a votre partie:\n");
        scanf("%s",battaille->name);

        printf("Nom du joueur 1 :\n");
        scanf("%s",battaille->player1.nom);
        printf("age du joueur 1 :\n");
        scanf("%d",&battaille->player1.age);


        if (humainoumachine == humain)
        {
            battaille->enemy = humain;
            if (mode == 0)
            {
                
                printf("Nom du joueur 2 :\n");
                scanf("%s",battaille->player2.nom);
                printf("age du joueur 2 :\n");
                scanf("%d",&battaille->player2.age);
                generate_sceen(battaille->player1.matrice,0);
                generate_sceen(battaille->player2.matrice,0);
            }else
            {
                generate_sceen(battaille->player1.matrice,1);
                generate_sceen(battaille->player2.matrice,1);
            }
        }else
        {
            battaille->enemy = machine;
            strcpy(battaille->player2.nom , "Machine");
            battaille->player2.age = 20;
            generate_sceen(battaille->player2.matrice,0);
            if (mode == 0 )
            {
                generate_sceen(battaille->player1.matrice,0);
                
            }else
            {
                generate_sceen(battaille->player1.matrice,1);
            }
        
        }

        
        Empty(battaille->player1.Print);
        Empty(battaille->player2.Print);
        savepartie("data",battaille);
        run(battaille);

        /* code */
    }
    
}

bool winplayer_i(PlayerInfo player_j){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (player_j.matrice[i][j]!= WATHER){
                return false;
            }
        }
    }
    return true;
}


void tirerMachine(BATTLESHIP *battaille) {
    int x = -1, y = -1;

    // Chercher une case non encore explorée à proximité d'un tir réussi
    for (int i = 0; i < SIZE && x == -1; i++) {
        for (int j = 0; j < SIZE && x == -1; j++) {
            if (battaille->player1.Print[i][j] == 1) {
                // Tirer autour de la dernière position réussie
                for (int k = -1; k <= 1 && x == -1; k++) {
                    for (int l = -1; l <= 1 && x == -1; l++) {
                        int newX = i + k;
                        int newY = j + l;
                        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE &&
                            battaille->player1.Print[newX][newY] == WATHER) {
                            x = newX;
                            y = newY;
                        }
                    }
                }
            }
        }
    }

    // Si aucune case n'a été trouvée à proximité des tirs réussis, tirer au hasard
    if (x == -1) {
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (battaille->player1.Print[x][y] != WATHER);
    }

    // Effectuer le tir
    if (battaille->player1.matrice[x][y] != WATHER) {
        battaille->player1.Print[x][y] = 1; // Touché
        battaille->player1.matrice[x][y] = WATHER;
    } else {
        if (battaille->player1.Print[x][y]==WATHER)
        {
            battaille->player1.Print[x][y] = -1; // Raté
        }  
    }
}

void run(BATTLESHIP *battaille){
    int x;
    int y;
    while (!winplayer_i(battaille->player1) && !winplayer_i(battaille->player2))
    {
        printdebug(battaille);
        print(battaille);
        printf("c'est a %s de jouer :\n",battaille->player1.nom);
        printf("position x :");
        scanf("%d",&x);
        printf("position y :");
        scanf("%d",&y);
        if (battaille->player2.matrice[x][y] != WATHER)
        {
            //player 2 est toucher
            battaille->player2.Print[x][y]= 1;
            battaille->player2.matrice[x][y]= WATHER;
        }else
        {
            if (battaille->player2.Print[x][y]==WATHER)
            {
                battaille->player2.Print[x][y] = -1; // Raté
            }             
        }
        system("cls");
        savepartie("data",battaille);
        printdebug(battaille);
        print(battaille);

        if (battaille->enemy == humain)
        {
            printf("c'est a %s de jouer :\n",battaille->player2.nom);
            printf("position x :");
            scanf("%d",&x);
            printf("position y :");
            scanf("%d",&y);
            if (battaille->player1.matrice[x][y] != WATHER)
            {
                //player 2 est toucher
                battaille->player1.Print[x][y]= 1;
                battaille->player1.matrice[x][y]= WATHER;
            }else
            {
                if (battaille->player1.Print[x][y]==WATHER)//security
                {
                    battaille->player1.Print[x][y] = -1; // Raté
                }  
            }          

        }else
        {
            tirerMachine(battaille);
            /*printf("c'est a %s de jouer :\n",battaille->player2.nom);
            Sleep(2500);
            x = rand()%SIZE;
            y = rand()%SIZE;*/
        }
    

        savepartie("data",battaille);
        Sleep(100);
        system("cls");

    }
    

}



void savepartie(char *folderPath,const BATTLESHIP *battaille) {
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s.txt", folderPath, battaille->name);
    FILE *file = fopen(filePath, "w");
    
    if (file) {
        fprintf(file, "NomPartie : %s\n", battaille->name);
        fprintf(file, "NomPlayer1 : %s\n", battaille->player1.nom);
        fprintf(file, "NomPlayer2 : %s\n", battaille->player2.nom);
        fprintf(file, "AgePlayer1 : %d\n", battaille->player1.age);
        fprintf(file, "AgePlayer2 : %d\n", battaille->player2.age);        
        fprintf(file, "joueurCourant : %d\n", battaille->currentplayer);
        fprintf(file, "Enemies : %d\n", battaille->enemy);

        for (int i = 0; i < SIZE; i++) {;
            for (int j = 0; j < SIZE; j++) {
                fprintf(file, "player1matrice[%d][%d] : %d\n",i,j, battaille->player1.matrice[i][j]);
                fprintf(file, "player1print[%d][%d] : %d\n",i,j, battaille->player1.Print[i][j]);
                fprintf(file, "player2matrice[%d][%d] : %d\n",i,j, battaille->player2.matrice[i][j]);
                fprintf(file, "player2print[%d][%d] : %d\n",i,j, battaille->player2.Print[i][j]);
            }
        }
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier pour enregistrement.\n");
    }
}




int loadpartie(const char *folderPath, const char *gameName, BATTLESHIP *battaille) {
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s.txt", folderPath, gameName);
    FILE *file = fopen(filePath, "r");
    
    if (file) {

        fscanf(file, "NomPartie : %s\n", battaille->name);
        fscanf(file, "NomPlayer1 : %s\n", battaille->player1.nom);
        fscanf(file, "NomPlayer2 : %s\n", battaille->player2.nom);
        fscanf(file, "AgePlayer1 : %d\n", &battaille->player1.age);
        fscanf(file, "AgePlayer2 : %d\n", &battaille->player2.age);        
        fscanf(file, "joueurCourant : %d\n", &battaille->currentplayer);
        fscanf(file, "Enemies : %d\n", &battaille->enemy);



        for (int i = 0; i < SIZE; i++) {;
            for (int j = 0; j < SIZE; j++) {
        fscanf(file, "player1matrice[%d][%d] : %d\n",&i,&j, &battaille->player1.matrice[i][j]);
        fscanf(file, "player1print[%d][%d] : %d\n",&i,&j, &battaille->player1.Print[i][j]);
        fscanf(file, "player2matrice[%d][%d] : %d\n",&i,&j, &battaille->player2.matrice[i][j]);
        fscanf(file, "player2print[%d][%d] : %d\n",&i,&j, &battaille->player2.Print[i][j]);
            }
        }

        fclose(file);
        return 1;  // La lecture a réussi
    } else {
        printf("Erreur lors de l'ouverture du fichier pour chargement.\n");
        return 0;  // La lecture a échoué
    }
}

