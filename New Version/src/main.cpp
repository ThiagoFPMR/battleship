#include <iostream>
#include <fstream>

#define MIN_ROW 7
#define MIN_COL 7
#define MAX_ROW 16
#define MAX_COL 16

#define MIN_NPUZ 1
#define MAX_NPUZ 100

#define STD_NPUZ 1
#define STD_ROW 10
#define STD_COL 10

#include "../include/functions.h"

int main(int argc, char * argv[]) {
    int quantity{STD_NPUZ}, rows{STD_ROW}, collums{STD_COL};
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

            rows = nrows;
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

            collums = ncols;
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

            quantity = npuzzles;
        }
    }

    return 0;
}

