#include <stdio.h>
//logica if else e comparaçao
int main() {
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;
    int escolha;

    // Entrada das cartas
    printf("Digite a populacao da Carta 1: ");
    scanf("%d", &populacao1);
    printf("Digite a area da Carta 1: ");
    scanf("%f", &area1);
    printf("Digite o PIB da Carta 1: ");
    scanf("%f", &pib1);
    printf("Digite os pontos turisticos da Carta 1: ");
    scanf("%d", &pontos1);

    printf("\nDigite a populacao da Carta 2: ");
    scanf("%d", &populacao2);
    printf("Digite a area da Carta 2: ");
    scanf("%f", &area2);
    printf("Digite o PIB da Carta 2: ");
    scanf("%f", &pib2);
    printf("Digite os pontos turisticos da Carta 2: ");
    scanf("%d", &pontos2);

    // Menu interativo com switch
    printf("\nEscolha a comparacao:\n");
    printf("1 - Populacao e Area\n");
    printf("2 - PIB e Pontos Turisticos\n");
    printf("3 - Populacao e PIB\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            if (populacao1 > populacao2 && area1 > area2)
                printf("Carta 1 venceu em populacao e area!\n");
            else if (populacao2 > populacao1 && area2 > area1)
                printf("Carta 2 venceu em populacao e area!\n");
            else
                printf("Empate na comparacao!\n");
            break;

        case 2:
            if (pib1 > pib2 && pontos1 > pontos2)
                printf("Carta 1 venceu em PIB e pontos turisticos!\n");
            else if (pib2 > pib1 && pontos2 > pontos1)
                printf("Carta 2 venceu em PIB e pontos turisticos!\n");
            else
                printf("Empate na comparacao!\n");
            break;

        case 3:
            if (populacao1 > populacao2 || pib1 > pib2)
                printf("Carta 1 venceu em populacao ou PIB!\n");
            else if (populacao2 > populacao1 || pib2 > pib1)
                printf("Carta 2 venceu em populacao ou PIB!\n");
            else
                printf("Empate na comparacao!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}

