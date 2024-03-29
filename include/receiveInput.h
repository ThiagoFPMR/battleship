#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MIN_ROW 9
#define MIN_COL 9
#define MAX_ROW 16
#define MAX_COL 16

#define MIN_NPUZ 1
#define MAX_NPUZ 100

#define STD_NPUZ 1
#define STD_ROW 10
#define STD_COL 10

#include "Board.h"

#include <iostream>
#include <string>
#include <vector>

void errorMsg(std::string error = ""); // Emite a mensagem de erro a partir do argumento dado ao programa
std::string strToLower(std::string str); // Transforma maiusculo em minusculo (usando toLower)
void receiveInput(int argc, char *argv[], int *quantity, int *rows, int *collums); // Recebe a entrada e define quantity, rows e collums

#endif