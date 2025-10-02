//iniciado
#include <stdio.h>

#define TAM_TABULEIRO 10   // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]; // matriz 10x10 para representar o tabuleiro
    int i, j;

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais do navio horizontal (linha fixa, coluna inicial)
    int linhaNavioH = 2;
    int colunaNavioH = 4;

    // Coordenadas iniciais do navio vertical (linha inicial, coluna fixa)
    int linhaNavioV = 6;
    int colunaNavioV = 3;

    // === Validação do navio horizontal ===
    if (colunaNavioH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (j = 0; j < TAM_NAVIO; j++) {
            // Verifica se já existe navio na posição
            if (tabuleiro[linhaNavioH][colunaNavioH + j] == 3) {
                printf("Erro: Sobreposição detectada no navio horizontal!\n");
                return 1;
            }
        }
        // Posiciona o navio horizontal
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaNavioH][colunaNavioH + j] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora do limite do tabuleiro!\n");
        return 1;
    }

    // === Validação do navio vertical ===
    if (linhaNavioV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (i = 0; i < TAM_NAVIO; i++) {
            // Verifica se já existe navio na posição
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == 3) {
                printf("Erro: Sobreposição detectada no navio vertical!\n");
                return 1;
            }
        }
        // Posiciona o navio vertical
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
    } else {
        printf("Erro: Navio vertical fora do limite do tabuleiro!\n");
        return 1;
    }

    // === Exibição do tabuleiro ===
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
