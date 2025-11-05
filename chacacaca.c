#include <stdio.h>
#include <string.h>

typedef struct {
	char palavracerta[50];
	char display[50];
	int tamanho;
	int vida;
	int vitoria;
	char tentativa;
	int morte;
} jogoforca;





int main()
{
    jogoforca jogo;
	strcpy(jogo.palavracerta, "ABACATE");
	jogo.tamanho = strlen(jogo.palavracerta);
	jogo.vida = 6;
	jogo.vitoria = 0;
	jogo.display[jogo.tamanho] = '\0';
	for(int i = 0; i < jogo.tamanho; i++ ) {
		jogo.display[i] = '_';
	}
	printf("%d Letras\n", jogo.tamanho);
	while(jogo.vida != 0 && jogo.vitoria != 1) {
		jogo.morte = 0;
		for(int i = 0; i < jogo.tamanho; i++ ) {
			printf("%c",jogo.display[i]);	
		}
		if(jogo.vida == 6){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|          \n");
		printf("|          \n");
		printf("|          \n");
		}
		if(jogo.vida == 5){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|       O  \n");
		printf("|          \n");
		printf("|          \n");
	}
		if(jogo.vida == 4){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|       O  \n");
		printf("|       |  \n");
		printf("|          \n");
	}
		if(jogo.vida == 3){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|       O  \n");
		printf("|      /|  \n");
		printf("|          \n");
	}
		if(jogo.vida == 2){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|       O  \n");
		printf("|      /|/ \n");
		printf("|          \n");
	}
		if(jogo.vida == 1){
		printf(" \n________  \n");
		printf("|       |  \n");
		printf("|       O  \n");
		printf("|      /|/ \n");
		printf("|      /   \n");
	}
	
		printf("\n\nDigite o seu chute: ");
		scanf(" %c", &jogo.tentativa);
		for(int i = 0; i < jogo.tamanho; i++ ) {
			if(jogo.palavracerta[i] == jogo.tentativa) {
				jogo.display[i] = jogo.palavracerta[i];
				jogo.morte = jogo.morte + 1;
			}
			else {
				jogo.morte = jogo.morte + 0;
			}
		}
		if(jogo.morte == 0) {
			jogo.vida = jogo.vida - 1;
			printf("Errou\n");
		}
		if(strcmp(jogo.display, jogo.palavracerta) == 0)
		{
			jogo.vitoria = 1;
			printf("%s\nGanhou", jogo.palavracerta);
			printf("\nA palavra e: %s", jogo.palavracerta);
		}
		if(jogo.vida == 0) {
					if (jogo.vida == 0){
		printf("\n ________  \n");
		printf("|       |  \n");
		printf("|       X  \n");
		printf("|      /|/ \n");
		printf("|      / / \n");
	}
			printf("Acabaram as vidas\nPerdeu");
			printf("\nA palavra e: %s", jogo.palavracerta);
		}
	}

    return 0;
}