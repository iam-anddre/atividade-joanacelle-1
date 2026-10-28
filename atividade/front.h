#ifndef front_h
#define front_h

void escreveMenu();
int cadastrarProdutos(char nome[10][100], float preco[10], int quant[10]);
int consultarEstoque(char nome[10][100], float preco[10], int quant[10]);
int registrarVendas(char nome[10][100], float preco[10], int quant[10]);
int reposicaoProdutos(char nome[10][100], int quant[10]);
int entradaMercadorias(char nome[10][100], int quant[10]);
float faturarVendas(float preco, int quantidade);
float valorTotalEstoque(float preco[10], int quant[10]);
 
#endif
 
