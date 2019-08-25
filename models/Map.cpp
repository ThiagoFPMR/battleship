using namespace std;
// usar .board (ou .map) e .armada
class Map{
public:

  vector <vector<int>> board;
  vector <int> r_close;
  vector <int> c_close;
  Map(int rows, int collums){
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
    vector <int> line;  //inicicializador de "board"
    
    //inicializa "board"
    for(int k = 0; k <= collums; k++)
      line.push_back(0);
    for(int k = 0; k <= rows; k++)
      board.push_back(line);
    
    //guarda posições ocupadas
    
    // Posicionar o Battleship
    srand(time(NULL));
    for(int k = 0; k <= ships.size(); k++){
      int r = rand() % (rows - 1 - ships[k]);
      int c = rand() % (collums - 1 - ships[k]);
      bool rotation = rand() % 2;
      
      //add position de ships[] e água pra evitar colisão
      //add position so dos ships e exporta pra algum lugar pra criar
          //  armada e evitar mapas repetidos 
      if(rotation == 0)
        for(int s = r; s <= ships[k]; s++){
          //board[c][s] = 1;
          r_close.push_back(s);
          c_close.push_back(c);
          cout << "s of rotation 0 = " << s << endl;
          cout << "c of rotation 0 = " << c << endl;
        }
      else if(rotation == 1)
        for(int s = c; s <= ships[k]; s++){
          //board[s][r] = 1;
          r_close.push_back(r);
          c_close.push_back(s);
          cout << "r of rotation 1 = " << r << endl;
          cout << "s of rotation 1 = " << s << endl;
        }
      cout << "k = " << k << endl << endl;
    }
    


    // Definir Direção
    //int directions[2] = {'H', 'V'};
    //int direction = directions[rand() % 2];

    // Escolher as cordenadas m (linha) e n (coluna)
    //int m = rand() % (rows - 4);
    //int n = rand() % (collums - 4);

    //Preenchendo o espaço ocupado pelo vetor
    /*if (m > 0 && m < rows - 1  && n > 0 && n < collums -1){
      for (int i = m - 1; i < m + 4; i++){
        for (int e = n -1; i < n + 2; e++){
          board[i][e] = 1;
        }
      }
    } */
  }
  void print_debug(void){
    for(int k = 0; k < r_close.size(); k++){
      cout << "r_close = " << r_close[k] <<  endl;
      cout << "c_close = " << c_close[k] <<  endl;
      cout << endl;
    }
  }
};
