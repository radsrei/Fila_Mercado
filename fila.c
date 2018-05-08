#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

typedef struct n{
	int i;
	struct n* proximo;
} No;


Fila* criar_fila(){
	Fila* f = malloc(sizeof(Fila));
	f->cabeca = NULL;
	return f;
}

void colocar_fila(Fila* f, int i){
	
	No* n = malloc(sizeof(No));
	n->i = i;
	n->proximo = NULL;
	
	if(f->cabeca == NULL){
		f->cabeca = n;
	}else{
		No* aux = f->cabeca;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = n;
	}
	
}

int retirar_fila(Fila* f){
	
	No* n = f->cabeca;
	int i = n->i;
	f->cabeca = n->proximo;
	free(n);
	
	return i;
}

int esta_vazia_fila(Fila* f){
	if(f->cabeca == NULL) return 1;
	else return 0;
}

void destruir_fila(Fila* f){
	No* aux = f->cabeca;
	while(aux->proximo != NULL){
		No* n = aux;
		aux = aux->proximo;
		free(n);
	}
	free(f->cabeca);
	free(f);
}
