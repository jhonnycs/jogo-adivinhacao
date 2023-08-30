	#include <stdio.h>
#define clear() printf("\033[H\033[J")

/*
-no terminal, executei: chcp 65001
-isso serve pra alterar a visualização de caracteres
do terminal
-por padrão, essa visualização é a 850 (Latin I)
*/

int main() {
	clear();
	printf("***********************************\n");
	printf("* Bem vindo ao jogo de Advinhação *\n");
	printf("***********************************\n");
	
	int numerosecreto = 42;
	int chute;
	for (int i = 0; i < 3; ++i)	{
		printf("\n-------------- tentativa número %d --------------\n", i+1);
		printf("\nMe diga então um número (inteiro, por favor): ");
		scanf("%d", &chute);
		printf("o número chutado é %d\n", chute);

		int acertou = numerosecreto == chute;
		
		if (acertou) {
			printf("Parabéns, acertaste!\n");
		} else {
			int maior = chute > numerosecreto;
			if (maior) {
				printf("Infelizmente, erraste. Chutou um número maior\n");
			} else {
				printf("Infelizmente, erraste. Chutou um número menor\n");
			}		
		}
	}
}
