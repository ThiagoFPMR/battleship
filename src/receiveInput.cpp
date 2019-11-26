
#include "../include/receiveInput.h"

using namespace std;

void message(string error="")
{
    error = "";
    if (error != "")
        cout << "Error: " << error << "\n\n";

    cout << "Usage: [<options>] <number_of_puzzles>\n"
         << "Program options are:\n"
         << "--Row <num>    Specify the number of rows for the matrix, with '<num>' in the range [9, 16]. The deafult value is 10.\n"
         << "--Col <num>    Specify the number of collums for the matrix, with '<num>' in the range [9, 16]. The deafult value is 10."
         << "Requested input is:\n"
         << "   number of puzzles   The number of puzzles to be generated, in the range [1, 100].\n";

    exit(0);
}

string str_tolower(string str)
{

    for (char &c : str)
        c = tolower(c);

    return str;
}

void receiveInput (int argc, char * argv[], int * np, int * r, int * c)
{

	// Se não houver arguemntos (apenas o nome do programa), exibimos a mensagem de ajuda.
    if ( argc == 1 )
        message();
	// Se tivermos mais do que 6 argumentos, finalizamos também.
    if ( argc > 6 )
        message("Too many argumnents!");
	// Uma outra abordagem, talvez a melhor, seria apenas ignorar os argumentos
	// extras. Nesse caso, o `for` abaixo precisaria ser ajustado
	// para que parasse quando alcançar argc (número de argumentos) OU
	// chegar a 6, o que acontecer primeiro.

    // Processar os argumentos
    for ( auto i{1} ; i < argc ; ++i )
    {
        // convert the current argument to lower case.
        auto s_arg = str_tolower( argv[i] );
		// Testar se o argumento é uma das possibilidade que o programa deve aceitar.
        if ( s_arg == "-r" or s_arg == "--row" or s_arg == "-row" or s_arg == "--r"  )
        {
			// Aqui executamos 3 testes em sequência:
            int nrows{0};
			// Teste #1: Para evitar segfault, precisamos verificar se existe o
			// próximo argumento **antes** de tentar acessa-lo.
            if ( (i+1) == argc )
                message("Missing number of rows!");
			// Teste #2: Aqui usamos tratamento de exeções para verificar
			// se a converdsão de string para inteiro deu certo.
			// Lemnbre que precisamos converter, "12" para inteiro 12.
            try {
                nrows = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for row!");
            }
			// Teste #3: Neste ponto, já temos um inteiro válido. Resta saber
			// se esse inteiro está dentro da faixa de valores que o programa
			// deve aceitar.
            if ( nrows < MIN_ROW or nrows > MAX_ROW )
                message("Number of rows out of the acceptable range!");
			// Quando chegamos aqui, temos um número inteiro válido que
			// corresponde à quantidade linhas que o programa deve usar
			// para criar tabuleiros.
            *r = nrows; // Copiar da variável temporária para a definitiva, 'r'.
        }
        else if ( s_arg == "-c" or s_arg == "--col" or s_arg == "-col" or s_arg == "--c"  )
        {
           	// Aqui executamos 3 testes em sequência:
            int ncols{0};
			// Teste #1: Para evitar segfault, precisamos verificar se existe o
			// próximo argumento **antes** de tentar acessa-lo.
            if ( (i+1) == argc )
                message("Missing number of rows!");
			// Teste #2: Aqui usamos tratamento de exeções para verificar
			// se a converdsão de string para inteiro deu certo.
			// Lemnbre que precisamos converter, "12" para inteiro 12.
            try {
                ncols = std::stoi( argv[++i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for row!");
            }
			// Teste #3: Neste ponto, já temos um inteiro válido. Resta saber
			// se esse inteiro está dentro da faixa de valores que o programa
			// deve aceitar.
            if ( ncols < MIN_ROW or ncols > MAX_ROW )
                message("Number of rows out of the acceptable range!");
			// Quando chegamos aqui, temos um número inteiro válido que
			// corresponde à quantidade linhas que o programa deve usar
			// para criar tabuleiros.
            *c = ncols; // Copiar da variável temporária para a definitiva, 'r'.
        }
        else // # of puzzles
        {
            int npuzzles{1};
            try {
                npuzzles = std::stoi( argv[i] );
            }
            catch( const std::invalid_argument& e ){
                message("Invalid value for number of puzzles!");
            }
            if ( npuzzles < MIN_NPUZ or npuzzles > MAX_NPUZ )
                message("The requested number of puzzles is out of the acceptable range!");
            *np = npuzzles;
        }
    }
    std::cout << ">>> cols = " << *c << ", rows = "  << *r << ", npuzzles = " << *np << std::endl;
}