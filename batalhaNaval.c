#include <stdio.h>

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).

    int tabuleiro[10][10];
    char linha[10] = {'0', '1', '2', '3', '4', '5','6', '7', '8', '9'};

// Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
// Posiciona os navios
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};
    int naviodiagonal1[3] = {3, 3, 3};
    int naviodiagonal2[3] = {3, 3, 3};

// Navio horizontal
    int linha1 = 9, coluna1 = 0;
    for (int i = 0; i < 3; i++){
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }

// Navio vertical
    int linha2 = 7, coluna2 = 9;
    for (int i = 0; i < 3; i++){
        tabuleiro[linha2 +i][coluna2] = navio2[i];
    }

    //Navio diagonal (esquerda pra direita descendo)
    int linhadiag1 = 0, colunadiag1 = 0;
    for (int i = 0; i < 3; i++){
        tabuleiro[linhadiag1 + i][colunadiag1 + i] = naviodiagonal1[i];
    }

    //Navio diagonal (esquerda pra direita subindo)
    int linhadiag2 = 7, colunadiag2 = 2;
    for (int i = 0; i < 3; i++){
        tabuleiro[linhadiag2 - i][colunadiag2 + i] = naviodiagonal2[i];
    }

    //Navio em forma de cone
    int linha_cone = 0, coluna_cone = 5;
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha_cone + i < 10 && coluna_cone + j >= 0 && coluna_cone + j < 10) {
                tabuleiro[linha_cone + i][coluna_cone + j] = 3;
            }
        }
    }

    //Navio octaedro
    int linha_octa = 4, coluna_octa = 5;
    for (int i = -1; i <= 1; i++){
        if (linha_octa + i >= 0 && linha_octa + i < 10 && tabuleiro[linha_octa + i][coluna_octa] == 0)
            tabuleiro[linha_octa + i][coluna_octa] = 4;
        if (coluna_octa + i >= 0 && coluna_octa + i < 10 && tabuleiro[linha_octa][coluna_octa + i] == 0)
            tabuleiro[linha_octa][coluna_octa + i] = 4;
    }

    //Navio em forma de cruz
    int linha_cruz = 7, coluna_cruz = 5;
    for (int i = -1; i <= 1; i++){
        if (coluna_cruz + i >= 0 && coluna_cruz + i < 10 && tabuleiro[linha_cruz][coluna_cruz + i] == 0)
            tabuleiro[linha_cruz][coluna_cruz + i] = 5;
        if (linha_cruz + i + 0 && linha_cruz + i < 10 && tabuleiro[linha_cruz + i][coluna_cruz] == 0)
            tabuleiro[linha_cruz + i][coluna_cruz] = 5;
    }

// Exibir tabuleiro
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 10; i++){
        printf("%c ", linha[i]);
        for (int j = 0; j < 10; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\r\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}