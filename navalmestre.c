#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Auxiliar para valor absoluto
int absoluto(int x) {
    return x < 0 ? -x : x;
}

// Aplicação da habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int origem_linha, int origem_coluna,
                        int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = origem_linha - offset + i;
            int coluna_tab = origem_coluna - offset + j;
            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO &&
                coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO &&
                matriz[i][j] == 1 &&
                tabuleiro[linha_tab][coluna_tab] != NAVIO) {
                tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posicionamento dos dois navios
    int linha_h = 2, coluna_h = 4;
    int linha_v = 6, coluna_v = 1;

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = NAVIO;
        tabuleiro[linha_v + i][coluna_v] = NAVIO;
    }

    // Habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Cone
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            cone[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            cruz[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int distancia = absoluto(i - TAM_HABILIDADE / 2) + absoluto(j - TAM_HABILIDADE / 2);
            octaedro[i][j] = (distancia <= TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }

    // Habilidades em diferentes posições
    aplicar_habilidade(tabuleiro, 1, 1, cone);
    aplicar_habilidade(tabuleiro, 5, 5, cruz);
    aplicar_habilidade(tabuleiro, 8, 8, octaedro);

    // Tabuleiro final
    printf("*** Tabuleiro com Navios e Áreas de Habilidade ***\n\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("0 ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("3 ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("5 ");
            }
        }
        printf("\n");
    }

    return 0;
}
