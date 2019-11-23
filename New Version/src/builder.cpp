#include "../include/builder.h"

using namespace std;

Board boardBuilder (int rows, int collums) {
    vector <unsigned short int> boats = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    Board map = Board (rows, collums);
    std::ostringstream OSS;


    //top da armada
    OSS << "Linhas: " << rows 
        << "Colunas: " << collums 
        << "\n\n";

    map.fleet+= OSS.str();

    //Inicializa a matriz
    setup(&map);

    for (int i = boats.back(); i >= 0; i++) {
        unsigned short int* boat = &boats[i];
        setBoat(&map, boat);
        boats.pop_back();
    }
    /*Lembrar para quando for implementar o resto:
        vector::back
        vector::pop_back
    */

   return map;

}

void setup (Board * map) {
    for (int m = 0; m < map->rows(); m++){
        map->matrix.push_back({});
        for (int n = 0; n < map->collums(); n++){
            map->matrix[m].push_back('.');
            cout << m << " " << n << " | ";
        }
        cout << endl;
    }
}

void setBoat (Board * map, unsigned short int* boatSize) {
    random_device r_col, r_row, r_direction;
    /* Começa definindo 3 números aleatorios acima,
     os quais usados como base para obter a posição
     e orienteação do barco definidas abaixo */
    int row = r_row() % map->rows();
    int collum = r_col() % map->collums();
    int direction = r_direction() % 2;
    // 0 -> Horizontal | 1 -> Vertical

    //seg fault next line
    if (!(canPlaceBoat(map, row, collum, direction, boatSize))) {
        setBoat(map, boatSize);
    }
    else {
        // Adicionando o barco à armada
        std::ostringstream OSS;

        OSS << *boatSize << " "
            << row       << " " 
            << collum    << " " 
            << direction << "\n";
        map->fleet+= OSS.str();

        /* Adicionando o barco à matriz */

        if (direction == 0) { // Se for horizontal
            // Posiciona o barco
            for (int n = collum; n < collum + *boatSize; n++)
                map->matrix[row][n] = '◼︎';
            // Ocupa posições acima do barco
            if (row > 0)
                for (int n = collum; n < collum + *boatSize; n++)
                    map->matrix[row - 1][n] = '*';
            // Ocupa posições abaixo do barco
            if (row < map->rows() - 1)
                for (int n = collum; n < collum + *boatSize; n++)
                    map->matrix[row + 1][n] = '*';
            // Ocupa posições à direita e à esquerda (e diagonais)
            if (collum > 0) {
                map->matrix[row][collum - 1] = '*';
                if (row > 0)
                    map->matrix[row - 1][collum - 1] = '*';
                if (row < map->rows() - 1)
                    map->matrix[row + 1][collum - 1] = '*';
            }
            if (collum < map->collums() - *boatSize) {
                map->matrix[row][collum + *boatSize] = '*';
                if (row > 0)
                    map->matrix[row - 1][collum + *boatSize] = '*';
                if (row < map->rows() - 1)
                    map->matrix[row + 1][collum + *boatSize] = '*';
            }
        }
        if (direction == 1) { // Se for vertical
            // Posiciona o barco
            for (int m = row; m < row + *boatSize; m++)
                map->matrix[m][collum] = '◼︎';
            // Ocupa poisções à esqueda do barco
            if (collum > 0)
                for (int m = row; m < row + *boatSize; m++)
                    map->matrix[m][collum - 1] = '*';
            // Ocupa posições à direita do barco
            if (collum < map->collums() - 1)
                for (int m = row; m < row + *boatSize; m++)
                    map->matrix[m][collum + 1] = '*';
            // Ocupa posições abaixo e acima (e diagonais)
            if (row > 0) { 
                map->matrix[row - 1][collum] = '*';
                if (collum > 0)
                    map->matrix[row - 1][collum - 1] = '*';
                if (collum < map->collums() - 1)
                    map->matrix[row - 1][collum + 1];
            }
            if (row < map->rows() - *boatSize)
                map->matrix[row + *boatSize][collum] = '*';
                if (collum > 0)
                    map->matrix[row + *boatSize][collum - 1] = '*';
                if (collum < map->collums() - 1)
                    map->matrix[row + *boatSize][collum + 1];
        }
    }
}

bool canPlaceBoat (Board * map, int row, int collum, int direction, unsigned short int *boatSize) {
    if (direction == 0) { // Se for horizontal
        if (!(row < map->rows() && row >= 0))
            return false;
        if (!(collum < map->collums() - *boatSize && collum >= 0))
            return false;
        for (int n = collum; n < collum + *boatSize; n++)
            if (map->matrix[row][n] != '.')
                return false;
    }
    if (direction == 1) { // Se for vertical
        if (!(row < map->rows() - *boatSize && row >= 0))
            return false;
        if (!(collum < map->collums() && collum >= 0))
            return false;

        cout << " '\\'--------------------------------------------------'/' " << endl;
        cout << "bSize: " << *boatSize << endl;

        for (int m = row; m < (row + *boatSize)-1; m++){
            cout << "its in once" << endl;
        //problem next line!
            if (map->matrix[m][collum] != '.')
                return false;
        }
    }
    return true;
}