/*
ID: wenxzha1 
TASK: ride 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define STRSZ 6
#define MOD 47

using namespace std;

int sti(string a);

int main() {
    ifstream fin ("ride.in");
    ofstream fout("ride.out");
    string a, b, smes = "GO\n", dmes = "STAY\n";
    fin >> a >> b;
    //cout << a << endl;
    //cout << b << endl;
    int resA = sti(a)%MOD, resB = sti(b)%MOD;
    //cout << resA << " " << resB << endl;
    if(resA == resB){
        fout << smes;
    } else {
        fout << dmes;
    }
    return 0;
}

int sti(string a){
    int res = 1;
    //cout << "1";
    for(int i = 0; i < a.size(); i++){
        res *= ((int)a[i] - 64);
        //cout << " * " << ((int)a[i] - 64) << " = " << res;
    }
    //cout << "\nENDING\n\n";
    return res;
}

