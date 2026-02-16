#include <stdio.h>

int main(){

    // Preenche o tabuleiro de 0
    int TAM = 10;
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    
    // Mostra o tabuleiro
    printf(" ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", 1 + i);
        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}