#include <iostream>
#include <fstream>
#include <vector>

#include "../include/Board.h"
#include "../include/receiveInput.h"
#include "../include/builder.h"

using namespace std;

int main(int argc, char * argv[]) {
    ofstream fleetFile;
    ofstream matrixFile;
    vector <Board> boardList;
    /*Definimos a quantidade de matrizes, linhas e colunas abaixo e atribuimos
     valores a elas a partir da função receiveInput(), que processa a entrada.*/
    int quantity{STD_NPUZ}, 
        rows{STD_ROW},
        collums{STD_COL};
    receiveInput(argc, argv, &quantity, &rows, &collums);
    
    // print head da armada
    fleetFile.open("../data/fleet.txt");
    matrixFile.open("../data/matrix.txt");

    fleetFile << "Linhas: " << rows 
              << "Colunas: " << collums 
              << "\n\n\n";

    // Alocando dinâmicamente o vetor de matrizes e printando armada
    for(int i = 1; i <= quantity; i++){
        boardList.push_back(boardBuilder(rows, collums));
        cout << boardList[i].rows();
        fleetFile << boardList[i].fleet << "\n\n";
        matrixFile << boardList[i].fleet << "\n\n";  //not done
    }
    fleetFile.close();

    return 0;
}