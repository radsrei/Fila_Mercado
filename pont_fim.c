#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

typedef struct n{
	int i;
	struct n* proximo;
} No;


Fila* criar_fila(){
	Fila* f = malloc(sizeof(Fila));						// aloca a struct com o extremo
	f->fim = NULL;										// inicia o ponteiro pra fim em NULL
	return f;
}

void colocar_fila(Fila* f, int i){
	
	No* n = malloc(sizeof(No));							// aloca o nó
	n->i = i;											// inicializa as variaveis do nó
	n->proximo = NULL;
	
	if(f->fim == NULL){									// se a fila estiver vazia o fim passará a apontar para o nó criado
		f->fim = n;
	}else{
		n->proximo = f->fim;							// se a fila nao estiver vazia o novo nó aponta para onde o fim apontava anteriormente
		f->fim = n;										// o fim aponta pro novo nó criado.
	}
	
}

int retirar_fila(Fila* f){
	No* aux = f->fim;		
	No* nov = aux;
					
	while(aux->proximo != NULL){
		nov = aux;
		aux = aux->proximo;
	}
	int i = aux->i;
	nov->proximo = NULL;
	
	return i;
}

int esta_vazia_fila(Fila* f){
	if(f->cabeca == NULL) return 1;
	else return 0;
}

void destruir_fila(Fila* f){
	No* aux = f->fim;
	No* nov = aux;
	
	while(f->fim != NULL){	
		while(aux->proximo != NULL){
			aux = aux->proximo;
			nov->proximo = aux;
		}
		free(aux->proximo);
		nov->proximo = NULL;	
	}
	free(f->fim);
	free(f);
}
