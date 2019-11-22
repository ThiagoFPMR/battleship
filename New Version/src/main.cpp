#include <iostream>
#include <fstream>
#include <vector>

#include "../include/Board.h"
#include "../include/receiveInput.h"
#include "../include/builder.h"

using namespace std;

int main(int argc, char * argv[]) {
    /*Definimos a quantidade de matrizes, linhas e colunas abaixo e atribuimos
     valores a elas a partir da função receiveInput(), que processa a entrada.*/
    int quantity{STD_NPUZ}, rows{STD_ROW}, collums{STD_COL};
    receiveInput(argc, argv, &quantity, &rows, &collums);
    
    // Alocando dinâmicamente o vetor de matrizes
    vector <Board> boardList;

    return 0;
}

