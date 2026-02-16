#include <stdio.h>

int main(){

    // Variaveis
    int tabuleiro[10][10];
    int posicaomae = 0, posicaoaux=6;

    // Preenche o tabuleiro de 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    
    // Cria a primeira linha de A a J
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    //Mostra tabuleiro
    for(int i = 0; i < 10; i++){  // For responsavel por fazer em linha

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

}