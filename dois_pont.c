#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

typedef struct n{
	int i;
	struct n* proximo;
} No;


Fila* criar_fila(){										
	Fila* f = malloc(sizeof(Fila));						//aloca a struct extremos
	f->cabeca = NULL;									//inicializa as variaveis
	f->fim = NULL;
	return f;
}

void colocar_fila(Fila* f, int i){						
	
	No* n = malloc(sizeof(No));							//aloca um nó
	n->i = i;											//inicializa as variaveis
	n->proximo = NULL;
	
	if(f->cabeca == NULL){								
		f->cabeca = n;									//a cabeça aponta para o novo primeiro nó
		f->fim = n;										//o fim aponta  para o novo ultimo nó
		
	}else{													
		f->fim->proximo = n;							//o antigo nó fim aponta para o novo nó fim
		f->fim = n; 									//o extremo fim aponta para o novo fim
	}
	
}

int retirar_fila(Fila* f){								//retira nós da fila
	
	No* n = f->cabeca;									//n é se torna um ponteiro pro primeiro nó
	int i = n->i;										//i recebe o elemento guardado no primeiro nó
	f->cabeca = n->proximo;								//a cabeça é atualizada para apontar para o novo primeiro nó
	free(n);											//o antigo primeiro nó é liberado
	
	return i;
}

int esta_vazia_fila(Fila* f){
	if(f->cabeca == NULL) return 1;						//checa se a fila está vazia e retorna a informação
	else return 0;
}

void destruir_fila(Fila* f){
	No* aux = f->cabeca;								//aux recebe o primeiro nó
	while(aux->proximo != f->fim){
		No* n = aux;									
		aux = aux->proximo;								//emquanto o nó apontado pelo proximo nao for o ultimo vai liberando tudo
		free(n);
	}
	free(f->cabeca);									//libera o ultimo nó
	free(f);											//libera a struct extremos
}
