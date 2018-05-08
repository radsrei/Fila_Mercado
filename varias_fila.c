#include <stdlib.h>
#include <stdio.h>

#include "clientes.h"

#include "mercado.h"
#include "fila.h"

#define NUMERO_DE_CAIXAS 5

int main(void){
	printf("mercado\n");
	int tempo = 0;
	
	Caixa* caixas[NUMERO_DE_CAIXAS];
	Fila* filas[NUMERO_DE_CAIXAS];

	for(i =0;i<NUMERO_DE_CAIXAS;i++){
		caixas[i] = criar_caixa();
		filas[i] = criar_fila(); 
	}

	int i = 0;
	while(i<NUMERO_DE_CLIENTES){
		int j = 0;
		while(j<NUMERO_DE_CAIXAS && i<NUMERO_DE_CLIENTES){
			colocar_fila(filas[j], clientes[i]);
			j++;
			i++;
		}
	}

	int temGenteEmUmCaixa = 0;
	int temGenteEmUmaFila = 0;

	for(i =0;i<NUMERO_DE_CAIXAS;i++){
		if(esta_livre_caixa(caixas[i]) == 0){
			temGenteEmUmCaixa = 1;
			break;
		}
	}

	for(i =0;i<NUMERO_DE_CAIXAS;i++){
		if(esta_vazia_fila(filas[i]) == 0){
			temGenteEmUmaFila = 1;
			break;
		}
	}

	while(temGenteEmUmCaixa == 1 || temGenteEmUmaFila == 1){
	 	temGenteEmUmCaixa = 0;
	 	temGenteEmUmaFila = 0;

		for(i =0;i<NUMERO_DE_CAIXAS;i++){
			if(esta_livre_caixa(caixas[i]) == 1){
				printf("caixa %i livre\n",i+1);

				if(esta_vazia_fila(filas[i]) == 0){
					int x = retirar_fila(filas[i]);
					
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

		for(i =0;i<NUMERO_DE_CAIXAS;i++){
			if(esta_vazia_fila(filas[i]) == 0){
				temGenteEmUmaFila = 1;
				break;
			}
		}

		tempo++;
		printf("temGenteEmUmCaixa %i\n",temGenteEmUmCaixa);
		printf("tempo atendendo: %i\n",tempo);
		printf("--------------------\n\n");
	}

	printf("TEMPO: %i\n",tempo);
	
	return 0;
}
