#include <stdio.h>

int main(){

    // Preenche o tabuleiro de 0
    int tabuleiro[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }

    // Coloca navios no tabuleiro
    
    
    // Mostra o tabuleiro
    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    for(int i = 0; i < 10; i++){

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i);
        
        for(int j = 0; j < 10; j++){

            if (i ==2 && j>= 2 && j <= 4)
            {
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);
            }else if(j == 7 && i>= 5 && i <= 7){
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);
            }else{
                printf("%d ", tabuleiro[i][j]);
            }         
            
        }
        printf("\n");
    }

}