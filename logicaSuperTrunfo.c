#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char pais[50];
    int populacao;
    int area;
    float densidadeDemografica;
} Carta;

// Função para exibir os atributos disponíveis
void exibirAtributos() {
    printf("\nEscolha um atributo:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. Densidade Demográfica\n");
}

// Função para obter a escolha do atributo do jogador
int escolherAtributo(int atributo1) {
    int escolha;
    do {
        exibirAtributos();
        printf("Digite o número do atributo: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 3) {
            printf("Opção inválida. Tente novamente.\n");
        } else if (escolha == atributo1) {
            printf("Você já escolheu este atributo. Tente novamente.\n");
            escolha = 0; // Forçar a repetição do loop
        }
    } while (escolha < 1 || escolha > 3);
    return escolha;
}

// Função para comparar um atributo específico
int compararAtributo(int valorCarta1, int valorCarta2, int atributo) {
    if (atributo == 3) { // Densidade Demográfica: menor valor vence
        if (valorCarta1 < valorCarta2) {
            return 1; // Carta 1 vence
        } else if (valorCarta2 < valorCarta1) {
            return 2; // Carta 2 vence
        } else {
            return 0; // Empate
        }
    } else { // Outros atributos: maior valor vence
        if (valorCarta1 > valorCarta2) {
            return 1; // Carta 1 vence
        } else if (valorCarta2 > valorCarta1) {
            return 2; // Carta 2 vence
        } else {
            return 0; // Empate
        }
    }
}

int main() {
    // Cartas pré-cadastradas (Exemplo)
    Carta carta1 = {"Brasil", 210000000, 8500000, 24.7};
    Carta carta2 = {"Argentina", 45000000, 2780000, 16.2};

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    printf("Carta 1: %s\n", carta1.pais);
    printf("Carta 2: %s\n", carta2.pais);
    atributo1 = escolherAtributo(0); // Nenhum atributo escolhido ainda

    // Escolha do segundo atributo (dinâmico)
    printf("\nEscolha o segundo atributo:\n");
    atributo2 = escolherAtributo(atributo1);

    // Comparação e exibição dos resultados
    int valorAtributo1Carta1, valorAtributo1Carta2;
    int valorAtributo2Carta1, valorAtributo2Carta2;
    char *nomeAtributo1, *nomeAtributo2;

    // Determinar os valores e nomes dos atributos
    switch (atributo1) {
        case 1:
            valorAtributo1Carta1 = carta1.populacao;
            valorAtributo1Carta2 = carta2.populacao;
            nomeAtributo1 = "População";
            break;
        case 2:
            valorAtributo1Carta1 = carta1.area;
            valorAtributo1Carta2 = carta2.area;
            nomeAtributo1 = "Área";
            break;
        case 3:
            valorAtributo1Carta1 = (int) (carta1.densidadeDemografica * 100); // Converter para inteiro para comparar
            valorAtributo1Carta2 = (int) (carta2.densidadeDemografica * 100);
            nomeAtributo1 = "Densidade Demográfica";
            break;
        default:
            printf("Erro ao obter o primeiro atributo.\n");
            return 1;
    }

    switch (atributo2) {
        case 1:
            valorAtributo2Carta1 = carta1.populacao;
            valorAtributo2Carta2 = carta2.populacao;
            nomeAtributo2 = "População";
            break;
        case 2:
            valorAtributo2Carta1 = carta1.area;
            valorAtributo2Carta2 = carta2.area;
            nomeAtributo2 = "Área";
            break;
        case 3:
            valorAtributo2Carta1 = (int) (carta1.densidadeDemografica * 100); // Converter para inteiro para comparar
            valorAtributo2Carta2 = (int) (carta2.densidadeDemografica * 100);
            nomeAtributo2 = "Densidade Demográfica";
            break;
        default:
            printf("Erro ao obter o segundo atributo.\n");
            return 1;
    }

    // Comparar os atributos individualmente
    int resultadoAtributo1 = compararAtributo(valorAtributo1Carta1, valorAtributo1Carta2, atributo1);
    int resultadoAtributo2 = compararAtributo(valorAtributo2Carta1, valorAtributo2Carta2, atributo2);

    // Calcular a soma dos atributos
    int somaCarta1 = valorAtributo1Carta1 + valorAtributo2Carta1;
    int somaCarta2 = valorAtributo1Carta2 + valorAtributo2Carta2;

    // Determinar o vencedor da rodada
    int vencedorRodada = 0;
    if (somaCarta1 > somaCarta2) {
        vencedorRodada = 1; // Carta 1 vence
    } else if (somaCarta2 > somaCarta1) {
        vencedorRodada = 2; // Carta 2 vence
    }

    // Exibir os resultados
    printf("\nResultados da Comparação:\n");
    printf("Carta 1: %s\n", carta1.pais);
    printf("Carta 2: %s\n", carta2.pais);

    printf("\n%s: %d vs %d\n", nomeAtributo1, valorAtributo1Carta1, valorAtributo1Carta2);
    printf("%s: %d vs %d\n", nomeAtributo2, valorAtributo2Carta1, valorAtributo2Carta2);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %d\n", carta1.pais, somaCarta1);
    printf("%s: %d\n", carta2.pais, somaCarta2);

    if (vencedorRodada == 1) {
        printf("\n%s venceu a rodada!\n", carta1.pais);
    } else if (vencedorRodada == 2) {
        printf("\n%s venceu a rodada!\n", carta2.pais);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
