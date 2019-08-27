using namespace std;
int position(int direction, int ship){
    srand(time(NULL));
    
    int result;
    
    result = rand() % (direction - (ship-1));  //compile again with changes
    
    return result;
}