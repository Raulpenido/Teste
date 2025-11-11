#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
char nome[20];
int quantidade;
float preco;
} Produto;

void lerproduto(Produto *p) {
    printf("Nome do produto: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    strtok(p->nome, "\n");
   
    printf("Quantidade: ");
    scanf("%d", &p->quantidade);
    getchar(); // Limpar o buffer do teclado
    printf("Preco: ");
    scanf("%f", &p->preco);
    getchar(); // Limpar o buffer do teclado
    
}
void mostrarproduto(Produto p) {
    printf("Nome: %s\n", p.nome);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco: %f\n", p.preco);
}
void atualizarestoque(Produto *p){
    int qtd, opcao;
    printf("Você deseja adicionar ou remover do estoque? (1/0):");
    scanf("%d", &opcao);
    getchar(); // Limpar o buffer do teclado
    if(opcao == 0){
        printf("Quantidade a remover: ");
        scanf("%d", &qtd);
        getchar(); // Limpar o buffer do teclado
        p->quantidade = p->quantidade - qtd;
  
        
    }
    else{
        printf("Quantidade a adicionar: ");
        scanf("%d", &qtd);
        getchar(); // Limpar o buffer do teclado
        p->quantidade = p->quantidade + qtd;
    }
    
}
void mostrarTodos(Produto produtos[], int n)
{
    for (int i = 0; i < n; i++) {
       printf("\nProduto %d: %s \n", i + 1, produtos[i].nome);
       
    }
} 


int main() {
    Produto produtos[4];
    int total = 3;
    for (int i = 0; i < total; i++) {
        printf("Produto %d:\n", i + 1);
       
        lerproduto(&produtos[i]);
        atualizarestoque(&produtos[i]);
        mostrarproduto(produtos[i]);
    }
    mostrarTodos(produtos, total);
    
    return 0;
}

