#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector <vector <int>> libvec;

    for(int k = 0; k <= 3; k++)
        libvec.push_back({2, 2, 2, 2});
        //for(int kk = 0; kk <= 3; kk++)
            //libvec[k].push_back(2);

    for(int k = 0; k < libvec.size(); k++){
        for(int kk = 0; kk < libvec.size(); kk++)
            cout << libvec[k][kk] << "  ";
        cout << endl;
    }
}