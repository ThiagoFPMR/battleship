using namespace std;

void error_msg(string error = ""){

    if (error != "")
        cout << "Error: " << error << "\n\n";

    cout <<
    "Usage: [<options>] <number_of_puzzles>\n" <<
    "Program options are:\n" <<
    "--Row <num>    Specify the number of rows for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10.\n" <<
    "--Col <num>    Specify the number of collums for the matrix, with '<num>' in the range [7, 16]. The deafult value is 10." << 
    "Requested input is:\n" <<
    "   number of puzzles   The number of puzzles to be generated, in the range [1, 100].\n";
    
    exit(0);
    
}

string str_tolower(string str){

    for (char & c : str)
        c = tolower(c);

    return str;
}

int position(int direction, int ship){
    srand(time(NULL));
    
    int result;
    
    result = rand() % (direction - (ship-1));
    
    return result;
}