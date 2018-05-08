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
	
	No* n = malloc(sizeof(No));							//aloca um n�
	n->i = i;											//inicializa as variaveis
	n->proximo = NULL;
	
	if(f->cabeca == NULL){								
		f->cabeca = n;									//a cabe�a aponta para o novo primeiro n�
		f->fim = n;										//o fim aponta  para o novo ultimo n�
		
	}else{													
		f->fim->proximo = n;							//o antigo n� fim aponta para o novo n� fim
		f->fim = n; 									//o extremo fim aponta para o novo fim
	}
	
}

int retirar_fila(Fila* f){								//retira n�s da fila
	
	No* n = f->cabeca;									//n � se torna um ponteiro pro primeiro n�
	int i = n->i;										//i recebe o elemento guardado no primeiro n�
	f->cabeca = n->proximo;								//a cabe�a � atualizada para apontar para o novo primeiro n�
	free(n);											//o antigo primeiro n� � liberado
	
	return i;
}

int esta_vazia_fila(Fila* f){
	if(f->cabeca == NULL) return 1;						//checa se a fila est� vazia e retorna a informa��o
	else return 0;
}

void destruir_fila(Fila* f){
	No* aux = f->cabeca;								//aux recebe o primeiro n�
	while(aux->proximo != f->fim){
		No* n = aux;									
		aux = aux->proximo;								//emquanto o n� apontado pelo proximo nao for o ultimo vai liberando tudo
		free(n);
	}
	free(f->cabeca);									//libera o ultimo n�
	free(f);											//libera a struct extremos
}
