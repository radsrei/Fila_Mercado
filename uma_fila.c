#include <stdlib.h>
#include <stdio.h>

#include "clientes.h"

#include "mercado.h"
#include "fila.h"

#define NUMERO_DE_CAIXAS 5

int main(void){
	printf("mercado\n");
	int tempo = 0;
	int i;
	
	Caixa* caixas[NUMERO_DE_CAIXAS];
	Fila* fila = criar_fila();

	for(i =0;i<NUMERO_DE_CLIENTES;i++){
		colocar_fila(fila, clientes[i]);
	}

	for(i =0;i<NUMERO_DE_CAIXAS;i++){
		caixas[i] = criar_caixa(); 
	}

	int temGenteEmUmCaixa = 0;

	for(i =0;i<NUMERO_DE_CAIXAS;i++){
		if(esta_livre_caixa(caixas[i]) == 0){
			temGenteEmUmCaixa = 1;
			break;
		}
	}

	while(esta_vazia_fila(fila) == 0 || temGenteEmUmCaixa == 1){
		temGenteEmUmCaixa = 0;

		for(i =0;i<NUMERO_DE_CAIXAS;i++){
			if(esta_livre_caixa(caixas[i]) == 1){
				printf("caixa %i livre\n",i+1);

				if(esta_vazia_fila(fila) == 0){
					int x = retirar_fila(fila);
					
					printf("um cliente com %i itens foi chamado\n",x);

					iniciar_atendimento_caixa(&caixas[i], x);
					printf("caixa %i iniciou atendimento\n\n",i+1);
				}
			}else{
				processar_item_caixa(&caixas[i]);
			}
		}

		for(i =0;i<NUMERO_DE_CAIXAS;i++){
			if(esta_livre_caixa(caixas[i]) == 0){
				temGenteEmUmCaixa = 1;
				break;
			}
		}

		tempo++;
		printf("temGenteEmUmCaixa %i\n",temGenteEmUmCaixa);
		printf("fila vazia %i\n",esta_vazia_fila(fila));
		printf("tempo atendendo: %i\n",tempo);
		printf("--------------------\n\n");
	}

	printf("TEMPO: %i\n",tempo);
	
	return 0;
}
