/*
ID: wenxzha1 
TASK: shuffle
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int id_curr[101];
int id_prev[101];
int order[101];
int N;

void print(int arr[]){
    for(int i = 1; i <= N; i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main() {
    ifstream fin ("shuffle.in");
    ofstream fout("shuffle.out");
    fin >> N; 
    for(int i = 1; i <= N; i++){
        fin >> order[i];
    }
    for(int i = 1; i <= N; i++){
        fin >> id_prev[i];
    }
    //print(id_prev);
    for(int j = 1; j <= 3; j++){
        for(int i = 1; i <= N; i++) { 
            id_curr[i] = id_prev[order[i]];
        }
        for(int i = 1; i <= N; i++) {
            id_prev[i] = id_curr[i];
        }
        //print(id_prev);
    }
    for(int i = 1; i <= N; i++) {
        fout << id_prev[i] << endl;
    }

    return 0;
}
