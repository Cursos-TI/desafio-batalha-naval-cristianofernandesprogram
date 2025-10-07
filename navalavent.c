#include <stdio.h>

int main() {
    
    int tamanho_tabuleiro = 10;
    int tamanho_navio = 3;
    int valor_agua = 0;
    int valor_navio = 3;

    
    int tabuleiro[10][10];
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = valor_agua;
        }
    }

    // Coordenadas dos navios
    int linha_h1 = 1, coluna_h1 = 2; // Navio horizontal
    int linha_v1 = 4, coluna_v1 = 6; // Navio vertical
    int linha_d1 = 0, coluna_d1 = 0; // Navio diagonal principal
    int linha_d2 = 0, coluna_d2 = 9; // Navio diagonal secundária

    // Limites
    if (coluna_h1 + tamanho_navio > tamanho_tabuleiro ||
        linha_v1 + tamanho_navio > tamanho_tabuleiro ||
        linha_d1 + tamanho_navio > tamanho_tabuleiro ||
        coluna_d1 + tamanho_navio > tamanho_tabuleiro ||
        linha_d2 + tamanho_navio > tamanho_tabuleiro ||
        coluna_d2 - tamanho_navio + 1 < 0) {
        printf("Erro: coordenadas fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Sobreposição
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_h1][coluna_h1 + i] == valor_navio ||
            tabuleiro[linha_v1 + i][coluna_v1] == valor_navio ||
            tabuleiro[linha_d1 + i][coluna_d1 + i] == valor_navio ||
            tabuleiro[linha_d2 + i][coluna_d2 - i] == valor_navio) {
            printf("Erro: sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posição dos navios
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h1][coluna_h1 + i] = valor_navio;           // Horizontal
        tabuleiro[linha_v1 + i][coluna_v1] = valor_navio;           // Vertical
        tabuleiro[linha_d1 + i][coluna_d1 + i] = valor_navio;       // Diagonal principal
        tabuleiro[linha_d2 + i][coluna_d2 - i] = valor_navio;       // Diagonal secundária
    }

    // Tabuleiro
    printf("**Tabuleiro de Batalha Naval***:\n\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}