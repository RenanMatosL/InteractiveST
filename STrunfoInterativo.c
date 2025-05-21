#include <stdio.h>

// Função para exibir o menu de escolha do atributo de confronto
int mostrarMenu() {
    int escolha;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional (Menor vence!)\n");
    printf("6 - PIB per capita\n");
    printf("Escolha uma opção (1 a 6): ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para exibir o resultado do confronto entre cartas
void exibirResultado(char nomePais1[], char nomePais2[], int escolha, float valor1, float valor2, int regraEspecial) {
    printf("\n=== Resultado do Confronto ===\n");
    printf("País 1: %s\n", nomePais1);
    printf("País 2: %s\n", nomePais2);

    // Exibe qual atributo foi comparado
    switch (escolha) {
        case 1: printf("Atributo comparado: População\n"); break;
        case 2: printf("Atributo comparado: Área\n"); break;
        case 3: printf("Atributo comparado: PIB\n"); break;
        case 4: printf("Atributo comparado: Pontos turísticos\n"); break;
        case 5: printf("Atributo comparado: Densidade populacional (Menor vence!)\n"); break;
        case 6: printf("Atributo comparado: PIB per capita\n"); break;
    }

    // Exibe o País e os valores dos atributos
    printf("%s: %.2f\n", nomePais1, valor1);
    printf("%s: %.2f\n", nomePais2, valor2);

    // Lógica de vitória (Maior vence, exceto para densidade populacional)
    if (regraEspecial == 0) {
        if (valor1 > valor2) {
            printf("Vencedor: %s!\n", nomePais1);
        } else if (valor2 > valor1) {
            printf("Vencedor: %s!\n", nomePais2);
        } else {
            printf("Empate!\n");
        }
    } else {
        if (valor1 < valor2) {
            printf("Vencedor: %s (Menor densidade populacional vence!)\n", nomePais1);
        } else if (valor2 < valor1) {
            printf("Vencedor: %s (Menor densidade populacional vence!)\n", nomePais2);
        } else {
            printf("Empate!\n");
        }
    }
}

int main() {
    // Declaração das variáveis das cartas
    char nomePais1[50], nomePais2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;

    // Variáveis calculadas
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    // Coletando dados da PRIMEIRA CARTA
    printf("Digite os dados da primeira carta:\n");
    printf("Nome do país: ");
    scanf(" %49[^\n]", nomePais1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões US$): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Coletando dados da SEGUNDA CARTA
    printf("\nDigite os dados da segunda carta:\n");
    printf("Nome do país: ");
    scanf(" %49[^\n]", nomePais2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões US$): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos de densidade populacional e PIB per capita
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // O jogador escolhe o atributo para o confronto
    int escolha = mostrarMenu();

    // Comparação baseada na escolha do jogador
    switch (escolha) {
        case 1: exibirResultado(nomePais1, nomePais2, escolha, (float)populacao1, (float)populacao2, 0); break;
        case 2: exibirResultado(nomePais1, nomePais2, escolha, area1, area2, 0); break;
        case 3: exibirResultado(nomePais1, nomePais2, escolha, pib1, pib2, 0); break;
        case 4: exibirResultado(nomePais1, nomePais2, escolha, (float)pontosTuristicos1, (float)pontosTuristicos2, 0); break;
        case 5: exibirResultado(nomePais1, nomePais2, escolha, densidade1, densidade2, 1); break; // Regra especial: menor vence
        case 6: exibirResultado(nomePais1, nomePais2, escolha, pibPerCapita1, pibPerCapita2, 0); break;
        default: printf("\nOpção inválida! Escolha um número entre 1 e 6.\n");
    }

    return 0;
}