/*
ID: wenxzha1 
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 10

using namespace std;

string names[MAX];
int bank[MAX];
int N;

int search(string str){
    for(int i = 0; i < N; i++){
        if(str == names[i]) return i;
    }
    return -1;
}
int main() {
    ifstream fin ("gift1.in");
    ofstream fout("gift1.out");
    fin >> N;
    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << "OKAY\n";
        fin >> (names[i]);
        cout << names[i];
    }
    string tmp;
    for(int i = 0, tot, gifted, am; i < N; i++){
        fin >> tmp >> tot >> gifted;
        bank[search(tmp)] += tot%gifted - tot;
        if(gifted != 0) am = tot/gifted;
        else am = 0;
        for(int j = 0; j < gifted; j++){
            fin >> tmp;
            bank[search(tmp)] += am;
        }
    }

    for(int i = 0; i < N; i++){
        fout << names[i] << " " << bank[i] << endl;
        cout << names[i] << " " << bank[i] << endl;
    }

    return 0;
}
