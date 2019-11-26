
#include "../include/receiveInput.h"

using namespace std;

void errorMsg(string error)
{
    error = "";
    if (error != "")
        cout << "Error: " << error << "\n\n";

    cout << "Usage: [<options>] <number_of_puzzles>\n"
         << "Program options are:\n"
         << "--Row <num>    Specify the number of rows for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10.\n"
         << "--Col <num>    Specify the number of collums for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10."
         << "Requested input is:\n"
         << "   number of puzzles   The number of puzzles to be generated, in the range [1, 100].\n";

    exit(0);
}

string strToLower(string str)
{

    for (char &c : str)
        c = tolower(c);

    return str;
}

void receiveInput (int argc, char * argv[], int * quantity, int * rows, int * collums) {
    // Apenas nome do progrma (sem argumentos)
    if (argc == 1)
        errorMsg();

    // Mais do que 6 argumentos (excesso)
    if (argc > 6)
        errorMsg("Too many arguments!");

    for (auto i{1}; i < argc; i++)
    {

        auto s_arg = strToLower(argv[i]);

        if (s_arg == "-r" || s_arg == "--r" || s_arg == "--row" || s_arg == "-row")
        {
            int nrows{0};

            // Teste 1
            if ((i + 1) == argc)
                errorMsg("Missing number of rows!");

            // Teste 2
            try
            {
                nrows = std::stoi(argv[i++]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for row!");
            }

            // Teste 3
            if (nrows < MIN_ROW || nrows > MAX_ROW)
                errorMsg("Number of rows out of the acceptable range!");

            *rows = nrows;
        }
        else if (s_arg == "-c" || s_arg == "--c" || s_arg == "--col" || s_arg == "-col")
        {
            int ncols{0};

            try
            {
                ncols = std::stoi(argv[i++]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for collum!");
            }

            if (ncols < MIN_COL || ncols > MAX_COL)
                errorMsg("Number of collums out of the acceptable range!");

            *collums = ncols;
        }
        else
        {
            int npuzzles{1};

            try
            {
                npuzzles = std::stoi(argv[i]);
            }
            catch (const std::invalid_argument &e)
            {
                errorMsg("Invalid value for number of puzzles!");
            }

            if (npuzzles < MIN_NPUZ || npuzzles > MAX_NPUZ)
                errorMsg("Number of puzzles out of the acceptable range!");

            *quantity = npuzzles;
        }
    }
}