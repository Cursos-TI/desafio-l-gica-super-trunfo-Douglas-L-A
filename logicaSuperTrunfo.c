#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    struct Carta {
    char estado[50];                      // Ex: 'Ceará'
    char codigo[4];                       // Ex: "A01" (máx 3 chars + terminador)
    char nomeCidade[50];                  // Nome da cidade (até 49 caracteres)
    unsigned long int populacao;          // Número de habitantes
    float area;                           // Área em km²
    float pib;                            // PIB (unidade a combinar com enunciado)
    int pontosTuristicos;                 // Quantidade de pontos turísticos
    float densidadePopulacional;          // calculado
    float pibPerCapita;                   // calculado
    float superPoder;                     // Soma dos atributos numéricos
  };
    struct Carta carta1;
    struct Carta carta2;
    
    // Cadastro das Cartas:
    /* ===== Cadastro da primeira carta ===== */
    printf("Cadastro da primeira carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", &carta1.estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB: ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    /* (Nível Aventureiro) Calcula propriedades derivadas */
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta1.superPoder = (float)carta1.populacao + carta1.area + carta1.pib
                        + (float)carta1.pontosTuristicos
                        + carta1.pibPerCapita
                        + (1.0f / carta1.densidadePopulacional);

    /* ===== Cadastro da segunda carta ===== */
    printf("\nCadastro da segunda carta:\n");

    printf("Estado (letra A-H): ");
    scanf(" %[^\n]", &carta2.estado);

    printf("Codigo da carta (ex: B02): ");
    scanf("%3s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB: ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    /* (Nível Aventureiro) Calcula propriedades derivadas */
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;
    carta2.superPoder = (float)carta2.populacao + carta2.area + carta2.pib
                        + (float)carta2.pontosTuristicos
                        + carta2.pibPerCapita
                        + (1.0f / carta2.densidadePopulacional);

    printf("\n=== Dados da Primeira Carta ===\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta1.pibPerCapita);

    printf("\n=== Dados da Segunda Carta ===\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta2.pibPerCapita);

    // Comparação de Cartas:

    int atributo = 1;  
    // 1 = Populacao
    // 2 = Area
    // 3 = PIB
    // 4 = Densidade Populacional
    // 5 = PIB per Capita

    printf("\nComparacao de cartas:\n");

    if (atributo == 1) {
        printf("\nAtributo: Populacao\n");
        printf("Carta 1 - %s: %lu\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 - %s: %lu\n", carta2.nomeCidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    if (atributo == 2) {
        printf("\nAtributo: Area\n");
        printf("Carta 1 - %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("Carta 2 - %s: %.2f km²\n", carta2.nomeCidade, carta2.area);
        if (carta1.area > carta2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    if (atributo == 3) {
        printf("\nAtributo: PIB\n");
        printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, carta1.pib);
        printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, carta2.pib);
        if (carta1.pib > carta2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    if (atributo == 4) {
        printf("\nAtributo: Densidade Populacional\n");
        printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
        printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    if (atributo == 5) {
        printf("\nAtributo: PIB per Capita\n");
        printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
        printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    return 0;
}
