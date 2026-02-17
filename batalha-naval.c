#include <stdio.h>

/**
 * FUNÇÃO: BatalhaNaval
 * 
 * OBJETIVO: Criar e exibir um tabuleiro 10x10 da Batalha Naval com 4 navios posicionados
 * 
 * POSIÇÕES DOS NAVIOS:
 * - Navio 1: Linha 2 (índice 2), colunas 2, 3 e 4 (posição horizontal)
 * - Navio 2: Coluna 7 (índice 7), linhas 5, 6 e 7 (posição vertical)
 * - Navio 3: Diagonal da posição (0,6) até (3,9) (posição diagonal descendente)
 * - Navio 4: Diagonal da posição (6,2) até (9,5) (posição diagonal descendente)
 * 
 * REPRESENTAÇÃO:
 * - 0 = Água
 * - 3 = Parte do navio
 */
int BatalhaNaval(){

    int tabuleiro[10][10];          // Matriz principal que representa o tabuleiro 10x10
    int posicaomae = 0, posicaoaux=6; // Variáveis de controle para criação dos navios diagonais
                                     // posicaomae controla a linha, posicaoaux controla a coluna
                                     // Iniciam em (0,6) para o primeiro navio diagonal

    // INICIALIZAÇÃO: Preenche todo o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }        
    }

    // CABEÇALHO: Título do jogo com formatação visual
    printf("--------------------------------------\n");
    printf("            BATALHA NAVAL\n");
    printf("--------------------------------------\n\n");

    // CABEÇALHO DAS COLUNAS: Cria a primeira linha com letras de A a J
    printf("  ");  // Espaço para alinhamento com os números das linhas
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);  // Converte número para letra (0->A, 1->B, etc.)
    }
    printf("\n");

    // EXIBIÇÃO DO TABULEIRO: Loop principal para mostrar linha por linha
    for(int i = 0; i < 10; i++){  // i = linha atual (0 a 9)

        // NÚMERO DA LINHA: Formata a exibição do número da linha (1 a 10)
        // Operador ternário para ajustar espaçamento (linha 10 tem menos espaços)
        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i);
        
        for(int j = 0; j < 10; j++){ // j = coluna atual (0 a 9)

            // [NAVIO 1] Posição horizontal na linha 2 (índice 2), colunas 2,3,4
            if (i ==2 && j>= 2 && j <= 4)                       
            {
                tabuleiro[i][j] = 3;      // Marca posição como navio
                printf("%d ", tabuleiro[i][j]);  // Exibe o valor

            // [NAVIO 2] Posição vertical na coluna 7 (índice 7), linhas 5,6,7
            }else if(j == 7 && i>= 5 && i <= 7){                
                tabuleiro[i][j] = 3;
                printf("%d ", tabuleiro[i][j]);

            // [NAVIOS 3 e 4] Posições diagonais controladas pelas variáveis posicaomae/posicaoaux
            }else if(i == posicaomae && j == posicaoaux){       

                // VERIFICAÇÃO DE TRANSIÇÃO: Quando chega ao fim do navio 3 (3,9)
                if (posicaomae == 3 && posicaoaux == 9) {       
                    // Reinicia as variáveis para começar o navio 4 em (6,2)
                    posicaomae = 6;
                    posicaoaux = 2;
                    printf("%d ", tabuleiro[i][j]);  // Exibe (será 0 pois não foi marcado)

                // VERIFICAÇÃO DE FINAL: Quando chega ao fim do navio 4 (9,5)
                } else if(posicaomae == 9 && posicaoaux == 5){  
                    // Reseta as variáveis (não usado depois)
                    posicaomae = 1;
                    posicaoaux = 1;
                    printf("%d ", tabuleiro[i][j]);  // Exibe (será 0)

                // CONSTRUÇÃO DOS NAVIOS DIAGONAIS: Marca posição e avança diagonal
                } else {
                    tabuleiro[i][j] = 3;      // Marca como navio
                    posicaomae++;              // Avança para próxima linha
                    posicaoaux++;               // Avança para próxima coluna
                    printf("%d ", tabuleiro[i][j]);  // Exibe (valor 3)
                } 

            // ÁGUA: Se não é posição de navio, exibe 0
            }else{                                  
                printf("%d ", tabuleiro[i][j]);
            }         
            
        }
        printf("\n");  // Quebra de linha após cada linha do tabuleiro
    }
    return 0;  // Retorno padrão (embora o valor não seja usado)
}

/**
 * Função: MatrizCone
 * 
 * Objetivo: Criar e exibir um padrão em formato de cone/árvore em um tabuleiro 10x10
 * 
 * PADRÃO: Forma um cone apontando para cima com vértice em (2,4)
 *         Linha 2: coluna 4
 *         Linha 3: colunas 3,4,5
 *         Linha 4: colunas 2,3,4,5,6
 *         Linha 5: colunas 1,2,3,4,5,6,7
 * 
 * REPRESENTAÇÃO:
 * - 0 = Espaço vazio
 * - 3 = Parte do cone
 */
int MatrizCone(){

    int MatrizCone[10][10];          // Matriz para o padrão cone
    int MCaux1 = 200, MCaux2 = 200, MCaux3 = 200, MCParada = 0;
    // Variáveis de controle:
    // MCaux1 = limite esquerdo da linha atual
    // MCaux2 = limite direito da linha atual
    // MCaux3 = linha atual sendo processada
    // MCParada = contador para controlar expansão (conta 3 linhas)

    // INICIALIZAÇÃO: Preenche matriz com zeros
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            MatrizCone[i][j] = 0;
        }        
    }

    // CABEÇALHO DO TABULEIRO (similar à função anterior)
    printf("--------------------------------------\n");
    printf("            MATRIZ EM CONE\n");
    printf("--------------------------------------\n\n");

    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    // EXIBIÇÃO E CONSTRUÇÃO DO PADRÃO
    for(int i = 0; i < 10; i++){  // i = linha atual

        // Número da linha
        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i);
        
        for(int j = 0; j < 10; j++){ // j = coluna atual

            // VÉRTICE DO CONE: Ponto inicial do padrão na linha 2 (índice 2), coluna 4 (índice 4)
            if (j == 4 && i == 2)
            {
                MatrizCone[i][j] = 3;  // Marca o vértice
                printf("%d ", MatrizCone[i][j]);
                
                // Inicializa variáveis de controle para expandir o cone
                MCaux1 = 0;  
                MCaux2 = 0;
                MCaux3 = 0;
                MCaux1 = j - 1;  // Limite esquerdo = coluna 3
                MCaux2 = j + 1;  // Limite direito = coluna 5
                MCaux3 = i + 1;  // Próxima linha = linha 3

            // CORPO DO CONE: Verifica se está dentro dos limites atuais
            }else if(j >= MCaux1 && j <= MCaux2 && i == MCaux3){
                
                // Verifica se já expandiu 3 vezes (atingiu largura máxima)
                if (MCParada == 3)
                {
                    // Reseta variáveis (para não expandir mais)
                    MCaux1 = 0;
                    MCaux2 = 0;
                    MCaux3 = 0;
                    printf("%d ", MatrizCone[i][j]);  // Exibe (pode ser 0)

                // MOMENTO DE EXPANSÃO: Quando chega no limite direito da linha atual
                }else if(MCaux2 == j && MCaux3 == i){
                    // Expande os limites para a próxima linha
                    MCaux1 = MCaux1 - 1;  // Esquerda: uma coluna a mais
                    MCaux2 = j + 1;        // Direita: uma coluna a mais
                    MCaux3 = i + 1;        // Próxima linha
                    MatrizCone[i][j] = 3;  // Marca posição atual
                    printf("%d ", MatrizCone[i][j]);
                    MCParada++;  // Incrementa contador de expansões

                // PREENCHIMENTO NORMAL: Apenas marca a posição atual
                }else{
                    MatrizCone[i][j] = 3;
                    printf("%d ", MatrizCone[i][j]);
                }
                

            // ÁREA FORA DO CONE: Exibe 0
            }else{
                printf("%d ", MatrizCone[i][j]);
            }

        }
        printf("\n");
    }
    return 0;
}

/**
 * Função: MatrizOctaedro
 * 
 * Objetivo: Criar e exibir um padrão em formato de octaedro (losango) em um tabuleiro 10x10
 * 
 * PADRÃO: Forma um losango com centro na linha 1, coluna 4
 *         Parte superior (já implementada): expansão gradual até linha 4
 *         Parte inferior (tentativa de implementação): contração gradual a partir da linha 5
 * 
 * OBSERVAÇÃO: Esta implementação tem complexidade alta. Leia com atenção.
 */
int MatrizOctaedro(){

    int MatrizOctaedro[10][10];
    int MCaux1 = 200, MCaux2 = 200, MCaux3 = 200, MCParada = 0;
    // Variáveis de controle similares à função Cone, mas para octaedro

    // INICIALIZAÇÃO
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            MatrizOctaedro[i][j] = 0;
        }        
    }

    // CABEÇALHO
    printf("--------------------------------------\n");
    printf("          MATRIZ EM OCTAEDRO\n");
    printf("--------------------------------------\n\n");

    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    // EXIBIÇÃO E CONSTRUÇÃO
    for(int i = 0; i < 10; i++){  // i = linha atual

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i);
        
        for(int j = 0; j < 10; j++){ // j = coluna atual

            // VÉRTICE SUPERIOR: Ponto central do octaedro (linha 1, coluna 4)
            if (j == 4 && i == 1)
            {
                MatrizOctaedro[i][j] = 3;
                printf("%d ", MatrizOctaedro[i][j]);
                // Inicializa variáveis para expansão
                MCaux1 = 0;
                MCaux2 = 0;
                MCaux3 = 0;
                MCaux1 = j - 1;  // Limite esquerdo: coluna 3
                MCaux2 = j + 1;  // Limite direito: coluna 5
                MCaux3 = i + 1;  // Próxima linha: linha 2

            // PARTE SUPERIOR DO OCTAEDRO (expansão) - similar ao cone
            }else if(j >= MCaux1 && j <= MCaux2 && i == MCaux3){
                
                // Após 3 expansões, termina parte superior
                if (MCParada == 3)
                {
                    MCaux1 = 0;
                    MCaux2 = 0;
                    MCaux3 = 0;
                    printf("%d ", MatrizOctaedro[i][j]);

                // Expansão: aumenta largura a cada linha
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
                

            // PARTE INFERIOR DO OCTAEDRO (contração) - implementação complexa
            }else if(MCParada==3){
                
                // Reinicialização para começar a contração
                if (MCaux1 == 0)
                {
                    MCaux1 = 1;      // Limite esquerdo inicial da contração
                    MCaux2 = 7;      // Limite direito inicial da contração
                    MCaux3 = i +1;   // Próxima linha
                    MatrizOctaedro[i][j] = 0; // Mantém como 0 (água)
                    printf("%d ", MatrizOctaedro[i][j]);

                // Dentro dos limites atuais da contração
                }else if( j >= MCaux1 && j <= MCaux2){
                    
                    MatrizOctaedro[i][j] = 3;  // Marca como parte do octaedro
                    printf("%d ", MatrizOctaedro[i][j]);

                // Fim da linha atual: prepara para próxima linha (contração)
                }else if(MCaux3 == i){
                    MCaux1 = MCaux1 + 1;  // Aumenta limite esquerdo (contrai)
                    MCaux2 = MCaux2 - 1;  // Diminui limite direito (contrai)
                    MCaux3 = i + 1;       // Próxima linha
                    printf("%d ", MatrizOctaedro[i][j]);  // Exibe valor atual (0)

                }else{
                    printf("%d ", MatrizOctaedro[i][j]);  // Exibe 0
                }

            // Área fora do padrão
            }else{
                printf("%d ", MatrizOctaedro[i][j]);
            }

        }
        printf("\n");
    }
    return 0;
}

/**
 * Função: MatrizCruz
 * 
 * Objetivo: Criar e exibir um padrão em formato de cruz em um tabuleiro 10x10
 * 
 * PADRÃO: Uma cruz centralizada:
 *         - Braço vertical: linha 4 (índice 4), colunas 1 a 7 (índices 1 a 7)
 *         - Braço horizontal: coluna 4 (índice 4), linhas 1 a 7 (índices 1 a 7)
 * 
 * REPRESENTAÇÃO:
 * - 0 = Espaço vazio
 * - 3 = Parte da cruz
 */
int MatrizCruz(){

    int MatrizCruz[10][10];

    // INICIALIZAÇÃO
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            MatrizCruz[i][j] = 0;
        }        
    }

    // CABEÇALHO
    printf("--------------------------------------\n");
    printf("            MATRIZ EM CRUZ\n");
    printf("--------------------------------------\n\n");

    printf("  ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c",'A' + i);
    }
    printf("\n");

    // EXIBIÇÃO E CONSTRUÇÃO DA CRUZ
    for(int i = 0; i < 10; i++){  // i = linha atual

        ( i == 9) ? printf("%d ", 1 + i) : printf(" %d ", 1 + i);
        
        for(int j = 0; j < 10; j++){ // j = coluna atual

            // BRAÇO VERTICAL: Todas as linhas de 1 a 7 na coluna 4
            if (j == 4 && i >= 1 && i <= 7)
            {
                MatrizCruz[i][j] = 3;
                printf("%d ", MatrizCruz[i][j]);

            // BRAÇO HORIZONTAL: Todas as colunas de 1 a 7 na linha 4
            }else if(i == 4 && j >= 1 && j <= 7){
                MatrizCruz[i][j] = 3;
                printf("%d ", MatrizCruz[i][j]);

            // FORA DA CRUZ
            }else{
                printf("%d ", MatrizCruz[i][j]);
            }

        }
        printf("\n");
    }
    return 0;
}

/**
 * FUNÇÃO: main
 * 
 * Objetivo: Função principal que executa todas as funções de exibição
 * 
 * Fluxo:
 * 1. Executa BatalhaNaval() - Mostra tabuleiro com navios
 * 2. Pula linha para separação visual
 * 3. Executa MatrizCruz() - Mostra padrão de cruz
 * 4. Pula linha
 * 5. Executa MatrizCone() - Mostra padrão de cone
 * 6. Pula linha
 * 7. Executa MatrizOctaedro() - Mostra padrão de octaedro
 */
int main(){

    BatalhaNaval();
    printf("\n");
    MatrizCruz();
    printf("\n");
    MatrizCone();
    printf("\n");
    MatrizOctaedro();

}