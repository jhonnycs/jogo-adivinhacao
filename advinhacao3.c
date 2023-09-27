#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");


    int segundos = time(0);
    srand(segundos);
    /*
        srand usa uma semente para aleatorizar o rand
        ao usar o time passando 0, temos os segundos que se passaram desde uma data específica, deixando
        o valor muito próximo do aleatório
    */
    int numeroGrande = rand();
    int chute;
    int tentativas;
    int acertou = 0;
    float pontos = 1000;

    int jogarNovamente = 1;
    
    while(jogarNovamente) {
        int numeroSecreto = numeroGrande % 100;
        // usando o resto da divisão por 100,
        //temos sempre um número no intervalo [0, 99]

        printf("Escolha a dificuldade:\n\n");
        printf("(1) Fácil   (2) Médio   (3) Difícil\n\n>");
        int dificuldade;
        
        scanf("%d", &dificuldade);
        printf("\n");
        // & serve para apontar para a variável
    
        while(dificuldade != 1 && dificuldade != 2 && dificuldade != 3) {
            printf("Por favor, digite uma dificuldade válida: ");
            scanf("%d", &dificuldade);
        }

        switch(dificuldade) {
            case 1:
                tentativas = 20;
                break;
            case 2:
                tentativas = 14;
                break;
            case 3:
                tentativas = 6;
                break;
        }

        int ultimoChute;
        for(int i = 1; i <= tentativas; i++) {
            printf("Você tem %d tentativas de %d\n", i, tentativas);
            printf("\nChute um número: ");
            scanf("%d", &chute);
            
            if (i != 1 && ultimoChute == chute) {
                i--;
                printf("\nVocê já chutou esse número. Chute outro\n\n");
            }
            ultimoChute = chute;
            
            if (chute < 0) {
                printf("Por favor, não chute um número negativo");
                i--;
                continue;
            }
    
            acertou = numeroSecreto == chute;
            int menor = chute < numeroSecreto;
    
            if (acertou) {
                break;
            } else {
                float pontosPerdidos = abs(numeroSecreto - chute) / (float)2;
            // (tipo)dado -> converter o dado <dado> para o tipo <tipo>
            // no caso acima, float
                
                if (menor) {
                    printf("o número que cê chutou foi menor que o número secreto\n");
                } else {
                    printf("o número chutado foi maior que o número secreto\n");
                }
                pontos = pontos - pontosPerdidos;
            }
        }
        printf("\n");   
        if (acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\nParabéns! Você acertou!\n");
            printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
            // %f: imprime todas as casas decimais;
            // %.xf: imprime x casas decimais
        } else {
            printf("       \\|/ ____ \\|/    \n");   
            printf("        @~/ ,. \\~@      \n");   
            printf("       /_( \\__/ )_\\    \n");   
            printf("          \\__U_/        \n");
     
            printf("\nVocê perdeu! Tente novamente!\n\n");
        }
        printf("Deseja jogar novamente? Escolha:\n");
        printf("(0) não jogar   (1) jogar\n\n>");
        scanf("%d", &jogarNovamente);
    }
    return 0;
}