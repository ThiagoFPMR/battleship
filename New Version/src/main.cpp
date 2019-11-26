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
    
    // salvar head dos arquivos
    fleetFile.open("../data/fleet.bp");
    matrixFile.open("../data/matrix.bp");

    fleetFile   << quantity << "\n"
                << "\n\n\n";

    matrixFile  << quantity << "\n";


    // Alocando dinâmicamente o vetor de matrizes e printando armada
    for(int i = 1; i <= quantity; i++){
        //incializa matriz
        boardList.push_back(boardBuilder(rows, collums));

        // armazenar board
        fleetFile << boardList[i-1].fleet << "\n";

        //salvar head por puzle
        matrixFile  << rows     << " "
                    << collums
                    << "\n";
        fleetFile   << rows     << " "
                    << collums << "\n";

        if(collums <= 9){
            matrixFile << "   ";
            for(int i = 1; i <= collums; i++)
                matrixFile << i << " ";
        }
        else{
            matrixFile << "                      ";
            for(int i = 10; i <= collums; i++)
                matrixFile << i/10 << " "; //primeiro digito

            matrixFile << "\n    ";
            for(int i = 1; i <= collums; i++)
                if( i < 10 )
                    matrixFile << i << " "; //numero completo
                else 
                    matrixFile << (i % 10) << " "; //segundo digito
        }
        matrixFile << "\n";

            //salvar corpo
        for(int m = 0; m < boardList[i-1].matrix.size(); m++){
            if(rows > 9)
                if (m < 9)
                    matrixFile  << " ";
            matrixFile << m+1 << "[ ";
            for(int n = 0; n < boardList[i-1].matrix[m].size(); n++)
                if (boardList[i-1].matrix[m][n] != "* ")
                    matrixFile << boardList[i-1].matrix[m][n];
                else
                    matrixFile << ". ";
            
            matrixFile << "]\n";
        }
        matrixFile << "\n\n";
    }
    fleetFile.close();
    matrixFile.close();

    return 0;
}