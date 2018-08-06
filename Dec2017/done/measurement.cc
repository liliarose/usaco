/*
ID: wenxzha1 
TASK: measurement
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Bessie = 0, Elsie = 1, and Mildred = 2 

int output[3][101];


int main() {
    ifstream fin ("measurement.in");
    ofstream fout("measurement.out");
    //cout << "Bessie = 0, Elsie = 1, and Mildred = 2\n";  
    int N, max = 0, daysChanged = 0;
    fin >> N;
    for(int i = 0, id, day, delta; i < N; i++){
        string stmp;
        fin >> day >> stmp >> delta;
        //cout << day << " " << stmp << " " << delta << "\t";
        if(stmp == "Bessie"){ id = 0; }
        else if(stmp == "Elsie") { id = 1; }
        else if(stmp == "Mildred") { id = 2; }
        else {cout << "different name?: " << stmp << endl;}
        output[id][day] += delta;
        //cout << id << "\n";
        if(day > max){ max = day;}
    }
    output[0][0] = 7,  output[1][0] = 7,  output[2][0] = 7;
    //calculate actual max
    cout << max << endl;
    bool cowIDs[3] = {true, true, true};
    for(int i = 1; i <= max; i++){
        int maxOut = 0;
        for(int j = 0; j < 3; j++){
            output[j][i] =  output[j][i] +  output[j][i-1];
            if(output[j][i] > maxOut) {maxOut = output[j][i];}
        }
        bool changed = false;
        for(int j = 0; j < 3; j++){
            if(output[j][i] == maxOut && !cowIDs[j]){
                cowIDs[j] = true, changed = true;
                //cout << i << ": " << j << " added\n";
            } else if(output[j][i] < maxOut && cowIDs[j]){
                cowIDs[j] = false, changed = true;
                //cout << i << ": " << j << " taken down\n";
            }
        }
        if(changed) {daysChanged++;}
    }
    fout << daysChanged << endl;
    return 0;
}






