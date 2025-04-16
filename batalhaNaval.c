#include <stdio.h>

// Função para verificar se a posição está vazia e dentro dos limites
int posicao_valida(int tabuleiro[10][10], int linha, int coluna) {
    return (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == 0);
}

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com água (0)
    int tamanho_navio = 3;

    // ========================
    // NAVIO 1 - HORIZONTAL (linha 2, colunas 3 a 5)
    int linha1 = 2, coluna1 = 3;
    for (int i = 0; i < tamanho_navio; i++) {
        if (posicao_valida(tabuleiro, linha1, coluna1 + i)) {
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    }

    // ========================
    // NAVIO 2 - VERTICAL (coluna 7, linhas 1 a 3)
    int linha2 = 1, coluna2 = 7;
    for (int i = 0; i < tamanho_navio; i++) {
        if (posicao_valida(tabuleiro, linha2 + i, coluna2)) {
            tabuleiro[linha2 + i][coluna2] = 3;
        }
    }

    // ========================
    // NAVIO 3 - DIAGONAL PRINCIPAL (começa em 5,5 até 7,7)
    int linha3 = 5, coluna3 = 5;
    for (int i = 0; i < tamanho_navio; i++) {
        if (posicao_valida(tabuleiro, linha3 + i, coluna3 + i)) {
            tabuleiro[linha3 + i][coluna3 + i] = 3;
        }
    }

    // ========================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA (começa em 0,9 até 2,7)
    int linha4 = 0, coluna4 = 9;
    for (int i = 0; i < tamanho_navio; i++) {
        if (posicao_valida(tabuleiro, linha4 + i, coluna4 - i)) {
            tabuleiro[linha4 + i][coluna4 - i] = 3;
        }
    }

    // ========================
    // IMPRIMIR TABULEIRO
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

