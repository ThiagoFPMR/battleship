#include <iostream>

class Map{
    public:
    Map(){
      // Board[Rows][Collums] = {{0}};

      /* Plano de Ataque:
         1. Decidir o tipo de barco a ser posicionado
         2. Decidir se é horiozontal ou vertical
         3. Limitar o numero de posiçôes possiveis baseado nas duas decisões
            e nos posicionamentos de barcos anteriories ao atual
         4. Posicionar o barco selecionado
         5. Repetir para os 10 barcos
      */

        /*
        0 -> Battleship
        1 -> Destroyer
        2 -> Cruiser
        3 -> Submarine
        */

        int ships[4] = {1, 2, 3, 4};
        char ships_char[4] = {'B', 'D', 'C', 'S'};
        int random = rand() % 4;
        ships[random] -= 1;
        for (int i = 0; i < 4; i++){
          std::cout << ships[i] << " " << ships_char[i] << std::endl;
        }


    }
};
