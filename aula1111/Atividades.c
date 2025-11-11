#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} aluno;



void leraluno(aluno *a) {
printf("Nome: ");
fgets(a->nome,sizeof(a->nome), stdin);
strtok(a->nome, "\n");
printf("Nota 1: ");
scanf("%f", &a->nota1);
printf("Nota 2: ");
scanf("%f", &a->nota2);
getchar(); // Limpar o buffer do teclado
a->media = (a->nota1 + a->nota2) / 2;
}

void mostrarAluno(aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Nota 1: %.2f\n", a.nota1);
    printf("Nota 2: %.2f\n", a.nota2);
    printf("Media: %.2f\n", a.media);
}

void mostraraprovado(aluno a) {
    if (a.media >= 6) {
        printf("Aluno %s aprovado!\n", a.nome);
    } else {

    }
}
void main2() {
          aluno a1, a2, a3;
    for( int i = 1; i <= 3; i++) {
     if (i == 1) {
        leraluno(&a1);
        mostrarAluno(a1);
} else if (i == 2) {
        leraluno(&a2);
        mostrarAluno(a2);
 } else {
        leraluno(&a3);
        mostrarAluno(a3);

        }
    }
    for( int i = 1; i <= 3; i++) {
     if (i == 1) {
        mostraraprovado(a1);
} else if (i == 2) {
        mostraraprovado(a2);
    } else {
        mostraraprovado(a3);
        }
    }


    
}
int main() {
     
    main2();
 


    return 0;
}