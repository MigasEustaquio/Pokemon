#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "arq.h"

void del();
void preiniciar(MESA *mesa);
void iniciar(MESA *mesa, int tipo, int num);
void iniciare(MESA *mesa, int tipo, int num);
void iniciart(MESA *mesa, int tipo, int num);
void ler(CARD *temp, int i);
void lere(ENERGY *tempe, int i);
void lert(TRAINER *tempt, int i);
void teste(CARD *temp);
void mesa();
void teste2(MESA *mesa);
void imprimirMesa(MESA *mesa);

int cont=0;

void main(){

	mesa();
}

void preiniciar(MESA *mesa){

	int tipo, num;

	printf("\n\tADICIONAR CARD\n");

	printf("\nQual o tipo de carta deseja criar?\n\t1-Pokemon(disponivel ate '3')\n\t2-Energia(disponivel ate '9')\n\t3-Treinador(disponivel ate '7')\n");
	scanf("%d", &tipo);
	printf("\nQual o numero da carta?\n");
	scanf("%d", &num);

	switch(tipo){	

	case 1:
		iniciar(mesa, tipo, num);
		break;

	case 2:		
		iniciare(mesa, tipo, num);
		break;

	case 3:
		iniciart(mesa, tipo, num);
		break;
	}

	printf("\nCARD ADICIONADO COM SUCESSO\n");
}

void iniciar(MESA *mesa, int tipo, int num){

	CARD *temp = (CARD *) malloc(sizeof(CARD));
	ler(temp, num);

	if(cont==0){

		mesa->ativo=temp;
		cont++;
	}
	else{

		mesa->banco[cont-1]=temp;
		cont++;
	}
}

void iniciare(MESA *mesa, int tipo, int num){

	ENERGY *tempe = (ENERGY *) malloc(sizeof(ENERGY));
	lere(tempe, num);
}

void iniciart(MESA *mesa, int tipo, int num){

	TRAINER *tempt = (TRAINER *) malloc(sizeof(TRAINER));
	lert(tempt, num);
}

/*void del(){
	CARD *no = lista, *aux;
	while (no != NULL)
	{
        	aux = no;
	        no = no->prox;
        	free (aux);
    	}
	ENERGY *noe = listae, *auxe;
    	while (noe != NULL)
    	{
        	auxe = noe;
	        noe = noe->prox;
        	free (auxe);
    	}
	TRAINER *not = listat, *auxt;
    	while (not != NULL)
    	{
        	auxt = not;
	        not = not->prox;
        	free (auxt);
    	}
}*/

void mesa(){
	
	int i=0, j=0;

	MESA *mesa = (MESA *) malloc(sizeof(MESA));

	while(j==0){

		printf("\nO que deseja fazer?\n1-Adicionar card a mesa\n2-???????????????\n3-???????????????\n4-???????????????\n5-???????????????\n6-???????????????\n7-???????????????\n8-???????????????\n9-Mostrar mesa(Apenas cards de pokemon)\n0-Encerrar\n");
		scanf("%d", &i);
	
		switch(i){

			case 1:
				preiniciar(mesa);
				break;
			case 9:
				imprimirMesa(mesa);
				break;
			case 0:
				j=1;
				printf("\n\tPrograma Encerrado\n");
				break;

		}
	}
}

void imprimirMesa(MESA *mesa){

	printf("\n\tIMPRIMIR MESA\n\n");

	if(mesa->ativo==NULL){

		printf("Nenhum Pokemon na mesa\n");
		return;
	}
	else{

		teste(mesa->ativo);

		if(mesa->banco[0]==NULL)
			return;
		else{

			teste(mesa->banco[0]);

			if(mesa->banco[1]==NULL)
				return;
			else{

				teste(mesa->banco[1]);

				if(mesa->banco[2]==NULL)
					return;
				else{

					teste(mesa->banco[2]);

					if(mesa->banco[3]==NULL)
						return;
					else
						teste(mesa->banco[3]);
				}
			}
		}
	}
}

void teste(CARD *temp){

	printf("NOME: %s\nTIPO: %s\nWEAK: %s\nRESIS: %s\nNUM: %d\nHP: %d\nCOST: %d\nATK1: %d\nATK2: %d\nDMG1: %d\nDMG2: %d\nEFFECT1: %d\nEFFECT2: %d\nNIVEL: %d\nEVOLUCAO: %d\nPOWER: %d\n\n", temp->nome, temp->tipo, temp->weak, temp->resis, temp->num, temp->hp, temp->cost, temp->atk1, temp->atk2, temp->dmg1, temp->dmg2, temp->effect1, temp->effect2, temp->nivel, temp->evolucao, temp->power);

//	printf("NOME: %s\nNUM: %d\n", tempt->nome, tempt->num);
}

void teste2(MESA *mesa){

	printf("NOME1:%s\nNOME2:%s\nNOME3:%s\n", mesa->ativo->nome, mesa->banco[0]->nome, mesa->banco[1]->nome);
}
