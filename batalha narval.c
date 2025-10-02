#include <stdio.h>

#define TAM_TABULEIRO 10   // Tabuleiro 10x10
#define TAM_NAVIO 3        // Navios com tamanho fixo 3
#define TAM_HABILIDADE 5   // As matrizes de habilidade serão 5x5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");  // água
            else if (tabuleiro[i][j] == 3)
                printf("N ");  // navio
            else if (tabuleiro[i][j] == 5)
                printf("* ");  // habilidade
            else
                printf("? ");  // caso inesperado
        }
        printf("\n");
    }
}

// Função para construir a matriz em cone (5x5)
void construirCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = 0; // inicializa
            // Forma de cone: cresce conforme a linha avança
            if (j >= TAM_HABILIDADE/2 - i && j <= TAM_HABILIDADE/2 + i && i <= TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para construir a matriz em cruz (5x5)
void construirCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = 0;
            // Cruz: linha central OU coluna central
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para construir a matriz em octaedro (losango)
void construirOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = 0;
            // Condição para formar um losango (|x| + |y| <= raio)
            int dist = (i - TAM_HABILIDADE/2 < 0 ? -(i - TAM_HABILIDADE/2) : (i - TAM_HABILIDADE/2)) +
                       (j - TAM_HABILIDADE/2 < 0 ? -(j - TAM_HABILIDADE/2) : (j - TAM_HABILIDADE/2));
            if (dist <= TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                       int origemLinha, int origemColuna) {

    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - offset);
                int colunaTab = origemColuna + (j - offset);

                // Verifica se está dentro dos limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {

                    // Marca no tabuleiro apenas se não for navio (valor 3)
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // === Inicializa tabuleiro com água (0) ===
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === Coloca navios ===
    int linhaNavioH = 2, colunaNavioH = 4; // navio horizontal
    for (int j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linhaNavioH][colunaNavioH + j] = 3;
    }

    int linhaNavioV = 6, colunaNavioV = 3; // navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
    }

    // === Construir matrizes de habilidades ===
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // === Aplicar habilidades no tabuleiro ===
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone no centro (linha 4, coluna 4)
    aplicarHabilidade(tabuleiro, cruz, 8, 8);      // Cruz no canto inferior direito
    aplicarHabilidade(tabuleiro, octaedro, 1, 1);  // Octaedro no canto superior esquerdo

    // === Exibir resultado ===
    imprimirTabuleiro(tabuleiro);

    return 0;
}
