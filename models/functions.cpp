#include <iostream>
#include <string>

void error_msg(std::string error = ""){

    if (error != "")
        std::cout << "Erro: " << error << "\n\n";

    std::cout <<
    "Usage: [<options>] <number_of_puzzles>\n" <<
    "Program options are:\n" <<
    "--Row <num>    Specify the number of rows for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10.\n" <<
    "--Col <num>    Specify the number of collums for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10." << 
    "Requested input is:\n" <<
    "   number of puzzles   The number of puzzles to be generated, in the range [1, 100].\n";
    
    exit(0);
    
}

std::string str_tolower(std::string str){

    for (char & c : str)
        c = std::tolower(c);

    return str;
}