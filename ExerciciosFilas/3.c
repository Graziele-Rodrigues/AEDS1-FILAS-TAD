#include <stdio.h>
#include <stdlib.h>
#include "fila.c"


void RemoveItem(TFila *Fila, int i){
	if(Fila->tamanho< i){
		printf("Fila e menor que %d\n", i);
	}else{
		int count = 1;
		TFila aux;
		TProduto x;
		FFVazia(&aux);
		while(!Vazia(*Fila)){
			Desenfileirar(Fila, &x);
			if (count != i){
				Enfileirar(x, &aux);
			}
			count++;
		}
		while(!Vazia(aux)){
			Desenfileirar(&aux, &x);
			Enfileirar(x, Fila);
		}
        Liberar(&aux);
	}
}


int main(){
    TFila F1;
    TProduto p;
    FFVazia(&F1);
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F1);
    }
    RemoveItem(&F1, 4);
    Imprimir(&F1);
}