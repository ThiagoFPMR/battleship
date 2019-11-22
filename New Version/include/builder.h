#ifndef BUILDER_H
#define BUILDER_H

#include "Board.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

Board boardBuilder( int rows, int collums);
void setup (Board map); // Inicializa o mapa, preenchendo todas as posições
bool canPlaceBoat(Board map, int row, int collum, int direction, unsigned short int * boatSize); // Checa se é possivel colocar um barco na posição
void setBoat(Board map, unsigned short int * boatSize); // Coloca o barco na posição

#endif