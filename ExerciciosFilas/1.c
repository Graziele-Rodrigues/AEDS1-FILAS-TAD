#include <stdio.h>
#include <stdlib.h>
#include "fila.c"


void LiberarFifo(TFila* Fila){
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


int main(){
    TFila F1;
    TProduto p;
    FFVazia(&F1);
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F1);
    }
    LiberarFifo(&F1);
}