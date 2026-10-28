#include <stdio.h>
#include "front.h"
 
void escreveMenu() {
    printf("Menu:\n");
    printf("1. Cadastrar\n");
    printf("2. Consulta de Estoque\n");
    printf("3. Registro de Vendas\n");
    printf("4. Produtos que precisam de reabastecimento\n");
    printf("5. Entrada de mercadorias\n");
    printf("6. Sair\n");
}
 
int cadastrarProdutos(char nome[10][100], float preco[10], int quant[10]) {
    for (int i = 0; i < 10; i++) {
        printf("\nProduto %d\n", i + 1);
 
        printf("Nome: ");
        scanf(" %99[^\n]", nome[i]); // para pegar os nomes com espaço
 
        printf("Quantidade: ");
        scanf("%d", &quant[i]);
 
        printf("Preco: ");
        scanf("%f", &preco[i]);
    }
    return 0;
}
 
int consultarEstoque(char nome[10][100], float preco[10], int quant[10]) {
    for (int i = 0; i < 10; i++) {
        printf("\nCodigo: %d\n", i + 1);
        printf("Nome: %s\n", nome[i]);
        printf("Quantidade: %d\n", quant[i]);
        printf("Preco: %.2f\n", preco[i]);
    }
    return 0;
}
 
int registrarVendas(char nome[10][100], float preco[10], int quant[10]) {
    int codigo, qtd;
 
    printf("Codigo do produto (1 a 10): ");
    scanf("%d", &codigo);
    if (codigo < 1 || codigo > 10) {
        printf("Codigo invalido.\n");
        return 0;
    }
 
    printf("Quantidade desejada: ");
    scanf("%d", &qtd);
    if (qtd <= 0) {
        printf("Quantidade invalida.\n");
        return 0;
    }
 
    int i = codigo - 1;
    if (quant[i] >= qtd) {
        quant[i] -= qtd;
        printf("Venda registrada: %d x %s\n", qtd, nome[i]);
        printf("Valor total da venda: %.2f\n", faturarVendas(preco[i], qtd));
    } else {
        printf("Venda nao pode ser realizada: estoque insuficiente (disponivel: %d).\n", quant[i]);
    }
    return 0;
}
 
int reposicaoProdutos(char nome[10][100], int quant[10]) {
    int achou = 0;
 
    for (int i = 0; i < 10; i++) {
        if (quant[i] < 5) {
            printf("Nome: %s\n", nome[i]);
            printf("Quantidade: %d\n", quant[i]);
            printf("\n");
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum produto precisa de reposicao.\n");
    }
    return 0;
}
 
int entradaMercadorias(char nome[10][100], int quant[10]) {
    int codigo, qtd;
 
    printf("Codigo do produto (1 a 10): ");
    scanf("%d", &codigo);
    if (codigo < 1 || codigo > 10) {
        printf("Codigo invalido.\n");
        return 0;
    }
 
    printf("Quantidade recebida: ");
    scanf("%d", &qtd);
    if (qtd <= 0) {
        printf("Quantidade invalida: deve ser maior que zero.\n");
        return 0;
    }
 
    quant[codigo - 1] += qtd;
    printf("Entrada registrada. %s agora tem %d unidades.\n", nome[codigo - 1], quant[codigo - 1]);
    return 0;
}
 
float faturarVendas(float preco, int quantidade) {
    return preco * quantidade;
}
 
float valorTotalEstoque(float preco[10], int quant[10]) {
    float total = 0;
    for (int i = 0; i < 10; i++) {
        total += preco[i] * quant[i];
    }
    return total;
}
