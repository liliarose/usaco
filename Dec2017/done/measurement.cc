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
#include <ctime>
#define MAX 100001
#define SVAL 0 
using namespace std;

// if the biggest value --> 
bool testing = true, testing2 = true;

struct cow{
    int day, id, milk;
};

bool compCow(cow a, cow b){
    return a.day < b.day;
}


void print(cow arr[], int N);

int N, G, daysChanged = 0, maxMilk = SVAL;
map<int, int, greater<int> > cc;
map<int, int> cowlink_log;
bool old_top, is_last, is_only, new_top; 
cow log[MAX];

int main() {
    ifstream fin ("measurement.in");
    ofstream fout("measurement.out"); 
    
    fin >> N >> G;
    for(int i = 0; i < N; i++){
        fin >> log[i].day  >> log[i].id >> log[i].milk;
        cowlink_log[log[i].id] = SVAL;
    }
    sort(log, log+N, compCow);
    //print(log, N);
    cc[SVAL] = N+1; //starts with this #
    for(int i = 0; i < N; i++){
        cow curr = log[i];
        old_top = (cc.begin() -> first == cowlink_log[curr.id]); 
        cc[cowlink_log[curr.id]]--;
        is_last = (!cc[cowlink_log[curr.id]]);
        if(is_last){    cc.erase(cowlink_log[curr.id]);     }
        cowlink_log[curr.id] += curr.milk;
        cc[cowlink_log[curr.id]]++;
        is_only = (cc.begin() -> second == 1);
        new_top = (cc.begin() -> first == cowlink_log[curr.id]);
        if((old_top && (!new_top || !is_only || !is_last)) || (!old_top && new_top)){
            daysChanged++;
        }
    }
    fout << daysChanged << endl;
    cout << daysChanged << endl;
    return 0;
}

void print(cow arr[], int N){
    for(int i = 0; i < N; i++){
        cout << arr[i].day << " " << arr[i].id << " " << arr[i].milk << endl;
    }
}




