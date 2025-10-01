#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2
#define SPOCK 3
#define LAGARTO 4

void versao_01() {
	int jogador, computador;
	printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
	scanf("%d", &jogador);
	computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
	printf("Computador escolheu: %d\n", computador);
	if (jogador == PEDRA) {
		if (computador == PEDRA) {
			printf("Empate!\n");
		} else if (computador == PAPEL) {
			printf("Computador vence!\n");
		} else { // computador == TESOURA
			printf("Jogador vence!\n");
		}
	} else if (jogador == PAPEL) {
		if (computador == PEDRA) {
			printf("Jogador vence!\n");
		} else if (computador == PAPEL) {
			printf("Empate!\n");
		} else { // computador == TESOURA
			printf("Computador vence!\n");
		}
	} else { // jogador == TESOURA
		if (computador == PEDRA) {
			printf("Computador vence!\n");
		} else if (computador == PAPEL) {
			printf("Jogador vence!\n");
		} else { // computador == TESOURA
			printf("Empate!\n");
		}
	}
}

/*
Vamos refatorar o cC3digo para reduzir o nC:mero de estruturas if/else a partir do uso de operadores lC3gicos
(&& para"E", || para "OU"). A ideia C) agrupar todas as condiC'C5es de vitC3ria do jogador em uma C:nica expressC#o.
*/
void versao_02() {
	int jogador, computador;
	printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
	scanf("%d", &jogador);
	computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
	printf("Computador escolheu: %d\n", computador);
	if (jogador == computador) {
		printf("Empate!\n");
	} else if ((jogador == PEDRA && computador == TESOURA) ||
	           (jogador == PAPEL && computador == PEDRA) ||
	           (jogador == TESOURA && computador == PAPEL)) {
		printf("Jogador vence!\n");
	} else {
		printf("Computador vence!\n");
	}
}

/*
Para que o jogo possa ser jogado vC!rias vezes sem precisar reiniciar o programa, vamos colocar toda a lC3gica dentro de um laC'o de repetiC'C#o.
O laC'o do-while C) ideal aqui, pois garante que o jogo seja executado pelo menos uma vez antes de perguntar se o jogador quer continuar.
*/
void versao_03() {
	int jogador, computador;
	char jogar_novamente;
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate!\n");
		} else if ((jogador == PEDRA && computador == TESOURA) ||
		           (jogador == PAPEL && computador == PEDRA) ||
		           (jogador == TESOURA && computador == PAPEL)) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}
void versao_04() {
	int jogador, computador;
	char jogar_novamente;
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura), 3 (Spock), 4 (Lagarto): ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate!\n");
		} else if ((jogador == PEDRA && computador == TESOURA) ||(jogador == PEDRA && computador == LAGARTO) ||
		           (jogador == PAPEL && computador == PEDRA) || (jogador == PAPEL && computador == SPOCK) ||
		           (jogador == TESOURA && computador == PAPEL) || (jogador == TESOURA && computador == LAGARTO) ||
		           (jogador == SPOCK && computador == TESOURA) || (jogador == SPOCK && computador == PEDRA) ||
		           (jogador == LAGARTO && computador == SPOCK) || (jogador == LAGARTO && computador == PAPEL)) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}



void versao_05() {
	int jogador, computador;
	char jogar_novamente;
	int jogador_ganha[] = {TESOURA, PEDRA, PAPEL};
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura): ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate!\n");
		} else if (jogador_ganha[jogador] == computador) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}
void versao_06() {
	int jogador, computador;
	char jogar_novamente;
	int pedrapapel[5][5] = {{0, -1, 1, -1, 1}, {1, 0, -1, 1, -1}, {-1, 1, 0, -1, 1}, {1, -1, 1, 0, -1}, {-1, 1, -1, 1, 0}} ;
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura), 3 (Spock), 4 (Lagarto):  ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (pedrapapel[jogador][computador] == 0) {
			printf("Empate!\n");
		} else if (pedrapapel[jogador][computador] == 1) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}
void versao_07() {
	int jogador, computador;
	char jogar_novamente;
	int somaj, somac;
	for(int i = 0; i < 3; i++) {

		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura) ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (jogador == computador) {
			printf("Empate! comece novamente\n");
			break;
		}

		else if (jogador == PEDRA && computador == TESOURA) {
			printf("Jogador vence!\n");
			somaj = somaj + 1;
		}
		else if (jogador == PAPEL && computador == PEDRA ) {
			printf("Jogador vence!\n");
			somaj = somaj + 3;
		}
		else if (jogador == TESOURA && computador == PAPEL) {
			printf("Jogador vence!\n");
			somaj = somaj + 2;
		}

		else if (computador == PEDRA && jogador == TESOURA) {
			printf("Computador vence!\n");
			somac = somac + 1;
		}
		else if (computador == PAPEL && jogador == PEDRA ) {
			printf("Computador vence!\n");
			somac = somac + 3;
		}
		else if (computador == TESOURA && jogador == PAPEL) {
			printf("Computador vence!\n");
			somac = somac + 2;
		}
	}
	if(somaj > somac) {
		printf("\nJogador venceu com %d pontos contra %d pontos do computador", somaj, somac);
	}

	else {
		printf("\nComputador venceu com %d pontos contra %d pontos do jogador", somac, somaj);
	}

}
void versao_08() {
	int jogador, computador;
	char jogar_novamente;
	int pedrapapel[3][3] = {{0, -1, 1}, {1, 1, -1}, {-1, 1, 0}} ;
	do {
		printf("Escolha: 0 (Pedra), 1 (Papel), 2 (Tesoura), 3 (Spock), 4 (Lagarto):  ");
		scanf("%d", &jogador);
		computador = rand() % 3; // Gera um nC:mero aleatC3rio entre 0 e 2
		printf("Computador escolheu: %d\n", computador);
		if (pedrapapel[jogador][computador] == 0) {
			printf("Empate!\n");
		} else if (pedrapapel[jogador][computador] == 1) {
			printf("Jogador vence!\n");
		} else {
			printf("Computador vence!\n");
		}
		printf("Quer jogar novamente? (s/n): ");
		scanf(" %c", &jogar_novamente);
	} while (jogar_novamente == 's' || jogar_novamente == 'S');

}











int main() {
	srand(time(NULL)); // Inicializa o gerador de nC:meros aleatC3rios
	printf("VersC#o 01:\n");
	//versao_01();
	printf("\nVersC#o 02:\n");
	//versao_02();
	printf("\nVersC#o 03:\n");
	//versao_03();
	printf("\nVersC#o 04:\n");
	//versao_04();
	printf("\nVersC#o 05:\n");
	//versao_05();
	printf("\nVersC#o 06:\n");
	versao_07();
	return 0;
}