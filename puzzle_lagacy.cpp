
using namespace std;
class Map{
    public:
    Map(int Rows, int Collums){
      /* Plano de Ataque:
         1. Decidir o tipo de barco a ser posicionado
         2. Decidir se é horiozontal ou vertical
         3. Limitar o numero de posiçôes possiveis baseado nas duas decisões
            e nos posicionamentos de barcos anteriories ao atual
         4. Posicionar o barco selecionado
         5. Repetir para os 10 barcos
      */
       vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
       char board[Rows][Collums] = {{0}};

      for(int k = 0; k <= ships.size(); k++){
        int r = 2;//rand() % Rows;
        int c = 2;//rand() % Collums;
        bool rotation = rand() % 2;
        board[r][c] = 1;
        
        //reescrito pensando em falhas de segmentação
        //coloquei if em vez de outros switchs pra ficar claro a diferença
        switch (ships[k])
        {
        case 1:
          board[r][c] = '●';
          break;
        case 2:
          if(rotation == 0){
            board[r][c]   = '▲';
            board[r+1][c] = '▼';
          }else if(rotation == 1){
            board[r][c]   = '▲';
            board[r][c+1] = '▼';
          }
          break;
        case 3:
          if(rotation == 0){
            board[r][c]   = '▲';
            board[r+1][c] = '◼︎';
            board[r+2][c] = '▼';
          }else if(rotation == 1){
            board[r][c]   = '▲';
            board[r][c+1] = '◼︎';
            board[r][c+3] = '▼';
          }
          break;
        case 4:
          if(rotation == 0){
            board[r][c]   = '▲';
            board[r+1][c] = '◼︎';
            board[r+2][c] = '◼︎';
            board[r+3][c] = '▼';
          }else if(rotation == 1){
            board[r][c]   = '▲';
            board[r][c+1] = '◼︎';
            board[r][c+2] = '◼︎';
            board[r][c+3] = '▼';
          }
          break;
        default:
          break;
        }
      }
       // É melhor criar uma função universal e usa-la para todos os barcos

      /*void add_ship(Rows, Collums, lenght){
        // Obs: largura do barco (lenght) será argumento para a função

        // Definir Direção
        int directions[2] = {'H', 'V'};
        int direction = directions[rand() % 2];

        // Escolher as cordenadas m (linha) e n (coluna)
        int m = rand() % (Rows - lenght;
        int n = rand() % (Collums - lenght);

        // Posicionamento
        switch(direction){
          case 'H': 
            int i = m - 1, 
            i_max = n + 1, 
            e = n - 1, 
            e_max = m + lenght; 
            break;
          case 'V': 
            int i = m - 1, 
            i_max = m + lenght, 
            e = n - 1, 
            e_max = n + 1; 
            break;
        }

        if (i < 0){i = m;}

        if (i_max >= Rows){
          switch(direction){
            case 'H': i_max = m; break;
            case 'V': i_max = m + lenght - 1; break;
          }
        }
        if (e < 0){e = n;}

        if (e_max >= Collums){
          switch(direction){
            case 'H': e_max = n + lenght - 1; break;
            case 'V': e_max = n; break;
          }
        }

        for (i; i <= i_max; i++){
          for (e; e <= e_max; e++){
            board[i][e] = 1;
          }
        }
      }

      // Posicionar o Battleship

      add_ship(Rows, Collums, 4); */



    }
};