#ifndef BUILDER_H
#define BUILDER_H

#include "Board.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

void boardBuilder(Board map, int rows, int collums);
void setup (Board map); // Inicializa o mapa, preenchendo todas as posições
bool canPlaceBoat(Board map, int row, int collum, int direction, int boatSize); // Checa se é possivel colocar um barco na posição
void setBoat(Board map, int boatSize); // Coloca o barco na posição

#endif