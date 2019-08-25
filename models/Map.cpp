using namespace std;
// usar .board (ou .map) e .armada
class Map{
public:

  vector <vector<int>> board;
  Map(int Rows, int Collums){
  /* Plano de Ataque:
      1. Decidir o tipo de barco a ser posicionado
      2. Decidir se é horiozontal ou vertical
      3. Limitar o numero de posições possiveis baseado nas duas decisões
        e nos posicionamentos de barcos anteriories ao atual
      4. Posicionar o barco selecionado
      5. Repetir para os 10 barcos
  */
    //valor de cada ship[x] será o tamanho da embarcação x
    vector <int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
    vector <int> line;
    
    //inicializa "board"
    for(int k = 0; k < Collums; k++)
      line.push_back(0);
    for(int k = 0; k < Rows; k++)
      board.push_back(line);
    
    //guarda posições ocupadas
    vector <int> r_close;
    vector <int> c_close;
    
    for(int k = 0; k <= ships.size(); k++){
      int r = rand() % (Rows - ships[k]);
      int c = rand() % (Collums - ships[k]);
      bool rotation = rand() % 2;

      //add position de ships[] e água pra evitar colisão
      //add position so dos ships e exporta pra algum lugar pra criar
          //  armada e evitar mapas repetidos 
      if(rotation == 0)
        for(int s = r; s <= ships[k]; s++){
          board[s][c] = 1;
          r_close.push_back(s);
          c_close.push_back(c);
        }
      if(rotation == 1)
        for(int s = c; s <= ships[k]; s++){
          board[r][s] = 1;
          r_close.push_back(r);
          c_close.push_back(s);
        }
    }
    
    // Posicionar o Battleship


    // Definir Direção
    //int directions[2] = {'H', 'V'};
    //int direction = directions[rand() % 2];

    // Escolher as cordenadas m (linha) e n (coluna)
    //int m = rand() % (Rows - 4);
    //int n = rand() % (Collums - 4);

    //Preenchendo o espaço ocupado pelo vetor
    /*if (m > 0 && m < Rows - 1  && n > 0 && n < Collums -1){
      for (int i = m - 1; i < m + 4; i++){
        for (int e = n -1; i < n + 2; e++){
          board[i][e] = 1;
        }
      }
    } */
  }
};
