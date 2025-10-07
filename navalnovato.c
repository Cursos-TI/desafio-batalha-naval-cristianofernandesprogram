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
    int linha_horizontal = 2, coluna_horizontal = 4; // Navio horizontal começa em (2,4)
    int linha_vertical = 5, coluna_vertical = 7;     // Navio vertical começa em (5,7)

    // Navio horizontal
    if (coluna_horizontal + tamanho_navio > tamanho_tabuleiro) {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Navio vertical
    if (linha_vertical + tamanho_navio > tamanho_tabuleiro) {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == valor_navio ||
            tabuleiro[linha_vertical + i][coluna_vertical] == valor_navio) {
            printf("Erro: sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Navio horizontal
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = valor_navio;
    }

    // Navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = valor_navio;
    }

    // Tabuleiro
    printf("***Tabuleiro de Batalha Naval***:\n\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}