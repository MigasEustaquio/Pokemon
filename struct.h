typedef struct card{

	int num, hp, cost, energy;
	int atk1, atk2, dmg1, dmg2;
	int effect1, effect2;
	int nivel, evolucao, power, status;
	char nome[20], tipo[10], weak[10], resis[10];

}CARD;

typedef struct energy{

	int num;
	char nome[20];

}ENERGY;

typedef struct trainer{

	int num;
	char nome[20];

}TRAINER;

typedef struct mesa{

	CARD *ativo, *banco[4];
	int cont;

}MESA;
