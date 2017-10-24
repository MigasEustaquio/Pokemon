#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "arq.h"
#include "atk.h"

void del();
void preiniciar(MESA *mesa);
int iniciar(MESA *mesa, int tipo, int num);
int iniciare(MESA *mesa, int num);
void iniciart(MESA *mesa, int tipo, int num);
void ler(CARD *temp, int i);
void lere(int i);
void lert(TRAINER *tempt, int i);
void teste(CARD *temp);
void mesa();
void teste2(MESA *mesa);
void imprimirMesa(MESA *mesa, int k);
int evolve(MESA *mesa, CARD *temp);

char auxstr[10];

void main(){

	mesa();
}

void preiniciar(MESA *mesa){

	int tipo, num, x=1, y;

	printf("\n-----------------------------------------------------------------------------------\n\tADICIONAR CARD\n");

	printf("\nQual o tipo de carta deseja criar?\n\t1-Pokemon(disponivel ate '49')\n\t2-Energia(disponivel ate '9')\n\t3-Treinador(disponivel ate '7')\n\t0-Retornar\n");
	scanf("%d", &tipo);

	if(tipo==0){
		printf("\nOPERACAO CANCELADA\n\n");
		return;
	}

	if(tipo==2)
		printf("\n\n\t1-FIGHT\n\t2-FIRE\n\t3-GRASS\n\t4-LIGHT\n\t5-PSICH\n\t6-WATER\n\t7-DARK\n\t8-METAL\n\t9-DOEBLE\n");

	if(mesa->cont!=5){
		printf("\nQual o numero da carta?\n");
		scanf("%d", &num);
	}

	switch(tipo){	

	case 1:
		if(mesa->cont==5){
			printf("\nSua mesa ja possui o maximo de pokemons.\n\nOPERACAO CANCELADA\n\n");
			return;
		}
		x=iniciar(mesa, tipo, num);
		if(x==0){
			printf("\nOPERACAO CANCELADA\n\n");
			return;
		}
		break;

	case 2:

		if(mesa->cont==0){
			printf("A mesa escolhida nao possui nenhum card de pokemon");
			return;
		}
		if(num<1 || num>9){
			printf("\nCards de energia possuem numero de 1 a 9\n\n");
			return;
		}
		y=iniciare(mesa, num);
		if(y==0)
			return;
		
		break;

	case 3:
		iniciart(mesa, tipo, num);
		break;
	}

	printf("\nCARD ADICIONADO COM SUCESSO\n\n\n");
}

int iniciar(MESA *mesa, int tipo, int num){

	int i=0, x, y=0;

	CARD *temp = (CARD *) malloc(sizeof(CARD));
	ler(temp, num);

	teste(temp);

	do{

		printf("Deseja adicionar esse Pokemon? (1-Sim, 2-Nao)\n");
		scanf("%d", &i);

		if(i!=1 && i!=2)
			printf("\nPor favor insira 1 ou 2.\n\n");
	}while(i!=1 && i!=2);

	if(temp->nivel!=0){

		y=1;

		x=evolve(mesa, temp);

		if(x==0)
			return 0;
	}

	if(i==2)
		return 0;

	if(mesa->cont==0){

		if(y!=1){
			mesa->ativo=temp;
			mesa->cont++;
		}
	}
	else{

		if(y!=1){
			mesa->banco[mesa->cont-1]=temp;
			mesa->cont++;
		}
	}
	return 1;
}

int iniciare(MESA *mesa, int num){

	int i=0, j, energy;

	lere(num);

	do{
		printf("\nDeseja adicionar esse card?(1-SIM/2-NAO)\n\n\t%s\n", auxstr);
		scanf("%d", &i);

		if(i!=1 && i!=2)
			printf("\nPor favor insira 1 ou 2.\n\n");

	}while(i!=1 && i!=2);

	if(i==2){

		printf("\nOPERACAO CANCELADA\n\n");
		return 0;
	}

	do{
		imprimirMesa(mesa, 2);

		printf("\nA qual Pokemon o card de energia sera ligado?(0-Ativo, num-Banco)\n");
		scanf("%d", &j);

		if(j<0 && j>(mesa->cont))
			printf("\nPor favor insira um numero equivalente a um pokemon\n");
			
	}while(j<0 || j>(mesa->cont-1));

	if(j==0)
		if(strcmp(mesa->ativo->tipo, auxstr)==0)
			energy=10;
		else
			energy=1;
	else
		if(strcmp(mesa->banco[j-1]->tipo, auxstr)==0)
			energy=10;
		else
			energy=1;

	if(num==9)
		energy++;

	if(j==0)
		mesa->ativo->energy = mesa->ativo->energy + energy;
	else
		mesa->banco[j-1]->energy = mesa->banco[j-1]->energy +energy;
	return 1;
}

void iniciart(MESA *mesa, int tipo, int num){

	TRAINER *tempt = (TRAINER *) malloc(sizeof(TRAINER));
	lert(tempt, num);
}

void mesa(){
	
	int i=0, j=0, k=0, z=0;

	MESA *mesa1 = (MESA *) malloc(sizeof(MESA));
	MESA *mesa2 = (MESA *) malloc(sizeof(MESA));
	
	mesa1->cont=0;
	mesa2->cont=0;

	mesa1->ativo=NULL;
	mesa2->ativo=NULL;

	for(i=0;i<4;i++){
		mesa1->banco[i]=NULL;
		mesa2->banco[i]=NULL;
	}

	while(j==0){

	i=0;

		printf("\n-----------------------------------------------------------------------------------\nO que deseja fazer?\n1-Adicionar card a mesa\n2-Atacar\n3-Substituir\n4-???????????????\n5-???????????????\n6-???????????????\n7-???????????????\n8-???????????????\n9-Mostrar mesa(Apenas cards de pokemon)\n0-Encerrar\n");
		scanf("%d", &i);

		if(i!=0)
			do{	
				printf("\nQual mesa deseja usar?(1 ou 2)\n");
				scanf("%d", &k);

				if(k!=1 && k!=2)
					printf("\nPor favor insira 1 ou 2.\n\n");
			}while(k!=1 && k!=2);

		switch(i){

			case 1:
				if(k==1)
					preiniciar(mesa1);
				else
					preiniciar(mesa2);
				break;
				
			case 2:
				if(k==1)
					atk(mesa1, mesa2);
				else
					atk(mesa2, mesa1);
				break;

			case 3:
				if(k==1)
					substituir(mesa1,0);
				else
					substituir(mesa2,0);
				break;

			case 9:
				if(k==1)
					imprimirMesa(mesa1, 0);
				else
					imprimirMesa(mesa2, 0);
				break;
				
			case 0:
				printf("\nTem certeza que deseja encerrar?(1-SIM/2-NAO)\n\n");
				scanf("%d", &z);
				if(z==1){
					printf("\n\tPrograma Encerrado\n");
					j=1;
				}
				break;

		}
	}
}

int evolve(MESA *mesa, CARD *temp){

	int num, energy=0;

	CARD *nome = (CARD *) malloc(sizeof(CARD));

	ler(nome, temp->evolucao);

	if(mesa->ativo==NULL){
		printf("Nenhum pokemon na mesa.\n\n");
		return 0;
	}

	imprimirMesa(mesa, 2);

	printf("Esse pokemon nao e basico.\nSelecione o pokemon de estagio anterior ao desejado em sua mesa (0 para o pokemon ativo)--(%s)", nome->nome);	scanf("%d", &num);

	if(num==0){
		if(mesa->ativo->num==nome->num){
			energy=mesa->ativo->energy;
			mesa->ativo=temp;
			mesa->ativo->energy=energy;
		}
		else{

			printf("\nO pokemon selecionado nao e o correto. Operacao cancelada.\n\n");
			return 0;
		}
	}
	else{

		if(mesa->banco[num-1]==NULL){
			printf("Essa mesa nao possui um pokemon nessa posicao.\n\n");
			return 0;
		}
		if(mesa->banco[num-1]->num==nome->num){
			energy=mesa->banco[num-1]->energy;
			mesa->banco[num-1]=temp;
			mesa->banco[num-1]->energy=energy;
		}
		else{

			printf("\nO pokemon selecionado nao e o correto. Operacao cancelada.\n\n");
			return 0;
		}
	}

	return 1;
}

void imprimirMesa(MESA *mesa, int k){

	if(k==0)
		printf("\n-----------------------------------------------------------------------------------\n\tIMPRIMIR MESA\n\n");

	if(mesa->ativo==NULL){

		printf("Nenhum Pokemon na mesa\n");
		return;
	}
	else{

		if(k!=1){
			printf("\nPokemon Ativo\n\n");
			teste(mesa->ativo);
		}

		if(mesa->banco[0]==NULL)
			return;
		else{

			printf("\nPokemon no Banco 1\n\n");
			teste(mesa->banco[0]);

			if(mesa->banco[1]==NULL)
				return;
			else{

				printf("\nPokemon no Banco 2\n\n");
				teste(mesa->banco[1]);

				if(mesa->banco[2]==NULL)
					return;
				else{

					printf("\nPokemon no Banco 3\n\n");
					teste(mesa->banco[2]);

					if(mesa->banco[3]==NULL)
						return;
					else{

						printf("\nPokemon no Banco 4\n\n");
						teste(mesa->banco[3]);
					}
				}
			}
		}
	}
	printf("\n\n");
}

void teste(CARD *temp){

	printf("NOME: %s\nTIPO: %s\nENERGY: %d\nWEAK: %s\nRESIS: %s\nNUM: %d\nHP: %d\nCOST: %d\nATK1: %d\nATK2: %d\nDMG1: %d\nDMG2: %d\nEFFECT1: %d\nEFFECT2: %d\nNIVEL: %d\nEVOLUCAO: %d\nPOWER: %d\n\n", temp->nome, temp->tipo, temp->energy, temp->weak, temp->resis, temp->num, temp->hp, temp->cost, temp->atk1, temp->atk2, temp->dmg1, temp->dmg2, temp->effect1, temp->effect2, temp->nivel, temp->evolucao, temp->power);
}

void teste2(MESA *mesa){

	printf("NOME1:%s\nNOME2:%s\nNOME3:%s\n", mesa->ativo->nome, mesa->banco[0]->nome, mesa->banco[1]->nome);
}
