#include <stdio.h>
#include <stdlib.h>
#include "fila.c"


void Diferenca(TFila *F1, TFila* F2, TFila* F3){
	TProduto x, y;
	TFila aux;
	FFVazia(&aux);
	while (!Vazia(*F1)){
		Desenfileirar(F1, &x);
		Enfileirar(x, &aux);
        y = Pesquisar(F2, x);
		if (y.codigo == -1){
			Enfileirar(x, F3);
		}
	}
	while (!Vazia(aux)){
		Desenfileirar(&aux, &x);
		Enfileirar(x, F1);
	}
	Liberar(&aux);
}


int main(){
    TFila F1, F2, F3;
    TProduto p;
    FFVazia(&F1);
    FFVazia(&F2);
    FFVazia(&F3);
    printf("\nITENS FILA 1\n");
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F1);
    }
    printf("\nITENS FILA 2\n");
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F2);
    }
    Diferenca(&F1, &F2, &F3);
    Imprimir(&F3);
}