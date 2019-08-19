#include <iostream>

class Map{
    public:
    Map(){
      /* vector<int> Board[Rows];
      for (int i = 0; i < Rows; i++){
        int Board[i][Collums] = {};
      }*/

        /*
        0 -> Battleship
        1 -> Destroyer
        2 -> Cruiser
        3 -> Submarine
        */
        int ships[4] = {1, 2, 3, 4};
        int random = rand() % 4;
        ships[random] -= 1;
        for (int i = 0; i < 4; i++){
          std::cout << ships[i] << std::endl;
        }


    }
};
