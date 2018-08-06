/*
ID: wenxzha1 
TASK: measurement
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list> 
#include <map> 

using namespace std;

//Bessie = 0, Elsie = 1, and Mildred = 2 

struct cow{
    int day, id, delta;
};

bool compCow(cow a, cow b){
    /*if(a.day == b.day){
        return a.id <  b.id;
    }*/
    return a.day < b.day;
}

void print(cow arr[], int N);

int main() {
    ifstream fin ("measurement.in");
    ofstream fout("measurement.out");

    int N, G, daysChanged = 0, maxMilk = 7;
    fin >> N >> G;
    
    cow log[N];
    
    for(int i = 0, id, day, delta; i < N; i++){
        fin >> day >> id >> delta;
        //cout << day << " " << id << " " << delta << "\n";
        log[i].day = day;        log[i].id = id;        log[i].delta = delta;
    }
    cout << endl;
    sort(log, log + N, compCow);
    print(log, N);
    

    fout << daysChanged << endl;
    return 0;
}

void print(cow arr[], int N){
    for(int i = 0; i < N; i++){
        cout << arr[i].day << " " << arr[i].id << " " << arr[i].delta << endl;
    }
}




