#include "../include/builder.h"

using namespace std;

Board boardBuilder (int rows, int collums) {
    vector <unsigned short int> boats = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    Board map = Board (rows, collums);

    //Inicializa a matriz
    setup(&map);

    for (int i = (boats.size()-1); i >= 0; --i) {
        unsigned short int* boat = &boats[i];

        setBoat(&map, boat);
    }
    /*Lembrar para quando for implementar o resto:
        vector::back
        vector::pop_back
    */

   return map;

}

void setup (Board * map) {
    for (int m = 0; m < map->rows(); m++){
        vector <string> inicializer;
        for (int n = 0; n < map->collums(); n++)
            inicializer.push_back(". ");
        
        map->matrix.push_back(inicializer);
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
        ostringstream OSS;

        switch (*boatSize)
        {
        case 4:
            OSS << 'B'; 
            break;
        case 3:
            OSS << 'D';
            break;
        case 2:
            OSS << 'C';
            break;
        default:
            OSS << 'S'; // sobrou ser = 0
            break;
        }
        OSS << " "
            << row       << " " 
            << collum    << " ";
            if (*boatSize > 1){
                if(direction == 0)
                    OSS << 'H' << "\n";
                else if(direction == 1)
                    OSS << 'V' << "\n";
            }
            else
                OSS << "\n";
        map->fleet+= OSS.str();

        /* Adicionando o barco à matriz */

        if (direction == 0) { // Se for horizontal
            // Posiciona o barco
            if(*boatSize == 1)
                map->matrix[row][collum] = "● ";
            else
                for (int n = collum; n < collum + *boatSize; n++)
                    if(n == collum)
                        map->matrix[row][n] = "◀︎ ";
                    else if(n == collum + *boatSize - 1)
                        map->matrix[row][n] = "▶︎ ";
                    else
                        map->matrix[row][n] = "◼︎ ";
            // Ocupa posições acima do barco
            if (row > 0)
                for (int n = collum; n < collum + *boatSize; n++)
                    map->matrix[row - 1][n] = "* ";
            // Ocupa posições abaixo do barco
            if (row < map->rows() - 1)
                for (int n = collum; n < collum + *boatSize; n++)
                    map->matrix[row + 1][n] = "* ";
            // Ocupa posições à direita e à esquerda (e diagonais)
            if (collum > 0) {
                map->matrix[row][collum - 1] = "* ";
                if (row > 0)
                    map->matrix[row - 1][collum - 1] = "* ";
                if (row < map->rows() - 1)
                    map->matrix[row + 1][collum - 1] = "* ";
            }
            if (collum < map->collums() - *boatSize) {
                map->matrix[row][collum + *boatSize] = "* ";
                if (row > 0)
                    map->matrix[row - 1][collum + *boatSize] = "* ";
                if (row < map->rows() - 1)
                    map->matrix[row + 1][collum + *boatSize] = "* ";
            }
        }
        if (direction == 1) { // Se for vertical
            // Posiciona o barco
            if(*boatSize == 1)
                map->matrix[row][collum] = "● ";
            else
                for (int m = row; m < row + *boatSize; m++)
                    if(m == row)
                        map->matrix[m][collum] = "▲ ";
                    else if(m == row + *boatSize - 1)
                        map->matrix[m][collum] = "▼ ";
                    else
                        map->matrix[m][collum] = "◼︎ ";
            // Ocupa poisções à esqueda do barco
            if (collum > 0)
                for (int m = row; m < row + *boatSize; m++)
                    map->matrix[m][collum - 1] = "* ";
            // Ocupa posições à direita do barco
            if (collum < map->collums() - 1)
                for (int m = row; m < row + *boatSize; m++)
                    map->matrix[m][collum + 1] = "* ";
            // Ocupa posições abaixo e acima (e diagonais)
            if (row > 0) {
                map->matrix[row - 1][collum] = "* ";
                if (collum > 0)
                    map->matrix[row - 1][collum - 1] = "* ";
                if (collum < map->collums() - 1)
                    map->matrix[row - 1][collum + 1] = "* ";
            }
            if (row < map->rows() - *boatSize)
                map->matrix[row + *boatSize][collum] = "* ";
                if (collum > 0)
                    map->matrix[row + *boatSize][collum - 1] = "* ";
                if (collum < map->collums() - 1)
                    map->matrix[row + *boatSize][collum + 1] = "* ";
        }
    }
}

bool canPlaceBoat (Board * map, int row, int collum, int direction, unsigned short int *boatSize) {
    if (direction == 0) { // Se for horizontal
        if (!(row < map->rows() && row >= 0))
            return false;
        if (!(collum < map->collums() - *boatSize && collum >= 0))
            return false;

        if (*boatSize == 1) {
            if (map->matrix[row][collum] != ". ")
                return false;
        }
        else
            for (int n = collum; n < (collum + *boatSize); n++)
                if (map->matrix[row][n] != ". ")
                    return false;
    }
    if (direction == 1) { // Se for vertical
        if (!(row < map->rows() - *boatSize && row >= 0))
            return false;
        if (!(collum < map->collums() && collum >= 0))
            return false;

        if (*boatSize == 1) {
            if (map->matrix[row][collum] != ". ")
                return false;
        }
        else  
            for (int m = row; m < (row + *boatSize); m++)
                if (map->matrix[m][collum] != ". ")
                    return false;
            
        
    }
    return true;
}