#include "../include/Board.h"

Board::Board(int rows, int collums) {
    linhas = rows;
    colunas = collums;
}

int Board::collums() {
    return colunas;
}

int Board::rows() {
    return linhas;
}