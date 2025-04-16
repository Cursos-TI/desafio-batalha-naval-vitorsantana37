#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Definição do tabuleiro 10x10 inicializado com 0 (representando água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo as coordenadas iniciais para os navios
    // Navio horizontal (linha 4, coluna 2)
    int navio_horizontal[TAMANHO_NAVIO] = {2, 3, 4};  // Representando as colunas

    // Navio vertical (linha 6, coluna 7)
    int navio_vertical[TAMANHO_NAVIO] = {6, 7, 8};  // Representando as linhas

    // Posicionando o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[4][navio_horizontal[i]] = 3; // Colocando o navio horizontal na linha 4
    }

    // Posicionando o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_vertical[i]][7] = 3; // Colocando o navio vertical na coluna 7
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
