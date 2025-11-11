#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} produto;
void mostrarProduto(produto p) {
    printf("Nome: %s\n", p.nome);
    printf("Preço: %f\n", p.preco);
    printf("Quantidade: %d\n", p.quantidade);
}

void aplicardesconto(produto *p, float desconto) {
    printf("Digite o percentual de desconto: ");
    scanf("%f", &desconto);
    desconto = 100 - desconto; 
    p->preco = p->preco * desconto / 100;
}


int main() {
    
    produto p1 = {"Caneta", 1.50, 100};
    aplicardesconto(&p1, 0);
    mostrarProduto(p1);
    return 0;
}