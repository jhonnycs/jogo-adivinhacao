#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n\n");

    int segundos = time(0);
    srand(segundos);
    /*
        srand usa uma semente para aleatorizar o rand
        ao usar o time passando 0, temos os segundos que se passaram desde uma data específica, deixando
        o valor muito próximo do aleatório
    */
    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100; // usando o resto da divisão por 100, temos sempre um número no intervalo [0, 99]
    int chute;
    int tentativas = 1;
    int acertou = 0;
    float pontos = 1000;
    
    while (!acertou) {
        printf("\n%dª tentativa. Chute um número: ", tentativas);
        scanf("%d", &chute);
        printf("seu chute foi %d.", chute);

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