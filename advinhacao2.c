#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 3

/*
  linguagem interpretada vs compilada
  interpretada: roda à medida que interpreta
  compilada: compila tudo e só depois gera a aplicação
*/

int main() {
    printf("************************************\n");
    printf("* Bem-vindo ao Jogo de Adivinhação *\n");
    printf("************************************\n\n");

    int numeroSecreto = 42;
    int chute;
    int tentativas = 1;
    int acertou = 0;
    
    while (!acertou) {
        printf("chute um número: ");
        scanf("%d", &chute);
        tentativas++;

        if (chute < 0) {
            printf("Por favor, não chute um número negativo");
            tentativas--;
            continue;
        }

        acertou = numeroSecreto == chute;
        int menor = chute < numeroSecreto;
        if (acertou) {
            printf("parabéns, você acertou :)\n");
            acertou = 1;
            break;
        } else if (menor) {
            printf("o número que cê chutou foi menor que o número secreto\n");
        } else {
            printf("o número chutado foi maior que o número secreto\n");
        }
    }    
    printf("Fim de jogo. Obrigado por jogar :)");
    return 0;
}