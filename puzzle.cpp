#include <iostream>
#include <vector>
#include "./models/Map.cpp"

// Objetivos:
// 1. Fazer o criador de navios, que gera o documento no formato da armada.png aleatoriamente a partir do valor de rows e collums e fornece as posição para 2
// 2. Fazer o gerador de matrizes com base nas posiçẽos geradas pelo 1 e no tamanho especificado
// 3. Fazer a função ler quantity rows e collums a partir da chamada pelo terminal (olhar slack)

using namespace std;
int main(int argc, char *argv[ ]){
  int Quantity, Rows, Collums;
  vector <Map*> armada;
  
  // O primeiro argumento deve ser a quantidade
  Quantity = atoi(argv[1]);
  srand(time(NULL));
  for(int k = 0; k < Quantity; k++){
    armada.push_back(new Map());
  }
    cout << "Q:" << Quantity << endl;

  //fazer o front
  return 0;
}

/* OBS: Se o tamanho fornecido resultar em uma matriz com area menor que 20,
sinalizar que o input foi incorreto (os 10 barcos ocupam 20 espaços, sem
contar a agua)*/
