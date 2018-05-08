#include <stdlib.h>
#include <stdio.h>

#include "mercado.h"

Caixa* criar_caixa(){
	Caixa* c = malloc(sizeof(Caixa));
	c->ocupado = 0;
	c->total_itens = 0;
	c->atual_itens = 0;
	return c;
}

void iniciar_atendimento_caixa(Caixa** c, int quantidade){
	(*c)->ocupado = 1;
	(*c)->total_itens = quantidade;
}

int esta_livre_caixa(Caixa* c){
	if(c->ocupado == 0) return 1;
	else return 0;
}

void processar_item_caixa(Caixa** c){
	(*c)->atual_itens++;
	if((*c)->atual_itens == (*c)->total_itens){
		(*c)->ocupado = 0;
		(*c)->total_itens = 0;
		(*c)->atual_itens = 0;
	}
}
