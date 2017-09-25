void teste(CARD *temp);
void substituir(MESA *mesa, int x);
void imprimirMesa(MESA *mesa, int k);

void atk(MESA *mesa1, MESA *mesa2){

	int i=0, temp, dano;

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

		dano=mesa2->ativo->dmg1;

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

	int i=0;
	CARD *aux = NULL;

	imprimirMesa(mesa, 1);

	printf("\nQual Pokemon do Banco voce deseja tornar ativo?\n");
	scanf("%d", &i);

	if(x==0){
		CARD *aux = (CARD *) malloc(sizeof(CARD));
		aux=mesa->ativo;
	}

	if(x==1)
		mesa->cont--;

	mesa->ativo=mesa->banco[i-1];

	switch(i){

		case 4:

			if(x==1)
				mesa->banco[3]=NULL;
			else
				mesa->banco[3]=aux;
			return;
			break;

		case 3:

			if(x==1){
				if(mesa->banco[3]!=NULL)
					mesa->banco[2]=mesa->banco[3];
				else
					mesa->banco[2]=NULL;

				mesa->banco[3]=NULL;
			}
			else
				mesa->banco[2]=aux;

			return;
			break;

		case 2:

			if(x==1){
				if(mesa->banco[2]!=NULL)
					mesa->banco[1]=mesa->banco[2];
				else
					mesa->banco[1]=NULL;

				if(mesa->banco[3]!=NULL)
					mesa->banco[2]=mesa->banco[3];
				else
					mesa->banco[2]=NULL;

				mesa->banco[3]=NULL;
			}
			else
				mesa->banco[1]=aux;
			return;
			break;

		case 1:

			if(x==1){
				if(mesa->banco[1]!=NULL)
					mesa->banco[0]=mesa->banco[1];
				else
					mesa->banco[0]=NULL;

				if(mesa->banco[2]!=NULL)
					mesa->banco[1]=mesa->banco[2];
				else
					mesa->banco[1]=NULL;

				if(mesa->banco[3]!=NULL)
					mesa->banco[2]=mesa->banco[3];
				else
					mesa->banco[2]=NULL;

				mesa->banco[3]=NULL;
			}
			else
				mesa->banco[0]=aux;
			return;
			break;
	}
}
