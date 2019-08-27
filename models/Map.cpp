using namespace std;
// usar .board (ou .map) e .armada

class Map{
public:

  vector <vector<string>> board;
  vector <int> r_occupied;
  vector <int> c_occupied;
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
    vector <string> line;  //inicicializador de "board"
    
    //inicializa "board"
    for(int k = 0; k <= collums; k++)
      line.push_back(" . ");
    for(int k = 0; k <= rows; k++)
      board.push_back(line);    
    
    // Posicionar o Battleship
    for(int k = 0; k < ships.size(); k++){
      int *ship = &ships[k]; // ponteiro
      int r = position(rows, *ship);
      int c = position(collums, *ship);
      bool rotation = rand() % 2;
      
      //debug board
      for(int w = 0; w < board.size(); w++){
        cout << w << "[ ";
        for(int j = 0; j < board[w].size(); j++)
          cout << board[w][j];
          cout << " ]" << endl;
      }
      //conferir posições ocupadas
      if(k != 0)  //pra evitar de pegar 'occupied' vazio
        for (int w = 0; w < r_occupied.size(); w++)
          for(int ship_it = 0; ship_it < ships[k]; ship_it++)
            if (r == r_occupied[w] && c == c_occupied[w]){
              r = position(rows, *ship);
              c = position(collums, *ship);
              w = 0;
            }else 
              switch(rotation){
                case 0:
                  if((r+ship_it) == r_occupied[w] && c == c_occupied[w]){
                    r = position(rows, *ship);
                    c = position(collums, *ship);
                    w = 0;
                  }
                  break;
                case 1:
                  if(r == r_occupied[w] && (c+ship_it) == c_occupied[w]){
                    r = position(rows, *ship);
                    c = position(collums, *ship);
                    w = 0;
                  }
                  break;
                defalt:
                  cout << "thats a bug\n\n";
                  break;
              }

      //add position so dos ships e exporta pra algum lugar pra criar
          //  armada e evitar mapas repetidos 
      cout << "ships[k] = " << ships[k] << endl;

      // seperar "rotation" do resto deve cortar o tamanho da estrutura pela metade
      
      if(ships[k] > 1){
        if(rotation == 0){
          for(int s = r; s < (ships[k]+r); s++){
            //add barco
            r_occupied.push_back(s);
            c_occupied.push_back(c);
            board[c][s] = " ◼︎ ";
            //add água *pontas*
            //reaproveitar pra definir visual
            if(s == r){   //achou o começo 
              r_occupied.push_back(s-1);
              c_occupied.push_back(c-1);
              r_occupied.push_back(s-1);
              c_occupied.push_back(c);
              r_occupied.push_back(s-1);
              c_occupied.push_back(c+1);
              board[c][s] = " ◀︎ ";
              
            }
            else if(s == ships[k]+(r-1)){   //achou o fim
              r_occupied.push_back(s+1);
              c_occupied.push_back(c-1);
              r_occupied.push_back(s+1);
              c_occupied.push_back(c);
              r_occupied.push_back(s+1);
              c_occupied.push_back(c+1);
              board[c][s] = " ▶︎︎ ";
            }
            //add água *lateral*
            r_occupied.push_back(s);
            c_occupied.push_back(c+1);
            r_occupied.push_back(s);
            c_occupied.push_back(c-1);
          }
        }
        else if(rotation == 1)
          for(int s = c; s < (ships[k]+c); s++){
            r_occupied.push_back(r);
            c_occupied.push_back(s);
            board[s][r] = " ◼︎ ";
            //add água *pontas*
            if(s == c){   //achou o começo 
              c_occupied.push_back(s-1);
              r_occupied.push_back(r-1);
              c_occupied.push_back(s-1);
              r_occupied.push_back(r);
              c_occupied.push_back(s-1);
              r_occupied.push_back(r+1);
              board[s][r] = " ▲ ";
            }
            else if(s == ships[k]+(c-1)){   //achou o fim
              c_occupied.push_back(s+1);
              r_occupied.push_back(r-1);
              c_occupied.push_back(s+1);
              r_occupied.push_back(r);
              c_occupied.push_back(s+1);
              r_occupied.push_back(r+1);
              board[s][r] = " ▼ ";
            }
            //add água *lateral*
            r_occupied.push_back(r+1);
            c_occupied.push_back(s);
            r_occupied.push_back(r-1);
            c_occupied.push_back(s);
          }
      } else if(ships[k] == 1){  //submarinos
        for(int j = c-1; j <= c+1; j++)
          for(int w = r-1; w <= r+1; w++)
            if(j <= board.size() || j > 0)
              if(w <= board[j].size() || w > 0){
                r_occupied.push_back(w);
                c_occupied.push_back(j);
              }

        board[c][r] = " ● ";
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
    for(int k = 0; k < r_occupied.size(); k++){
      cout << "r_close = " << r_occupied[k] <<  endl;
      cout << "c_close = " << c_occupied[k] <<  endl;
      cout << endl;
    }
  }
};
