
#include "../include/builder.h"

using namespace std;

void boardBuilder (Board map, int rows, int collums) {
    vector <int> boats = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    Board map(rows, collums);

    //Inicializa a matriz
    setup(map);

    for (int i = boats.back(); i >= 0; i++) { 
        setBoat(map, boats[i]);
        boats.pop_back();
    }
    /*Lembrar para quando for implementar o resto:
        vector::back
        vector::pop_back
    */

}

void setup (Board map) {
    for (int m = 0; m < map.rows(); m++)
        for (int n = 0; n < map.collums(); n++)
            map.matrix[m][n] = ".";
}

void setBoat (Board map, int boatSize) {
    random_device r_col, r_row, r_direction;
    /* Começa definindo 3 números aleatorios acima,
     os quais usados como base para obter a posição
     e orienteação do barco definidas abaixo */
    int row = r_row() % map.rows();
    int collum = r_col() % map.collums();
    int direction = r_direction() % 2;
    // 0 -> Horizontal | 1 -> Vertical

    if (!(canPlaceBoat(map, row, collum, direction, boatSize))) {
        setBoat(map, boatSize);
    }
    else {
        // Adicionando o barco à armada
        // Adicionando o barco à matriz
    }
}

bool canPlaceBoat (Board map, int row, int collum, int direction, int boatSize) {
    if (direction == 0) { // Se for horizontal
        if (!(row < map.rows() && row >= 0))
            return false;
        if (!(collum < map.collums() - boatSize && collum >= 0))
            return false;
        for (int n = collum; n < collum + boatSize; n++)
            if (map.matrix[row][n] != ".")
                return false;
    }
    if (direction == 1) { // Se for vertical
        if (!(row < map.rows() - boatSize && row >= 0))
            return false;
        if (!(collum < map.collums() && collum >= 0))
            return false;
        for (int m = row; m < row + boatSize; m++)
            if (map.matrix[m][collum] != ".")
                return false;
    }
    return true;
}