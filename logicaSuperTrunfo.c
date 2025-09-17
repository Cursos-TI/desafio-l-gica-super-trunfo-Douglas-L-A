#include <stdio.h>
#include <string.h>

// Estrutura da Carta
struct Carta {
    char estado[50];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função auxiliar para exibir menu dinâmico
void exibirMenu(int excluir) {
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
}

int main() {
    struct Carta carta1, carta2;

    /* ===== Cadastro da primeira carta ===== */
    printf("Cadastro da primeira carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB: ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcula derivados
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    /* ===== Cadastro da segunda carta ===== */
    printf("\nCadastro da segunda carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);

    printf("Codigo da carta (ex: B02): ");
    scanf("%3s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB: ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calcula derivados
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    /* ===== Exibição dos dados das cartas ===== */
    printf("\n=== Dados da Primeira Carta ===\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta1.pibPerCapita);

    printf("\n=== Dados da Segunda Carta ===\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta2.pibPerCapita);


    /* ===== Escolha dos atributos ===== */
    int atributo1, atributo2;

    exibirMenu(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    exibirMenu(atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    // Variáveis para armazenar valores de comparação
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    // Função de comparação 
    #define VENCEDOR(v1,v2,inverte) ((inverte) ? ((v1 < v2) ? 1 : ((v2 < v1) ? 2 : 0)) : ((v1 > v2) ? 1 : ((v2 > v1) ? 2 : 0)))

    // Processa o primeiro atributo
    switch(atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.pontosTuristicos; valor1_c2 = carta2.pontosTuristicos; break;
        case 5: valor1_c1 = carta1.densidadePopulacional; valor1_c2 = carta2.densidadePopulacional; break;
        case 6: valor1_c1 = carta1.pibPerCapita; valor1_c2 = carta2.pibPerCapita; break;
    }

    // Processa o segundo atributo
    switch(atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.pontosTuristicos; valor2_c2 = carta2.pontosTuristicos; break;
        case 5: valor2_c1 = carta1.densidadePopulacional; valor2_c2 = carta2.densidadePopulacional; break;
        case 6: valor2_c1 = carta1.pibPerCapita; valor2_c2 = carta2.pibPerCapita; break;
    }

    // Comparação dos dois atributos
    int resultado1 = VENCEDOR(valor1_c1, valor1_c2, atributo1 == 5);
    int resultado2 = VENCEDOR(valor2_c1, valor2_c2, atributo2 == 5);

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    int resultadoFinal = (soma1 > soma2) ? 1 : ((soma2 > soma1) ? 2 : 0);

    /* ===== Exibição ===== */
    printf("\n=== Comparação Final ===\n");
    printf("Carta 1: %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("Carta 2: %s (%s)\n\n", carta2.nomeCidade, carta2.estado);

    printf("Atributo 1: %d -> %s: %.2f | %s: %.2f | Vencedor: %s\n",
           atributo1, carta1.nomeCidade, valor1_c1, carta2.nomeCidade, valor1_c2,
           (resultado1 == 1 ? carta1.nomeCidade : (resultado1 == 2 ? carta2.nomeCidade : "Empate")));

    printf("Atributo 2: %d -> %s: %.2f | %s: %.2f | Vencedor: %s\n",
           atributo2, carta1.nomeCidade, valor2_c1, carta2.nomeCidade, valor2_c2,
           (resultado2 == 1 ? carta1.nomeCidade : (resultado2 == 2 ? carta2.nomeCidade : "Empate")));

    printf("\nSoma dos atributos: %s = %.2f | %s = %.2f\n",
           carta1.nomeCidade, soma1, carta2.nomeCidade, soma2);

    printf("Resultado Final: %s\n",
           (resultadoFinal == 1 ? carta1.nomeCidade :
            (resultadoFinal == 2 ? carta2.nomeCidade : "Empate")));

    return 0;
}
