#include <stdio.h>

int BatalhaNaval(){

    int tabuleiro[10][10];
    int posicaomae = 0, posicaoaux=6; // variaveis do tabuleiro de batalha naval com barcos diagonais

    // Preenche o tabuleiro e as matrizes de 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }        
    }

    printf("--------------------------------------\n");
    printf("            BATALHA NAVAL\n");
    printf("--------------------------------------\n\n");

    // Cria a primeira linha de A a J
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    //Mostra tabuleiro
    for(int i = 0; i < 10; i++){  // For responsavel por fazer as linha

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i); // IF responsavel por fazer a coluna de 1 a 10
        
        for(int j = 0; j < 10; j++){ // For responsavel por fazer as coluna 

            if (i ==2 && j>= 2 && j <= 4)                       // Cria barco 1
            {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);

            }else if(j == 7 && i>= 5 && i <= 7){                // Cria barco 2
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);

            }else if(i == posicaomae && j == posicaoaux){       // Cria barco 3 e 4

                if (posicaomae == 3 && posicaoaux == 9) {       // Para a criação do barco 3 e inicia criação do barco 4
                    posicaomae = 6;
                    posicaoaux = 2;
                    printf("%d ", tabuleiro[i][j]);

                } else if(posicaomae == 9 && posicaoaux == 5){  // Para a criação do barco 4
                    posicaomae = 1;
                    posicaoaux = 1;
                    printf("%d ", tabuleiro[i][j]);

                } else {
                    tabuleiro[i][j] = 3;
                    posicaomae++;
                    posicaoaux++;
                    printf("%d ", tabuleiro[i][j]);
                } 

            }else{                                  // Preenche de agua
                printf("%d ", tabuleiro[i][j]);
            }         
            
        }
        printf("\n");
    }
    return 0;
}

int MatrizCone(){

    int MatrizCone[10][10];
    int MCaux1 = 200, MCaux2 = 200, MCaux3 = 200, MCParada = 0;

    // Preenche o tabuleiro e as matrizes de 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            MatrizCone[i][j] = 0;
        }        
    }

    printf("--------------------------------------\n");
    printf("            MATRIZ EM CONE\n");
    printf("--------------------------------------\n\n");

    // Cria a primeira linha de A a J
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    //Mostra tabuleiro
    for(int i = 0; i < 10; i++){  // For responsavel por fazer as linha

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i); // IF responsavel por fazer a coluna de 1 a 10
        
        for(int j = 0; j < 10; j++){ // For responsavel por fazer as coluna 

            if (j == 4 && i == 2)
            {
                MatrizCone[i][j] = 3;
                printf("%d ", MatrizCone[i][j]);
                MCaux1 = 0;
                MCaux2 = 0;
                MCaux3 = 0;
                MCaux1 = j - 1;
                MCaux2 = j + 1;
                MCaux3 = i + 1;

            }else if(j >= MCaux1 && j <= MCaux2 && i == MCaux3){
                
                if (MCParada == 3)
                {
                    MCaux1 = 0;
                    MCaux2 = 0;
                    MCaux3 = 0;
                    printf("%d ", MatrizCone[i][j]);

                }else if(MCaux2 == j && MCaux3 == i){
                    MCaux1 = MCaux1 - 1;
                    MCaux2 = j + 1;
                    MCaux3 = i + 1;
                    MatrizCone[i][j] = 3;
                    printf("%d ", MatrizCone[i][j]);
                    MCParada++;

                }else{
                    MatrizCone[i][j] = 3;
                    printf("%d ", MatrizCone[i][j]);
                }
                

            }else{
                printf("%d ", MatrizCone[i][j]);
            }

        }
        printf("\n");
    }return 0;

}

int MatrizOctaedro(){

    int MatrizOctaedro[10][10];
    int MCaux1 = 200, MCaux2 = 200, MCaux3 = 200, MCParada = 0;

    // Preenche o tabuleiro e as matrizes de 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            MatrizOctaedro[i][j] = 0;
        }        
    }

    printf("--------------------------------------\n");
    printf("          MATRIZ EM OCTAEDRO\n");
    printf("--------------------------------------\n\n");

    // Cria a primeira linha de A a J
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    //Mostra tabuleiro
    for(int i = 0; i < 10; i++){  // For responsavel por fazer as linha

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i); // IF responsavel por fazer a coluna de 1 a 10
        
        for(int j = 0; j < 10; j++){ // For responsavel por fazer as coluna 

            if (j == 4 && i == 1)
            {
                MatrizOctaedro[i][j] = 3;
                printf("%d ", MatrizOctaedro[i][j]);
                MCaux1 = 0;
                MCaux2 = 0;
                MCaux3 = 0;
                MCaux1 = j - 1;
                MCaux2 = j + 1;
                MCaux3 = i + 1;

            }else if(j >= MCaux1 && j <= MCaux2 && i == MCaux3){
                
                if (MCParada == 3)
                {
                    MCaux1 = 0;
                    MCaux2 = 0;
                    MCaux3 = 0;
                    printf("%d ", MatrizOctaedro[i][j]);

                }else if(MCaux2 == j && MCaux3 == i){
                    MCaux1 = MCaux1 - 1;
                    MCaux2 = j + 1;
                    MCaux3 = i + 1;
                    MatrizOctaedro[i][j] = 3;
                    printf("%d ", MatrizOctaedro[i][j]);
                    MCParada++;

                }else{
                    MatrizOctaedro[i][j] = 3;
                    printf("%d ", MatrizOctaedro[i][j]);
                }
                

            }else if(MCParada==3){
                
                if (MCaux1 == 0)
                {
                    MCaux1 = 1;
                    MCaux2 = 7;
                    MCaux3 = i +1;
                    MatrizOctaedro[i][j] = 0; // validador de local
                    printf("%d ", MatrizOctaedro[i][j]);

                }else if( j >= MCaux1 && j <= MCaux2){
                    
                    
                    MatrizOctaedro[i][j] = 3;
                    printf("%d ", MatrizOctaedro[i][j]);

                }else if(MCaux3 == i){
                    MCaux1 = MCaux1 + 1;
                    MCaux2 = MCaux2 - 1;
                    MCaux3 = i + 1;
                    printf("%d ", MatrizOctaedro[i][j]);

                }else{
                    // MatrizOctaedro[i][j] = 1; // testador de local
                    printf("%d ", MatrizOctaedro[i][j]);
                }

            }else{
                printf("%d ", MatrizOctaedro[i][j]);
            }

        }
        printf("\n");
    }return 0;

}

int main(){

    // Variaveis
    int MatrizCruz[10][10];

    MatrizOctaedro();

}