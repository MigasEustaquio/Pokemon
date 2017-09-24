char auxstr[10];

void ler(CARD *temp, int i){

	temp->energy=0;

	int j;
	char x[100], y[3];

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

	fscanf(arquivo, " %[^;]s", y);
	temp->num=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->hp=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->cost=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->atk1=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->atk2=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->dmg1=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->dmg2=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->effect1=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->effect2=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->nivel=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->evolucao=atoi(y);
	fseek(arquivo, 1, 1);

	fscanf(arquivo, " %[^;]s", y);
	temp->power=atoi(y);
	fseek(arquivo, 1, 1);

	fclose(arquivo);
}

void lere(int i){

	int j=1;
	char x[10];

	FILE *arquivo;
	arquivo=fopen("energy.txt", "r");

	fseek(arquivo, 0, 0);
	
	for(j=1;j<i;j++){
		
		fscanf(arquivo, "%[^\n]s", x);
		fscanf(arquivo, "%[^.]s", x);
		fseek(arquivo, 1, 1);
	}
		
	fscanf(arquivo, "%[^;]s", auxstr);
//	tempe->num=i;

	fclose(arquivo);
}

void lert(TRAINER *tempt, int i){

	int j=1;
	char x[20];

	FILE *arquivo;
	arquivo=fopen("trainer.txt", "r");

	fseek(arquivo, 0, 0);
	
	for(j=1;j<i;j++){
		
		fscanf(arquivo, "%[^\n]s", x);
		fscanf(arquivo, "%[^.]s", x);
		fseek(arquivo, 1, 1);
	}
		
	fscanf(arquivo, "%[^;]s", tempt->nome);
	tempt->num=i;

	fclose(arquivo);
}
