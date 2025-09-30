#include <stdio.h>
//novocomit2
int main() {
    // --- Carta 1 ---
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // --- Carta 2 ---
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    int escolha;

    // --- Entrada de dados da Carta 1 ---
    printf("Cadastro da Carta 1:\n");

    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);


    // --- Entrada de dados da Carta 2 ---
    printf("\nCadastro da Carta 2:\n");

    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a Populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a Area (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);


    // --- Saída dos dados ---
    printf("\n=== CARTA 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\n=== CARTA 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    

 // Entrada simplificada só com dois atributos
    printf("Digite a populacao da Carta 1: ");
    scanf("%d", &populacao1);
    printf("Digite o PIB da Carta 1: ");
    scanf("%f", &pib1);

    printf("\nDigite a populacao da Carta 2: ");
    scanf("%d", &populacao2);
    printf("Digite o PIB da Carta 2: ");
    scanf("%f", &pib2);

    printf("\nEscolha o atributo principal para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - PIB\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    // Comparacao usando operador ternario
    (escolha == 1) 
        ? printf(populacao1 > populacao2 ? "Carta 1 venceu pela populacao!\n" :
                                           populacao2 > populacao1 ? "Carta 2 venceu pela populacao!\n" :
                                                                     "Empate em populacao!\n")
        : printf(pib1 > pib2 ? "Carta 1 venceu pelo PIB!\n" :
                               pib2 > pib1 ? "Carta 2 venceu pelo PIB!\n" :
                                             "Empate em PIB!\n");

    return 0;
}
