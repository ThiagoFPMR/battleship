#include <iostream>
#include <fstream>

#include "../include/functions.h"

int main(int argc, char * argv[]) {
    /*Definimos a quantidade de matrizes, linhas e colunas abaixo e atribuimos
     valores a elas a partir da função receiveInput(), que processa a entrada.*/
    int quantity{STD_NPUZ}, rows{STD_ROW}, collums{STD_COL};
    receiveInput(argc, argv, &quantity, &rows, &collums);
    
    // Alocando dinâmicamente o vetor de matrizes
    int * boardList;
    boardList = (int*) malloc(sizeof(int**) * quantity);

    for (int i = 0; i < quantity; i++) {
        
    }

    return 0;
}

