#include <iostream>

class Map{
    public:
    Map(){
      /* Plano de Ataque:
         1. Decidir o tipo de barco a ser posicionado
         2. Decidir se é horiozontal ou vertical
         3. Limitar o numero de posiçôes possiveis baseado nas duas decisões
            e nos posicionamentos de barcos anteriories ao atual
         4. Posicionar o barco selecionado
         5. Repetir para os 10 barcos
      */
        // int ships[4] = {1, 2, 3, 4};
       Board[Rows][Collums] = {{0}};
       int random;

       // Posicionar o Battleship

       // Definir Direção
       int directions[2] = {'H', 'V'};
       int direction = directions[rand() % 2];

       // Escolher as cordenadas m (linha) e n (coluna)
       m = rand() % (Rows - 4);
       n = rand() % (Collums - 4);

       //Preenchendo o espaço ocupado pelo vetor
       if (m > 0 && m < Rows - 1  && n > 0 && n < Collums -1){
         for (int i = m - 1; i < m + 4; i++){
           for (int e = n -1; i < n + 2; e++){
             Board[i][e] = 1;
           }
         }
       }





    }
};
