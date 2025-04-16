#include <stdio.h>
#include <stdlib.h>

int tabuleiro[10][10] = {0}; // 0 = água | 3 = navio | 5 = habilidade

// Posiciona navio horizontal de tamanho 3
int navio_horizontal(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        int c = coluna + i;
        if (linha >= 0 && linha < 10 && c < 10 && tabuleiro[linha][c] == 0)
            tabuleiro[linha][c] = 3;
    }
    return 1;
}

// Posiciona navio vertical de tamanho 3
int navio_vertical(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        int l = linha + i;
        if (l < 10 && coluna >= 0 && coluna < 10 && tabuleiro[l][coluna] == 0)
            tabuleiro[l][coluna] = 3;
    }
    return 1;
}

// Habilidade em cone (abaixo do centro)
int cone(int centro_linha, int centro_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= j - 2 && i >= 2 - j) {
                int l = centro_linha + i - 2;
                int c = centro_coluna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }
    return 1;
}

// Habilidade em cruz (horizontal + vertical)
int cruz(int centro_linha, int centro_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                int l = centro_linha + i - 2;
                int c = centro_coluna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }
    return 1;
}

// Habilidade em octaedro (forma de losango)
int octaedro(int centro_linha, int centro_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                int l = centro_linha + i - 2;
                int c = centro_coluna + j - 2;
                if (l >= 0 && l < 10 && c >= 0 && c < 10 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }
    return 1;
}

// Exibe o tabuleiro completo
int mostrar_tabuleiro() {
    printf("\nLegenda: 0 = água | 3 = navio | 5 = habilidade\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
    return 1;
}

int main() {
    // Posicionamento dos navios
    navio_horizontal(2, 2);
    navio_vertical(5, 7);
    navio_horizontal(7, 0);
    navio_vertical(0, 9);

    // Ativação das habilidades
    cone(0, 2);
    cruz(4, 4);
    octaedro(7, 2);

    // Exibição final
    mostrar_tabuleiro();

    return 0;
}
