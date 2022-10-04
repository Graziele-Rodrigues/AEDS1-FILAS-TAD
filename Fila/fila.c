#include <stdio.h>
#include <stdlib.h>
#include "fila.h"  //usa aspas duplas pois esta na raiz do projeto

/* corpo das funcoes que possuem assinatura em lsita.h */

void LerProduto(TProduto *x) { //passando por referencia -> alteraçoes afetam fora da funcao
  printf("\ndigite o nome: ");
  fflush(stdin);
  fgets(x->nome, 100, stdin);
  printf("\ndigite o codigo: ");
  fflush(stdin);
  scanf("%d", &x->codigo);
  printf("\ndigite a quantidade: ");
  fflush(stdin);
  scanf("%d", &x->quantidade);
  printf("\ndigite o preco: ");
  fflush(stdin);
  scanf("%f", &x->preco);
}

void ImprimirProduto(TProduto x) { // passagem por valor
  printf("Produto: %s", x.nome);
  printf("Codigo: %d\n", x.codigo);
  printf("Quantidade: %d\n", x.quantidade);
  printf("Preco: %.2f\n", x.preco);
  printf("\n-------------------------------\n");
}

void FFVazia(TFila *Fila){
  Fila->frente = (TCelula*) malloc(sizeof(TCelula));
  Fila->tras = Fila->frente;
  Fila->frente->prox = NULL;
  Fila->tamanho = 0;
}

int Vazia(TFila Fila) { // verifica se a lista ta vazia
  return (Fila.frente == Fila.tras); // retorna verdadeiro ou falso, comparando os dois, se
                         // forem iguais retorna 1, diferentes 0.
}

int Tamanho(TFila Fila) { return Fila.tamanho; } 

void Enfileirar(TProduto x, TFila *Fila){
  Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
  Fila->tras = Fila->tras->prox;
  Fila->tras->item = x;
  Fila->tras->prox = NULL;
  Fila->tamanho++;
}


void Desenfileirar(TFila *Fila, TProduto *Item){
  TCelula *aux;
  if(!Vazia(*Fila)){
    aux = Fila->frente->prox;
    Fila->frente->prox = aux->prox;
    *Item = aux->item;
    free(aux);
    if(Fila->frente->prox == NULL){
      Fila->tras = Fila->frente;
      Fila->tamanho--;
    }
  }
}


void Imprimir(TFila *F1){
  TProduto x;
  TFila F2;
  FFVazia(&F2);

  while(!Vazia(*F1)){
    Desenfileirar(F1, &x);
    Enfileirar(x, &F2);
  }
  while(!Vazia(F2)){
    Desenfileirar(&F2, &x);
    ImprimirProduto(x);
    Enfileirar(x, F1);
  }
  free(F2.frente);
}

void Imprimir2(TFila *F1){
  TProduto x;
  TFila F2;
  FFVazia(&F2);
  int n1 = Tamanho(*F1);
  while(n1!=0){
    Desenfileirar(F1, &x);
    Enfileirar(x, &F2);
    n1--;
  }
  int n2 = Tamanho(F2);
  while(n2!=0){
    Desenfileirar(&F2, &x);
    ImprimirProduto(x);
    Enfileirar(x, F1);
    n2--;
  }
  free(F2.frente);
}


TProduto Pesquisar(TFila *F1, TProduto x){
  TFila F2;
  FFVazia(&F2);
  TProduto y, z;
  int flag=0;
  while(!Vazia(*F1)){
    Desenfileirar(F1, &y);
    Enfileirar(y, &F2);
    if(y.codigo == x.codigo){
      flag = 1;
      z =y;
    }
  }

  while(!Vazia(F2)){
    Desenfileirar(&F2, &y);
    Enfileirar(y, F1);
  }
  if(flag==1){
    return z;
  }
  else{
    z.codigo=-1;
    return z;
  }
}


void Liberar(TFila* Fila){
	TFila aux;
	FFVazia(&aux);
	TProduto x;
	while (!Vazia(*Fila)){
		Desenfileirar(Fila, &x);
		ImprimirProduto(x);
		Enfileirar(x, &aux);
	}
	while (!Vazia(aux)){
		Desenfileirar(&aux, &x);
		Enfileirar(x, Fila);
	}
	free(aux.frente);
}
