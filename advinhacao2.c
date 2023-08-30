#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n\n");

    int numeroSecreto = 42;
    int chute;
    int tentativas = 1;
    int acertou = 0;
    float pontos = 1000;
    
    while (!acertou) {
        printf("\n%dª tentativa. Chute um número: ", tentativas);
        scanf("%d", &chute);

        if (chute < 0) {
            printf("Por favor, não chute um número negativo");
            tentativas--;
            continue;
        }

        printf("Você chutou %d\n", chute);
        acertou = numeroSecreto == chute;
        int menor = chute < numeroSecreto;

        if (acertou) {
            printf("parabéns, você acertou em %d tentativas.\n", tentativas);
            acertou = 1;
        } else {
            float pontosPerdidos = abs(numeroSecreto - chute) / (float)2; // converter para outro tipo
                                                                // nesse caso, float
            tentativas++;

            if (menor) {
                printf("o número que cê chutou foi menor que o número secreto\n");
            } else {
                printf("o número chutado foi maior que o número secreto\n");
            }
            pontos = pontos - pontosPerdidos;
        } 
    }
    printf("Você fez %.2f pontos\n", pontos);
    // %f: imprime todas as casas decimais;
    // %.xf: imprime x casas decimais
    printf("Fim de jogo. Obrigado por jogar :)");
    return 0;
}