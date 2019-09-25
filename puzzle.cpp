#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

#include "./models/functions.cpp"
#include "./models/Map.cpp"

#define MIN_COL 7
#define MAX_COL 16
#define MIN_ROW 7
#define MAX_ROW 16
#define MIN_NPUZZLE 1
#define MAX_NPUZZLE 100

#define STD_COL 10
#define STD_ROW 10
#define STD_NPUZZLE MIN_NPUZZLE


using namespace std;
int main(int argc, char *argv[]){
  
  int quantity{STD_NPUZZLE}, rows{STD_ROW}, collums{STD_COL}; // Valores Padrão

  // Apenas nome do progrma (sem argumentos)
  if (argc == 1)
    error_msg();

  // Mais do que 6 argumentos (excesso)
  if (argc > 6)
    error_msg("Too many arguments!");

  for ( auto i{1}; i < argc; i++){

    auto s_arg = str_tolower(argv[i]);

    if (s_arg == "-r" || s_arg == "--r" || s_arg == "--row" || s_arg == "-row"){
      int nrows{0};

      // Teste 1
      if ((i + 1) == argc)
        error_msg("Missing number of rows!");

      // Teste 2
      try {
        nrows = std::stoi(argv[i++]);
      }
      catch(const std::invalid_argument& e){
        error_msg("Invalid value for row!");
      }

      // Teste 3
      if (nrows < MIN_ROW || nrows > MAX_ROW)
        error_msg("Number of rows out of the acceptable range!");

      rows =nrows;

    }
    else if (s_arg == "-c" || s_arg == "--c" || s_arg == "--col" || s_arg == "-col"){
      int ncols{0};

      try {
        ncols = std::stoi(argv[i++]);
      }
      catch(const std::invalid_argument& e){
        error_msg("Invalid value for collum!");
      }

      if (ncols < MIN_COL || ncols > MAX_COL)
        error_msg("Number of collums out of the acceptable range!");

      collums = ncols;
    }
    else {
      int npuzzles{1};

      try {
        npuzzles = std::stoi(argv[i]);
      }
      catch(const std::invalid_argument& e){
        error_msg("Invalid value for number of puzzles!");
      }

      if (npuzzles < MIN_NPUZZLE || npuzzles > MAX_NPUZZLE)
        error_msg("Number of puzzles out of the acceptable range!");

      quantity = npuzzles;
    }

  }


  vector <Map*> matBool; 

  //argumentos na ordem
  //quantity = 1;
  //rows = 10;
  //collums = 10;

  cout << "compilou essa desgraça!!" << endl;
  cout << quantity << endl;
  for(int k = 0; k < quantity; k++){
    matBool.push_back(new Map(rows, collums));
    cout << "\n\n";
    
    //print indice top
    cout << "    ";
    for(int w = 0; w < matBool[k]->board.size(); w++)
      cout << w << "  ";
    cout << endl;

    //print map
    for(int w = 0; w < matBool[k]->board.size(); w++){
      cout << w << "[ ";
      for(int j = 0; j < matBool[k]->board[w].size(); j++)
        cout << matBool[k]->board[w][j];
      cout << " ]" << endl;
    }
    //matBool[k]->print_debug();
  }

  
  return 0;
}
