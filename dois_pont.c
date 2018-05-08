#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

/*typedef struct extremos{
    struct n* cabeca;
    struct n* fim;
}Fila;*/

typedef struct n{
	int i;
	struct n* proximo;
} No;

Fila* criar_fila(){  //Aloca a Struct extremos
    Fila* f = malloc(sizeof(Fila));
	f->cabeca = NULL;
    f->fim = NULL;
	return f;
}


void colocar_fila(Fila* f, int i){// preparar os ponteiros

	No* n = malloc(sizeof(No));
	n->i = i;
	n->proximo = NULL;

	if(f->cabeca == NULL){//caso fila vazia sao setados os ponteiros cabeca e fim
		f->cabeca = n;
        f->fim = n;
	}else{
		No* aux = f->cabeca;
		while(aux->proximo != NULL){//caso não seja o fim da fila faz repeticao ate o fim
			aux = aux->proximo;
		}
		aux->proximo = n;//ultimo cara da fila
        f->fim = n;//fim da fila pelo ponteiro
	}
}


int retirar_fila(Fila* f){ //avanca na fila

	No* n = f->cabeca;
	int i = n->i;
	f->cabeca = n->proximo;
    if(f->fim == f->cabeca){//caso seja o mesmo elemento seta os dois
        f->cabeca = NULL;
        f->fim = NULL;
    }
	free(n);//libera tudo

	return i;
}


int esta_vazia_fila(Fila* f){
	if(f->cabeca == NULL) return 1;//chega se esta vazia a fila
	else return 0;
}


void destruir_fila(Fila* f){
	No* aux = f->cabeca;
	while(aux->proximo != NULL){//avanca toda a fila
		No* n = aux;
		aux = aux->proximo;
		free(n);//libera o que estava sendo usado antes
	}
	free(f->cabeca);//libera cabeca
    free(f->fim);//libera fim
	free(f);//libera tudo
}
