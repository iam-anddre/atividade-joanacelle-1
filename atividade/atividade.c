#include <stdio.h>
#include "front.h"

int main() {
    int op;
    int quant[10];
    char nome[10][100];
    float preco[10];

    do {
        escreveMenu();
        scanf("%d", &op);

        switch (op) {
        case 1:
            cadastrarProdutos(nome, preco, quant);
            break;

        case 2:
            consultarEstoque(nome, preco, quant);
            break;

        case 3:
            registrarVendas(nome, quant);
            break;

        case 4:
            reposicaoProdutos(nome, quant);
            break;

        case 5:
            entradaMercadorias(nome, quant);
            break;

        case 6:
             faturarVendas(nome, preco, quant);
            break;

        case 7:
            break;

        default:
            printf("Opcao invalida");
        }
    } while (op != 7);

    return 0;
}