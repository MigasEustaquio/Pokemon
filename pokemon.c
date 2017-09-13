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

	struct trainer *proxt;

}TRAINER;

typedef struct mesa{

	CARD ativa=NULL, banco1=NULL, banco2=NULL, banco3=NULL, banco4=NULL;

}MESA;

void del();
void iniciar();
void ler(CARD *temp, int i);
void teste(CARD *temp);

CARD *lista=NULL, *temp=NULL;
ENERGY *listae=NULL, *tempe=NULL;
TRAINER *listat=NULL, *tempt=NULL;

void main(){

	iniciar();

	
}

void iniciar(){

	int i=0;

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

	printf("%s\n%s\nHP:%d\n", temp->nome, temp->tipo, temp->hp);
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
	}

	temp=temp->prox;
}
