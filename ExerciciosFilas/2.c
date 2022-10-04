#include <stdio.h>
#include <stdlib.h>
#include "fila.c"



int Compara(TFila *F1, TFila *F2){
    int flag=0;
	TProduto x, y;
	TFila aux;
	FFVazia(&aux);
    if(Tamanho(*F1) == Tamanho(*F2)){
        while(!Vazia(*F1)){
            Desenfileirar(F1, &x);
            Enfileirar(x, &aux);
            y = Pesquisar(F2, x);
            if(y.codigo==-1){
                flag=1;
            }
        }
        while (!Vazia(aux)){
            Desenfileirar(&aux, &x);
            Enfileirar(x, F1);
        }
        Liberar(&aux);
    }else{
        flag=1;
    }
    return flag;
}

int main(){
    int igual;
    TFila F1, F2;
    TProduto p;
    FFVazia(&F1);
    FFVazia(&F2);
    printf("FILA 1\n");
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F1);
    }
    printf("FILA 2\n");
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &F2);
    }
    igual = Compara(&F1, &F2);
    if(igual==0){
        printf("EH IGUAL!");
    }else{
        printf("NAO EH IGUAL");
    }
}