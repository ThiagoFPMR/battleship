#include <iostream>
#include <vector>
#include "./models/Map.cpp"

// Objetivos:
// 1. Fazer o criador de navios, que gera o documento no formato da armada.png aleatoriamente a partir do valor de rows e collums e fornece as posição para 2
// 2. Fazer o gerador de matrizes com base nas posiçẽos geradas pelo 1 e no tamanho especificado
// 3. Fazer a função ler quantity rows e collums a partir da chamada pelo terminal (olhar slack)

using namespace std;
int main(/*int argc, char *argv[] */){
  int quantity, rows, collums;
  vector <Map*> matBool; 

  //arguemntos na ordem
  quantity = 1;//atoi(argv[0]);
  //linhas e colunas tem q ser -1 do input real
  rows = 7;//atoi(argv[1]);
  collums = 7;//atoi(argv[2]);

  cout << "compilou essa desgraça!!" << endl;
  cout << quantity << endl;
  for(int k = 0; k < quantity; k++){
    matBool.push_back(new Map(rows, collums));
    cout << "\n\n";
    
    for(int w = 0; w < matBool[k]->board.size(); w++){
      for(int j = 1; j < matBool[k]->board[w].size(); j++)
        cout << matBool[k]->board[w][j];
      cout << endl;
    }
    //matBool[k]->print_debug();
  }

  //fazer o front
  return 0;
}

// OBS: Se o tamanho fornecido resultar em uma matriz cmenor que 6x7 sinalizar que o input foi incorreto