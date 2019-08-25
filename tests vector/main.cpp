#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector <int> dim1;
    vector <vector<int>> dim2;
    vector <vector <vector <int>>> vec;

    for(int k = 0; k <= 3; k++)
        dim1.push_back(2);

    for(int k = 0; k <= 3; k++)
        dim2.push_back(dim1);

    for(int k = 0; k <= 3; k++)
        vec.push_back(dim2);

    
    cout << "vec = ";
    for(int j = 0; j < vec.size(); j++){
        for(int k = 0; k < vec[j].size(); k++){
            cout << endl;
            for(int k2 = 0; k2 < vec[j][k].size(); k2++)
                cout << dim2[k][k2] << ", ";
        }
    cout << "\n\n\n";
    }
}