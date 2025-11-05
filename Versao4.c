#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "banco_palavras.h"


typedef struct {
	char palavracerta[50];
	char display[50];
	int tamanho;
	int vida;
	int vitoria;
	char tentativa;
	int morte;
	char letrasErradas[10];
	int numErros;
} jogoforca;



void escolhe_palavra(char* palavra_secreta) {
// PASSO 1: Abrir o arquivo de palavras
FILE* f = fopen("palavras.txt", "r");
// PASSO 2: Verificar se o arquivo foi encontrado
if (f == NULL) {
printf("Erro: Banco de palavras nao encontrado.\n");
exit(1); // Sai do programa se não encontrar o arquivo
}
// PASSO 3: Ler o número total de palavras (a primeira linha)
int total_palavras = 0;
fscanf(f, "%d", &total_palavras);
// PASSO 4: Sortear um índice aleatório (igual à V4)
int indice_sorteado = rand() % total_palavras;
// PASSO 5: Ler as palavras do arquivo até chegar na sorteada
// fscanf() lê uma palavra de cada vez.
// Vamos "pular" as palavras até o índice sorteado.
for (int i = 0; i <= indice_sorteado; i++) {
fscanf(f, "%s", palavra_secreta);
}
// PASSO 6: Fechar o arquivo
fclose(f);
}


int main()
{
	jogoforca jogo;
	inicializar_aleatoriedade();
	sortear_palavra(jogo.palavracerta);
	char palavra_secreta[50];
	escolhe_palavra(palavra_secreta);
	

    
	
	jogo.tamanho = strlen(palavra_secreta);
	jogo.vida = 6;
	jogo.vitoria = 0;
	jogo.numErros = 0;
    jogo.letrasErradas[0] = '\0';
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
	if (jogo.numErros > 0) {
            printf("\nLetras erradas: %s", jogo.letrasErradas);
        }
	
		printf("\n\nDigite o seu chute: ");
		scanf(" %c", &jogo.tentativa);
		for(int i = 0; i < jogo.tamanho; i++ ) {
			if(palavra_secreta[i] == jogo.tentativa) {
				jogo.display[i] = palavra_secreta[i];
				jogo.morte = jogo.morte + 1;
			}
			else {
				jogo.morte = jogo.morte + 0;
			}
		}
		if(jogo.morte == 0) {
			jogo.letrasErradas[jogo.numErros] = jogo.tentativa;                      
            jogo.numErros++; 
            jogo.letrasErradas[jogo.numErros] = '\0'; 
			jogo.vida = jogo.vida - 1;
			printf("Errou\n");
		}
		if(strcmp(jogo.display, palavra_secreta) == 0)
		{
			jogo.vitoria = 1;
			printf("%s\nGanhou", palavra_secreta);
			printf("\nA palavra e: %s", palavra_secreta);
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
			printf("\nA palavra e: %s", palavra_secreta);
		}
	}

    return 0;
}