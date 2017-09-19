#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "arq.h"

void del();
void iniciar(CARD *temp, ENERGY *tempe, TRAINER *tempt, int tipo, int num);
void ler(CARD *temp, int i);
void lere(ENERGY *tempe, int i);
void lert(TRAINER *tempt, int i);
void teste(CARD *temp, ENERGY *tempe, TRAINER *tempt);
void mesa();
void teste2(MESA *mesa);

void main(){

	mesa();
}

void iniciar(CARD *temp, ENERGY *tempe, TRAINER *tempt, int tipo, int num){

	switch(tipo){	

	case 1:
		ler(temp, num);
		break;

	case 2:		

		lere(tempe, num);
		break;

	case 3:
		lert(tempt, num);
		break;
	}
	
//	teste(temp, tempe, tempt);
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
	
	int tipoCarta, numCarta;

	tipoCarta=1;
	numCarta=1;

	CARD *temp = (CARD *) malloc(sizeof(CARD));
	ENERGY *tempe = (ENERGY *) malloc(sizeof(ENERGY));
	TRAINER *tempt = (TRAINER *) malloc(sizeof(TRAINER));
	MESA *mesa = (MESA *) malloc(sizeof(MESA));

	iniciar(temp, tempe, tempt, tipoCarta, numCarta);
	CARD *card1 = (CARD *) malloc(sizeof(CARD));
	*card1=*temp;
	mesa->ativo=card1;

	numCarta=3;

	iniciar(temp, tempe, tempt, tipoCarta, numCarta);	
	CARD *card2 = (CARD *) malloc(sizeof(CARD));
	*card2=*temp;
	mesa->banco1=card2;

	teste2(mesa);
}

void teste(CARD *temp, ENERGY *tempe, TRAINER *tempt){

//	printf("NOME: %s\nTIPO: %s\nWEAK: %s\nRESIS: %s\nNUM: %d\nHP: %d\nCOST: %d\nATK1: %d\nATK2: %d\nDMG1: %d\nDMG2: %d\nEFFECT1: %d\nEFFECT2: %d\nNIVEL: %d\nEVOLUCAO: %d\nPOWER: %d\n", temp->nome, temp->tipo, temp->weak, temp->resis, temp->num, temp->hp, temp->cost, temp->atk1, temp->atk2, temp->dmg1, temp->dmg2, temp->effect1, temp->effect2, temp->nivel, temp->evolucao, temp->power);

//	printf("NOME: %s\nNUM: %d\n", tempt->nome, tempt->num);
}

void teste2(MESA *mesa){

	printf("NOME1:%s\nNOME2:%s\n", mesa->ativo->nome, mesa->banco1->nome);
}
