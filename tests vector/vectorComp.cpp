
#include <iostream>
#include <vector>

using namespace std;
int main(){
    
    vector <int> x = {3, 2, 3, 4, 4, 2, 3, 4, 2, 3, 4, 2, 3, 2, 3, 4, 
  4, 2, 1, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 3, 3};
 
    vector <int> y = {3, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 7, 7, 7,
  6, 6, 1, 0, 1, 2, 2, 0, 1, 2, 0, 1, 0, 1, 2, 2, 0};


    for(int it1 = 0; it1 <= 7; it1++)
        for(int it2 = 0; it2 <= 7; it2++)
            for(int i = 0; i <= x.size(); i++)
                if(x[i] == it1 && y[i] == it2){
                    cout << "find! on position:" << i << endl;
                    cout << x[i] << " || " << y[i] << endl;
                }
    int fake = x[6];
    int *ponteiro = &x[6];

    cout << fake << " || " << *ponteiro;

    return 0;
}