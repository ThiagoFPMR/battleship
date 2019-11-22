#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>

class Board {
private:
    int linhas, colunas;
    // Linhas e colunas do tabuleiro
public:
    Board(int rows, int collums);
    // Construtor da classe
    int rows();
    // Retorna rows
    int collums();
    // Retorna collums
    std::string fleet;
    // Armada a ser impressa
    std::vector <std::vector <char> > matrix;
    // Matriz a ser impressa
};

#endif