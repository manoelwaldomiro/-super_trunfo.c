#include <stdio.h>
//INICIADO DESAFIAO
int main() {
    // Número de casas a serem movidas
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    int i; // variável de controle

    // =========================
    // Movimento da TORRE (for)
    // =========================
    printf("Movimento da Torre (5 casas para a Direita):\n");
    for (i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    // =========================
    // Movimento do BISPO (while)
    // =========================
    printf("\nMovimento do Bispo (5 casas na Diagonal: Cima e Direita):\n");
    i = 1; // resetar contador
    while (i <= casasBispo) {
        printf("Cima, Direita\n");
        i++;
    }

    // =========================
    // Movimento da RAINHA (do-while)
    // =========================
    printf("\nMovimento da Rainha (8 casas para a Esquerda):\n");
    i = 1; // resetar contador
    do {
        printf("Esquerda\n");
        i++;
    } while (i <= casasRainha);

    return 0;
}

