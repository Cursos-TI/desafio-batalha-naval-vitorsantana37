#include <stdio.h>

#define TAM 10
#define TAM_HABILIDADE 5

// Inicializa o tabuleiro com água (0) e navios (3) em posições fixas
int inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
    
    // Colocando alguns navios (valor 3) no tabuleiro
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;
    
    return 1;
}

// Gera a matriz de habilidade para a forma de cone
int gerarCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE/2 - i && j <= TAM_HABILIDADE/2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
    return 1;
}

// Gera a matriz de habilidade para a forma de cruz
int gerarCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
    return 1;
}

// Gera a matriz de habilidade para a forma de octaedro
int gerarOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int i, j;
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE/2) + abs(j - TAM_HABILIDADE/2) <= TAM_HABILIDADE/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
    return 1;
}

// Aplica a habilidade no tabuleiro
int aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int x, int y) {
    int i, j;
    int inicioX = x - TAM_HABILIDADE / 2;
    int inicioY = y - TAM_HABILIDADE / 2;
    
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            int posX = inicioX + i;
            int posY = inicioY + j;
            if (posX >= 0 && posX < TAM && posY >= 0 && posY < TAM && habilidade[i][j] == 1) {
                tabuleiro[posX][posY] = 5; // Representa a área afetada
            }
        }
    }
    return 1;
}

// Exibe o tabuleiro no console
int exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}