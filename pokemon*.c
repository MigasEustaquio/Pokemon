#include<stdio.h>
#include<stdlib.h>

typedef struct card{

	char num[3], hp[3], cost[1];
	char atk1[2], atk2[2], dmg1[2], dmg2[2];
	char effect1[3], effect2[3];
	char nivel[2], evolucao[3], power[3];
	char nome[20], tipo[10], weak[10], resis[10];

	struct card *prox;

}CARD;

typedef struct energy{

	int num;
	char nome[10];

	struct energy *proxe;

}ENERGY;

typedef struct trainer{

	int num;
	char nome[20];

	struct trainer *proxt;

}TRAINER;

typedef struct mesa{

	CARD ativa, banco1, banco2, banco3, banco4;

}MESA;

void del();
void iniciar();
void ler(CARD *temp, int i);
void teste(CARD *temp);

CARD *lista=NULL;
ENERGY *listae=NULL, *tempe=NULL;
TRAINER *listat=NULL, *tempt=NULL;

void main(){

	iniciar();

	
}

void iniciar(){

	int i=0;

	CARD *temp = (CARD *) malloc(sizeof(CARD));

//	temp=lista;
//	tempe=listae;
//	tempt=listat;
	
	ler(temp, 1);
//	temp=temp->prox;	
		
//	lere(tempe, i);
//	tempe=tempe->prox;

//	lert(tempt, i);
//	tempt=tempt->prox;
	
	teste(temp);
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

void ler(CARD *temp, int i){

	int j=1;

	FILE *arquivo;
	arquivo=fopen("pokemon.txt", "r");

	fseek(arquivo, 0, 0);

	while(i!=j){
		
		fscanf(arquivo, "%[^\n]s", temp->nome);
		j++;
	}
	
	fscanf(arquivo, "%[^;]s", temp->nome);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->tipo);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->weak);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->resis);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->num);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->hp);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->cost);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->atk1);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->atk2);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->dmg1);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->dmg2);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->effect1);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->effect2);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->nivel);
	fseek(arquivo, 1, 1);
	fscanf(arquivo, "%[^;]s", temp->evolucao);
	fseek(arquivo, 1, 1);
//	fscanf(arquivo, "%[^;]s", temp->power);

	fclose(arquivo);
}

void lere(ENERGY *temp, int i){

	int j=1;

	FILE *arquivo;
	arquivo=fopen("energy.txt", "r");

	fseek(arquivo, SEEK_SET, 0);
	
	while(i!=j){
		
		fscanf(arquivo, "%[^\n]s", temp->nome);
		j++;
	}
		
	fscanf(arquivo, "%[^;]s", temp->nome);
	temp->num=i;
}

void lert(TRAINER *temp, int i){

	int j=1;

	FILE *arquivo;
	arquivo=fopen("trainer.txt", "r");

	fseek(arquivo, SEEK_SET, 0);
	
	while(i!=j){
		
		fscanf(arquivo, "%[^\n]s", temp->nome);
		j++;
	}
		
	fscanf(arquivo, "%[^;]s", temp->nome);
	temp->num=i;
}

void teste(CARD *temp){

	printf("Nome: %s\n%s\nHP:%s\n", temp->nome, temp->tipo, temp->hp);
}
