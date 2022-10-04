
/* se ja existe biblioteca, existe o arquivo objeto o lista.h nao é compilado novamente */

#ifndef header_lista // macro inicial
#define header_lista //macro inicial

#include <stdlib.h>
#include <stdio.h>

//structs: TProduto, TCelula, TLista
//assinatura das funcoes: LerProduto, ImprimirProduto, FLVazia, Inserir, Pesquisar, Excluir, Imprimir


typedef struct {
  int codigo;
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula *prox;
} TCelula;

typedef struct {
  TCelula *frente;
  TCelula *tras;
  int tamanho;
} TFila;

void LerProduto(TProduto *x);
void ImprimirProduto(TProduto x);
void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
int Tamanho(TFila Fila);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila, TProduto *Item);
void Imprimir(TFila *Fila);
void Imprimir2(TFila *F1);
TProduto Pesquisar(TFila *F1, TProduto x);
void Liberar(TFila *Fila);



#endif //macro final