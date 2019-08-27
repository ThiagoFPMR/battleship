
#include <iostream>
#include <vector>

using namespace std;
int main(){
    
    vector <int> x = {1, 0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 4, 4, 2, 1, 1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 4, 4, 0, -1, 0, 1, 1, -1, 0, 1, -1, 0, -1, 0, 1, 1, -1, 3, 2, 2, 2, 3, 3, 4, 5, 5, 5, 4, 4};
 
    vector <int> y = {0, -1, 0, 1, 1, -1, 0, 1, -1, 0, 1, -1, 0, -1, 0, 1, 1, -1, 3, 2, 3, 4, 4, 2, 3, 4, 2, 3, 2, 3, 4, 4, 2, 3, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 6, 6, 5, 5, 5, 4, 5, 6, 6, 4, 5, 4, 5, 6, 6, 4};

    for(int i = 0; i <= x.size(); i++)
        if(x[i] == 4 && y[i] == 4){
            cout << "find! on position:" << i << endl;
            cout << x[i] << " || " << y[i] << endl;
        }
    int fake = x[6];
    int *ponteiro = &x[6];

    cout << fake << " || " << &ponteiro;

    return 0;
}