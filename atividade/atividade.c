#include <stdio.h>
#include "front.h"

int main() {
    int op;
    int quant[10] = {0};
    char nome[10][100] = {""};
    float preco[10] = {0};

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
            registrarVendas(nome, preco, quant);
            break;

        case 4:
            reposicaoProdutos(nome, quant);
            break;

        case 5:
            entradaMercadorias(nome, quant);
            break;

        case 6:
            printf("Valor total do estoque: %.2f\n", valorTotalEstoque(preco, quant));
            break;

        default:
            printf("Opcao invalida\n");
        }
    } while (op != 6);

    return 0;
}
