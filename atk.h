void teste(CARD *temp);
void substituir(MESA *mesa, int x);
void imprimirMesa(MESA *mesa, int k);
int energ(CARD *card, int j);
int energ2(CARD *card);
void troca(CARD *card1, CARD *card2, CARD *temp, int q);
void consertar(CARD *card);

void atk(MESA *mesa1, MESA *mesa2){

	int i=0, temp, dano, flag=1;

	printf("\n-----------------------------------------------------------------------------------\n\tATACAR\n\n");

	if(mesa1->ativo==NULL){

		printf("Nenhum Pokemon na mesa atacante\n");
		return;
	}
	if(mesa2->ativo==NULL){

		printf("Nenhum Pokemon na mesa defensiva\n");
		return;
	}

	teste(mesa1->ativo);
	printf("\nQual ataque deseja utilizar?\n");
	scanf("%d", &i);
	
	temp=mesa2->ativo->hp;

	
	if(i==1){

		flag=energ(mesa1->ativo, 1);

		if(flag==0){
			printf("\nO Pokemon nao possui cards de energia suficiente para realizar este ataque.\n\n");

		atk(mesa1, mesa2);
		return;
		}

		dano=mesa1->ativo->dmg1;

		if(mesa2->ativo->resis==mesa1->ativo->tipo){

			dano=dano-30;
			if(dano<0)
				dano=0;
		}

		if(mesa2->ativo->weak==mesa1->ativo->tipo){

			dano=dano*2;
		}

		mesa2->ativo->hp = mesa2->ativo->hp - dano;
	}

	if(i==2){

		if(mesa1->ativo->atk2==0){
			printf("\nO Pokemon nao possui segundo ataque.\n\n");
			atk(mesa1, mesa2);
			return;
		}

		flag=energ(mesa1->ativo, 2);

		if(flag==0){
			printf("\nO Pokemon nao possui cards de energia suficiente para realizar este ataque.\n\n");

		atk(mesa1, mesa2);
		return;
		}

		dano=mesa2->ativo->dmg2;

		if(mesa1->ativo->resis==mesa2->ativo->tipo){

			dano=dano-30;
			if(dano<0)
				dano=0;
		}

		if(mesa1->ativo->weak==mesa2->ativo->tipo){

			dano=dano*2;
		}

		mesa2->ativo->hp = mesa2->ativo->hp - dano;
	}

	printf("\nDANO CAUSADO: %i\n", temp-mesa2->ativo->hp);

	if(mesa2->ativo->hp<=0){

		printf("O Pokemon foi derrotado!\n\n\n");
		if(i==1)
			substituir(mesa2, 1);
		if(i==2)
			substituir(mesa1, 1);
		return;
	}
}

void substituir(MESA *mesa, int x){

	int i=0, j, m=0;

	imprimirMesa(mesa, 1);

	if(mesa->banco[0]==NULL){
		printf("\nNenhum pokemon no Banco.\n\n");
		return;
	}

	printf("\nQual Pokemon do Banco voce deseja tornar ativo?\n");
	scanf("%d", &i);

//	j=energ2(mesa->ativo);

//	if(j==0){
//		printf("\nO pokemon nao possui a energia necessaria para recuar.\n\n");
//		return;
//	}
	CARD *aux = (CARD *) malloc(sizeof(CARD));
	*aux=*mesa->ativo;

	if(x==1)
		mesa->cont--;

	switch(i){

		case 4:

			if(x==1){
				troca(mesa->banco[3], mesa->ativo, aux, 2);
				mesa->banco[3]=NULL;
			}
			else{
				troca(mesa->banco[3], mesa->ativo, aux, 2);
				consertar(mesa->banco[m]);
			}
			break;
		case 3:

			if(mesa->banco[3]!=NULL){
				troca(mesa->banco[3], mesa->banco[2], aux, 2);
				troca(mesa->banco[3], mesa->ativo, aux, 2);
				consertar(mesa->banco[3]);
				consertar(mesa->banco[2]);
				consertar(mesa->banco[1]);
				consertar(mesa->banco[0]);
				if(x==1)
					mesa->banco[3]=NULL;
			}
			else{
				troca(mesa->banco[2], mesa->ativo, aux, 2);
				consertar(mesa->banco[2]);
				consertar(mesa->banco[1]);
				consertar(mesa->banco[0]);
				if(x==1)
					mesa->banco[2]=NULL;
			}
			break;
		case 2:

			if(mesa->banco[2]!=NULL){

				troca(mesa->banco[2], mesa->banco[1], aux, 2);
				if(mesa->banco[3]!=NULL){
					troca(mesa->banco[3], mesa->banco[2], aux, 2);
					troca(mesa->banco[3], mesa->ativo, aux, 2);
					consertar(mesa->banco[3]);
					consertar(mesa->banco[2]);
					consertar(mesa->banco[1]);
					consertar(mesa->banco[0]);
					if(x==1)
						mesa->banco[3]=NULL;
				}else{
					troca(mesa->banco[2], mesa->ativo, aux, 2);
					consertar(mesa->banco[2]);
					consertar(mesa->banco[1]);
					consertar(mesa->banco[0]);
					if(x==1)
						mesa->banco[2]=NULL;
				}
			}
			else{
				troca(mesa->banco[1], mesa->ativo, aux, 2);
				consertar(mesa->banco[1]);
				consertar(mesa->banco[0]);
				if(x==1)
					mesa->banco[1]=NULL;
			}
			break;
		case 1:

			if(mesa->banco[1]!=NULL){
				troca(mesa->banco[1], mesa->banco[0], aux, 2);
				if(mesa->banco[2]!=NULL){
					troca(mesa->banco[2], mesa->banco[1], aux, 2);
					if(mesa->banco[3]!=NULL){
						troca(mesa->banco[3], mesa->banco[2], aux, 2);
						troca(mesa->banco[3], mesa->ativo, aux, 2);
						consertar(mesa->banco[3]);
						consertar(mesa->banco[2]);
						consertar(mesa->banco[1]);
						consertar(mesa->banco[0]);
						if(x==1)
							mesa->banco[3]=NULL;
					}else{
						troca(mesa->banco[2], mesa->ativo, aux, 2);
						consertar(mesa->banco[2]);
						consertar(mesa->banco[1]);
						consertar(mesa->banco[0]);
						if(x==1)
							mesa->banco[2]=NULL;
					}
				}else{
					troca(mesa->banco[1], mesa->ativo, aux, 2);
					consertar(mesa->banco[1]);
					consertar(mesa->banco[0]);
					if(x==1)
						mesa->banco[1]=NULL;
				}
			}else{
				troca(mesa->banco[0], mesa->ativo, aux, 2);
				consertar(mesa->banco[0]);
				if(x==1)
					mesa->banco[0]=NULL;
			}
			break;
	}
	consertar(mesa->ativo);
}

int energ(CARD *card, int j){

	int atk, atk1, atk2, energy, energy1, energy2;

	if(j==1)
		atk=card->atk1;
	if(j==2)
		atk=card->atk2;

	energy=card->energy;

	energy1=energy/10;
	energy2=energy%10;

	atk1=atk/10;
	atk2=atk%10;

	if(energy1<atk1)
		return 0;
	if(energy2+energy1-atk1<atk2)
		return 0;

	return 1;
}

int energ2(CARD *card){

	int energy, energy1, energy2, temp;

	energy=card->energy;

	energy1=energy/10;
	energy2=energy%10;

	if(energy2+energy1<card->cost)
		return 0;

	temp=card->cost;

	do{
		if(energy2>=card->cost){
			energy2--;
			temp--;
		}else
			if(energy1>=card->cost){
				energy1--;
				temp--;
			}
	}while(temp>0);

	card->energy=(energy1*10+energy2);
	return 1;
}

void troca(CARD *card1, CARD *card2, CARD *temp, int q){

	if(q==2){
		temp->energy=card1->energy;
		temp->num=card1->num;
		temp->hp=card1->hp;
		temp->cost=card1->cost;
		temp->atk1=card1->atk1;
		temp->atk2=card1->atk2;
		temp->dmg1=card1->dmg1;
		temp->dmg2=card1->dmg2;
		temp->effect1=card1->effect1;
		temp->effect2=card1->effect2;
		temp->nivel=card1->nivel;
		temp->evolucao=card1->evolucao;
		temp->power=card1->power;
	}

	card1->energy=card2->energy;
	card1->num=card2->num;
	card1->hp=card2->hp;
	card1->cost=card2->cost;
	card1->atk1=card2->atk1;
	card1->atk2=card2->atk2;
	card1->dmg1=card2->dmg1;
	card1->dmg2=card2->dmg2;
	card1->effect1=card2->effect1;
	card1->effect2=card2->effect2;
	card1->nivel=card2->nivel;
	card1->evolucao=card2->evolucao;
	card1->power=card2->power;

	if(q==2){
		card2->energy=temp->energy;
		card2->num=temp->num;
		card2->hp=temp->hp;
		card2->cost=temp->cost;
		card2->atk1=temp->atk1;
		card2->atk2=temp->atk2;
		card2->dmg1=temp->dmg1;
		card2->dmg2=temp->dmg2;
		card2->effect1=temp->effect1;
		card2->effect2=temp->effect2;
		card2->nivel=temp->nivel;
		card2->evolucao=temp->evolucao;
		card2->power=temp->power;
	}
}

void consertar(CARD *temp){

	int j, i=temp->num;
	char x[100];

	FILE *arquivo;
	arquivo=fopen("pokemons.txt", "r");

	fseek(arquivo, 0, 0);

	for(j=1;j<i;j++){
		
		fscanf(arquivo, "%[^\n]s", x);
		fscanf(arquivo, "%[^.]s", x);
	}

	fseek(arquivo, 1, 1);
	
	fscanf(arquivo, "%[^;]s", temp->nome);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", temp->tipo);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", temp->weak);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", temp->resis);
	fseek(arquivo, 1, 1);

	fclose(arquivo);
}








