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
#define SVAL 0 
using namespace std;

// if the biggest value --> 
bool testing = true, testing2 = true;

struct cow{
    int day, id, milk;
    bool operator < (const cow b) const{
        return milk < b.milk;
    }
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
    ofstream fout("test.out"); 
    
    int N, G, daysChanged = 0, maxMilk = SVAL;
    fin >> N >> G;
   
    map<int, int, greater<int> > cc; // # of cows w/ this or change_counter
    map<int, int> cowlink_log; // cow list
    cow log[N];

    for(int i = 0; i < N; i++){
        fin >> log[i].day  >> log[i].id >> log[i].milk;
        cowlink_log[log[i].id] = SVAL;
    }

    sort(log, log+N, compCow);
    //print(log, N);
    //for(int i = 0)    
    cc[SVAL] = N; //starts with this #
    fout << 0 << " " << cowlink_log[0] << endl;
    for(int i = 0; i < N; i++){
        cow tmp = log[i];
        if(tmp.id == 27){
            cowlink_log[27] += tmp.milk;
            fout << tmp.day << " " << cowlink_log[27] << endl;
        } 
    }
    return 0;
}

void print(cow arr[], int N){
    for(int i = 0; i < N; i++){
        cout << arr[i].day << " " << arr[i].id << " " << arr[i].milk << endl;
    }
}




