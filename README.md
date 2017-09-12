# Pokemon
Codigo fonte: pokemon.c

Ordenacao de cards de energia: energy list

Efeitos gerais de ataques: pokemon effects

Habilidades gerais de pokemons: pokemon powers

Explicacao geral de cards de treinador: trainer effects

Arquivo (.txt) com lista de cards pokemons: pokemons.txt

Arquivo (.txt) com lista de cards de energia: energy.txt

Arquivo (.txt) com lista de cards de treinador: trainer.txt

---Variáveis

num: numero da carta

hp: Pontos de vida do pokemon

cost: quantidade de cards de energia necessarios para recuar
	1-1 energia normal
	2-2 energia normal
	3-3 energia normal

atk1: quantidade de cards de energia necessarios para utilizar o primeiro ataque
	1-1 energia do tipo do pokemon
	2-2 energias do tipo do pokemon
	3-3 energias do tipo do pokemon
	4-4 energias do tipo do pokemon
	10-1 energia do tipo normal
	20-2 energias do tipo normal
	30-3 energias do tipo normal
	40-4 energias do tipo normal
	11-1 energia do tipo do pokemon + 1 energia do tipo normal
	22-2 energias do tipo do pokemon + 2 energias do tipo normal
	21-2 energias do tipo do pokemon + 1 energia do tipo normal
	31-3 energias do tipo do pokemon + 1 energia do tipo normal
	12-1 energia do tipo do pokemon + 2 energias do tipo normal
	13-1 energia do tipo do pokemon + 3 energias do tipo normal


atk2: quantidade de cards de energia necessarios para utilizar o segundo ataque

dmg1: dano causado pelo primeiro ataque

dmg2: dano causado pelo segundo ataque

effect1: efeito causado pelo primeiro ataque

effect2: efeito causado pelo segundo ataque

evolucao[]: o primeiro valor indica o nivel de evolucao do pokemon, o segundo indica o pokemon antecessor
	0-Basico
	1-Intermediario
	2-Superior

nome: Nome do pokemon

tipo: Tipo do pokemon

weak: Tipo da fraqueza do pokemon
	(TIPO)-2x dano recebido
	(TIPOxnum)-numx dano recebido

resis: Tipo da resistencia do pokemon
	(TIPO)-30 a menos do dano recebido
	(TIPOxnum)-1/numx dano recebido
