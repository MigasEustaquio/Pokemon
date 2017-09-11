#include<stdio.h>
#include<stdlib.h>

typedef struct card{

	int num, hp, cost;
	int atk1, atk2, dmg1, dmg2;
	int effect1, effect2;
	int evolucao[2], power;
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
	int effect;

	struct trainer *proxt;

}TRAINER;

void add(int i);
void adde(int i);
void addt(int i);
void criar();
void criare();
void criart();
void del();
void iniciar();
void ler();

CARD *lista=NULL, *temp=NULL;
ENERGY *listae=NULL, *tempe=NULL;
TRAINER *listat=NULL, *tempt=NULL;

void main(){

	iniciar();

	
}

void iniciar(){

	int i=0;


	for(i=0;i<151;i++)
		add(i);

	for(i=0;i<m;i++)
		adde(i);

	for(i=0;i<n;i++)
		addt(i);

	temp=lista;
	tempe=listae;
	tempt=listat;

	for(i=1;i<=151;i++){
		
		ler(temp, i);
		temp=temp->prox;	
	}

	for(i=0;i<m;i++){
		
		lere(tempe, i);
		tempe=tempe->prox;
	}

	for(i=0;i<m;i++){
		
		lert(tempt, i);
		tempt=tempt->prox;
	}
	
}

void add(int i){

	CARD *novo = (CARD *) malloc(sizeof(CARD));
	novo->num = i+1;
	novo->prox = NULL;

	if(lista == NULL){

		lista=novo;
		return;
	}
	else{

		CARD *aux = lista;

		while(aux->prox != NULL){

			aux = aux->prox;
		}

		aux->prox = novo;
	}
}

void adde(int i){

	ENERGY *new = (ENERGY *) malloc(sizeof(ENERGY));
	new->num = i+1;
	new->prox = NULL;

	if(lista == NULL){

		listae=new;
		return;
	}
	else{

		ENERGY *aux1 = listae;

		while(aux1->prox != NULL){

			aux1 = aux1->prox;
		}

		aux1->prox = new;
	}
}

void addt(int i){

	TRAINER *novo = (TRAINER *) malloc(sizeof(TRAINER));
	novo->num = i+1;
	novo->prox = NULL;

	if(lista == NULL){

		listat=novo;
		return;
	}
	else{

		TRAINER *aux = listat;

		while(aux->prox != NULL){

			aux = aux->prox;
		}

		aux->prox = novo;
	}
}

void del(){

	CARD *no = lista, *aux;
	while (no != NULL)
	{
        	aux = no;
	        no = no->proximo;
        	free (aux);
    	}

	ENERGY *noe = listae, *auxe;
    	while (noe != NULL)
    	{
        	auxe = noe;
	        noe = noe->proximo;
        	free (auxe);
    	}

	TRAINER *not = listat, *auxt;
    	while (not != NULL)
    	{
        	auxt = not;
	        not = not->proximo;
        	free (auxt);
    	}
}

void ler(CARD *temp, int i){

	int j=1;

	FILE *arquivo;
	arquivo=fopen("pokemons.txt", "r");

	fseek(arquivo, SEEK_SET, 0);
	
	while(i!=j){
		
		fscanf(arquivo, "%[^\n]s", temp->nome);
		j++;
	}
		
	fscanf(arquivo, "%[^;]s", temp->nome);
	fscanf(arquivo, "%[^;]s", temp->tipo);
	fscanf(arquivo, "%[^;]s", temp->weak);
	fscanf(arquivo, "%[^;]s", temp->resis);
	fscanf(arquivo, "%[^;]d", temp->num);
	fscanf(arquivo, "%[^;]d", temp->hp);
	fscanf(arquivo, "%[^;]d", temp->cost);
	fscanf(arquivo, "%[^;]d", temp->atk1);
	fscanf(arquivo, "%[^;]d", temp->atk2);
	fscanf(arquivo, "%[^;]d", temp->dmg1);
	fscanf(arquivo, "%[^;]d", temp->dmg2);
	fscanf(arquivo, "%[^;]d", temp->effect1);
	fscanf(arquivo, "%[^;]d", temp->effect2);
	fscanf(arquivo, "%[^;]d", temp->evolucao[0]);
	fscanf(arquivo, "%[^;]d", temp->evolucao[1]);
	fscanf(arquivo, "%[^;]d", temp->power);

	fclose(arquivo);
}

void lere(){

	
}

void lert(){

	
}

void criar(){

	switch(temp->num){

		case 1:

			temp->nome="Bulbasaur";
			temp->hp=40;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=2;
			temp->dmg2=NULL;
			temp->atk2=NULL;
			temp->dmg1=20;
			temp->effect1=1;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis=NULL;

			break;

		case 2:

			temp->nome="Ivysaur";
			temp->hp=60;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=1;
			temp->cost=1;
			temp->atk1=12;
			temp->atk2=3;
			temp->dmg1=30;
			temp->dmg2=20;
			temp->effect1=NULL;
			temp->effect2=2;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis="NULL";

			break;

		case 3:

			temp->nome="Venusaur";
			temp->hp=100;
			temp->tipo="GRASS";
			temp->evolucao[0]=2;
			temp->evolucao[1]=2;
			temp->cost=2;
			temp->atk1=4;
			temp->atk2=NULL;
			temp->dmg1=60;
			temp->dmg2=NULL;
			temp->effect1=NULL;
			temp->effect2=NULL;
			temp->power=1;
			temp->weak="FIRE";
			temp->resis="NULL";

			break;

		case 4:

			temp->nome="Charmander";
			temp->hp=50;
			temp->tipo="FIRE";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=10;
			temp->atk2=11;
			temp->dmg1=10;
			temp->dmg2=30;
			temp->effect1=NULL;
			temp->effect2=3;
			temp->power=NULL;
			temp->weak="WATER";
			temp->resis=NULL;

			break;

		case 5:

			temp->nome="Charmeleon";
			temp->hp=80;
			temp->tipo="FIRE";
			temp->evolucao[0]=1;
			temp->evolucao[1]=4;
			temp->cost=1;
			temp->atk1=30;
			temp->atk2=21;
			temp->dmg1=30;
			temp->dmg2=50;
			temp->effect1=NULL;
			temp->effect2=3;
			temp->power=NULL;
			temp->weak="WATER";
			temp->resis=NULL;

			break;

		case 6:

			temp->nome="Charizard";
			temp->hp=120;
			temp->tipo="FIRE";
			temp->evolucao[0]=2;
			temp->evolucao[1]=5;
			temp->cost=3;
			temp->atk1=4;
			temp->atk2=NULL;
			temp->dmg1=100;
			temp->dmg2=NULL;
			temp->effect1=4;
			temp->effect2=NULL;
			temp->power=2;
			temp->weak="WATER";
			temp->resis="FIGHT";

			break;

		case 7:

			temp->nome="Squirtle";
			temp->hp=40;
			temp->tipo="WATER";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=11;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=5;
			temp->effect2=6;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis=NULL;

			break;

		case 8:

			temp->nome="Wartortle";
			temp->hp=70;
			temp->tipo="WATER";
			temp->evolucao[0]=1;
			temp->evolucao[1]=7;
			temp->cost=1;
			temp->atk1=11;
			temp->atk2=12;
			temp->dmg1=NULL;
			temp->dmg2=40;
			temp->effect1=6;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis=NULL;

			break;

		case 9:

			temp->nome="Blastoise";
			temp->hp=100;
			temp->tipo="WATER";
			temp->evolucao[0]=2;
			temp->evolucao[1]=8;
			temp->cost=3;
			temp->atk1=3;
			temp->atk2=NULL;
			temp->dmg1=40;
			temp->dmg2=NULL;
			temp->effect1=7;
			temp->effect2=NULL;
			temp->power=3;
			temp->weak="THUNDER";
			temp->resis=NULL;

			break;

		case 10:

			temp->nome="Caterpie";
			temp->hp=40;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=NULL;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=5;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis=NULL;

			break;

		case 11:

			temp->nome="Metapod";
			temp->hp=70;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=10;
			temp->cost=2;
			temp->atk1=20;
			temp->atk2=2;
			temp->dmg1=NULL;
			temp->dmg2=20;
			temp->effect1=6;
			temp->effect2=5;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis=NULL;

			break;

		case 12:

			temp->nome="Butterfree";
			temp->hp=70;
			temp->tipo="GRASS";
			temp->evolucao[0]=2;
			temp->evolucao[1]=11;
			temp->cost=0;
			temp->atk1=20;
			temp->atk2=4;
			temp->dmg1=20;
			temp->dmg2=40;
			temp->effect1=8;
			temp->effect2=9;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis="FIGHT";

			break;

		case 13:

			temp->nome="Weedle";
			temp->hp=40;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=NULL;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=10;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis=NULL;

			break;

		case 14:

			temp->nome="Kakuna";
			temp->hp=80;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=13;
			temp->cost=2;
			temp->atk1=20;
			temp->atk2=2;
			temp->dmg1=NULL;
			temp->dmg2=20;
			temp->effect1=11;
			temp->effect2=10;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis=NULL;

			break;

		case 15:

			temp->nome="Beedrill";
			temp->hp=80;
			temp->tipo="GRASS";
			temp->evolucao[0]=2;
			temp->evolucao[1]=14;
			temp->cost=0;
			temp->atk1=30;
			temp->atk2=3;
			temp->dmg1=NULL;
			temp->dmg2=40;
			temp->effect1=12;
			temp->effect2=10;
			temp->power=NULL;
			temp->weak="FIRE";
			temp->resis="FIGHT";

			break;

		case 16:

			temp->nome="Pidgey";
			temp->hp=40;
			temp->tipo="NORMAL";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=20;
			temp->atk2=NULL;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=8;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis="FIGHT";

			break;

		case 17:

			temp->nome="Pidgeotto";
			temp->hp=60;
			temp->tipo="NORMAL";
			temp->evolucao[0]=1;
			temp->evolucao[1]=16;
			temp->cost=1;
			temp->atk1=20;
			temp->atk2=30;
			temp->dmg1=20;
			temp->dmg2=NULL;
			temp->effect1=8;
			temp->effect2=13;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis="FIGHT";

			break;

		case 18:

			temp->nome="Pidgeot";
			temp->hp=80;
			temp->tipo="NORMAL";
			temp->evolucao[0]=2;
			temp->evolucao[1]=17;
			temp->cost=0;
			temp->atk1=20;
			temp->atk2=30;
			temp->dmg1=20;
			temp->dmg2=30;
			temp->effect1=NULL;
			temp->effect2=14;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis="FIGHT";

			break;

		case 19:

			temp->nome="Ratata";
			temp->hp=30;
			temp->tipo="NORMAL";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=0;
			temp->atk1=10;
			temp->atk2=NULL;
			temp->dmg1=20;
			temp->dmg2=NULL;
			temp->effect1=NULL;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis="PSICH";

			break;

		case 20:

			temp->nome="Raticate";
			temp->hp=60;
			temp->tipo="NORMAL";
			temp->evolucao[0]=1;
			temp->evolucao[1]=19;
			temp->cost=1;
			temp->atk1=10;
			temp->atk2=10;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=15;
			temp->effect2=16;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis="PSICH";

			break;

		case 21:

			temp->nome="Spearow";
			temp->hp=50;
			temp->tipo="NORMAL";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=0;
			temp->atk1=10;
			temp->atk2=30;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=NULL;
			temp->effect2=13;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis="FIGHT";

			break;

		case 22:

			temp->nome="Fearow";
			temp->hp=70;
			temp->tipo="NORMAL";
			temp->evolucao[0]=1;
			temp->evolucao[1]=21;
			temp->cost=0;
			temp->atk1=30;
			temp->atk2=40;
			temp->dmg1=20;
			temp->dmg2=40;
			temp->effect1=17;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="THUNDER";
			temp->resis="FIGHT";

			break;

		case 23:

			temp->nome="Ekans";
			temp->hp=40;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=11;
			temp->dmg1=NULL;
			temp->dmg2=20;
			temp->effect1=10;
			temp->effect2=5;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 24:

			temp->nome="Arbok";
			temp->hp=60;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=23;
			temp->cost=2;
			temp->atk1=1;
			temp->atk2=21;
			temp->dmg1=10;
			temp->dmg2=20;
			temp->effect1=8;
			temp->effect2=2;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 25:

			temp->nome="Pikachu";
			temp->hp=40;
			temp->tipo="THUNDER";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=10;
			temp->atk2=11;
			temp->dmg1=10;
			temp->dmg2=30;
			temp->effect1=NULL;
			temp->effect2=18;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis=NULL;

			break;

		case 26:

			temp->nome="Raichu";
			temp->hp=80;
			temp->tipo="THUNDER";
			temp->evolucao[0]=1;
			temp->evolucao[1]=25;
			temp->cost=1;
			temp->atk1=12;
			temp->atk2=31;
			temp->dmg1=20;
			temp->dmg2=60;
			temp->effect1=17;
			temp->effect2=19;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis=NULL;

			break;

		case 27:

			temp->nome="Sandshrew";
			temp->hp=40;
			temp->tipo="FIGHT";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=NULL;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=20;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="GRASS";
			temp->resis="THUNDER";

			break;

		case 28:

			temp->nome="Sandslash";
			temp->hp=70;
			temp->tipo="FIGHT";
			temp->evolucao[0]=1;
			temp->evolucao[1]=27;
			temp->cost=1;
			temp->atk1=20;
			temp->atk2=2;
			temp->dmg1=20;
			temp->dmg2=NULL;
			temp->effect1=NULL;
			temp->effect2=21;
			temp->power=NULL;
			temp->weak="GRASS";
			temp->resis="THUNDER";

			break;

		case 29:

			temp->nome="NidoranF";
			temp->hp=60;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=2;
			temp->dmg1=NULL;
			temp->dmg2=NULL;
			temp->effect1=22;
			temp->effect2=23;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 30:

			temp->nome="Nidorina";
			temp->hp=70;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=29;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=12;
			temp->dmg1=NULL;
			temp->dmg2=NULL;
			temp->effect1=24;
			temp->effect2=12;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 31:

			temp->nome="Nidoqueen";
			temp->hp=90;
			temp->tipo="GRASS";
			temp->evolucao[0]=2;
			temp->evolucao[1]=30;
			temp->cost=3;
			temp->atk1=11;
			temp->atk2=22;
			temp->dmg1=20;
			temp->dmg2=50;
			temp->effect1=25;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 32:

			temp->nome="NidoranM";
			temp->hp=40;
			temp->tipo="GRASS";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=1;
			temp->atk2=NULL;
			temp->dmg1=30;
			temp->dmg2=NULL;
			temp->effect1=26;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 33:

			temp->nome="Nidorino";
			temp->hp=60;
			temp->tipo="GRASS";
			temp->evolucao[0]=1;
			temp->evolucao[1]=32;
			temp->cost=1;
			temp->atk1=12;
			temp->atk2=22;
			temp->dmg1=NULL;
			temp->dmg2=50;
			temp->effect1=12;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 34:

			temp->nome="Nidoking";
			temp->hp=90;
			temp->tipo="GRASS";
			temp->evolucao[0]=2;
			temp->evolucao[1]=33;
			temp->cost=3;
			temp->atk1=12;
			temp->atk2=3;
			temp->dmg1=30;
			temp->dmg2=20;
			temp->effect1=27;
			temp->effect2=28;
			temp->power=NULL;
			temp->weak="PSICH";
			temp->resis=NULL;

			break;

		case 35:

			temp->nome="Clefairy";
			temp->hp=40;
			temp->tipo="NORMAL";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=10;
			temp->atk2=30;
			temp->dmg1=NULL;
			temp->dmg2=NULL;
			temp->effect1=29;
			temp->effect2=30;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis="PSICH";

			break;

		case 36:

			temp->nome="Clefable";
			temp->hp=70;
			temp->tipo="NORMAL";
			temp->evolucao[0]=1;
			temp->evolucao[1]=35;
			temp->cost=2;
			temp->atk1=10;
			temp->atk2=20;
			temp->dmg1=NULL;
			temp->dmg2=NULL;
			temp->effect1=30;
			temp->effect2=31;
			temp->power=NULL;
			temp->weak="FIGHT";
			temp->resis="PSICH";

			break;

		case 37:

			temp->nome="Vulpix";
			temp->hp=50;
			temp->tipo="FIRE";
			temp->evolucao[0]=0;
			temp->evolucao[1]=NULL;
			temp->cost=1;
			temp->atk1=2;
			temp->atk2=NULL;
			temp->dmg1=10;
			temp->dmg2=NULL;
			temp->effect1=24;
			temp->effect2=NULL;
			temp->power=NULL;
			temp->weak="WATER";
			temp->resis=NULL;

			break;

		case 38:

			temp->nome="Ninetales";
			temp->hp=80;
			temp->tipo="FIRE";
			temp->evolucao[0]=1;
			temp->evolucao[1]=37;
			temp->cost=1;
			temp->atk1=20;
			temp->atk2=4;
			temp->dmg1=NULL;
			temp->dmg2=80;
			temp->effect1=32;
			temp->effect2=3;
			temp->power=NULL;
			temp->weak="WATER";
			temp->resis=NULL;

			break;

		case 39:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 40:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 41:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 42:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 43:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 44:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 45:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 46:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 47:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 48:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 49:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 50:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 51:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 52:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 53:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 54:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 55:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 56:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 57:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 58:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 59:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 60:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 61:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 62:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 63:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 64:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 65:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 66:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 67:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 68:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 69:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 70:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 71:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 72:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 73:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 74:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 75:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 76:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 77:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 78:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 79:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 80:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 81:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 82:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 83:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 84:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 85:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 86:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 87:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 88:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 89:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 90:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 91:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 92:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 93:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 94:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 95:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 96:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 97:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 98:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 99:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 100:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 101:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 102:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 103:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 104:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 105:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 106:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 107:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 108:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 109:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 110:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 111:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 112:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 113:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 114:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 115:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 116:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 117:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 118:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 119:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 120:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 121:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 122:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 123:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 124:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 125:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 126:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 127:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 128:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 129:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 130:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 131:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 132:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 133:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 134:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 135:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 136:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 137:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

		case 138:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 139:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 140:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 141:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 142:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 143:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 144:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 145:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 146:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 147:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 148:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 149:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 150:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;

		case 151:

			temp->nome=""
			temp->hp=
			temp->tipo=""
			temp->cost=
			temp->atk1=
			temp->atk2=
			temp->dmg1=
			temp->dmg2=
			temp->effect1=
			temp->effect2=
			temp->weak=""
			temp->resis=""

			break;


	}

	temp=temp->prox;
}
