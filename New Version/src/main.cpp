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

    fleetFile   << "mapas: "    << quantity << " "
                << "Linhas: "   << rows     << " "
                << "Colunas: "  << collums 
                << "\n\n\n";

    // Alocando dinâmicamente o vetor de matrizes e printando armada
    for(int i = 1; i <= quantity; i++){
        boardList.push_back(boardBuilder(rows, collums));

        // armazenar board
        for(int m = 0; m < boardList[i-1].matrix.size(); m++){
            for(int n = 0; n < boardList[i-1].matrix[m].size(); n++)
                matrixFile << boardList[i-1].matrix[m][n];  //not done
            matrixFile << "\n";
        }
        matrixFile << "\n\n\n";
    }
    fleetFile.close();
    matrixFile.close();

    return 0;
}