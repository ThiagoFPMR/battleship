O codigo em questão trata-se de um gerador de mapas do jogo battleship, sendo capaz de criar mapas de 7 colunas por 7 linhas a 16 colunas por 16 linhas.

Os mapas são emitidos em dois arquivo localizados na pasta output, sendo esses: armada.txt e matrix.txt (fazendo uso de duas formatações diferentes).

O programa requer um argumento obrigatório e recebe mais 2 opcionais, deve-se informar o número de mapas a serem gerados e pode-se informar também o numero de linhas
e colunas desejado.

Argumentos: [<opcionais>] número de mapas

Opicionais: --Rows       número de linhas
	    --Collums    número de colunas

Exemplo: --Rows 12 --Collums 11 8 (São gerados 8 mapas de 11 colunas e 12 linhas)
