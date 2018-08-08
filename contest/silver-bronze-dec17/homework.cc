/*
ID: wenxzha1 
TASK: homework
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

//priority_queue<int, vector<int>, greater<int> > least;
int homework[100001];
int K [100000];
int N, kLim;
double kMax = 0.0;

void print(int arr[], int N){
    for(int i = 0; i <= N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ifstream fin ("homework.in");
    ofstream fout("homework.out");
    
    fin >> N;

    for(int i = 1; i <= N; i++){
        fin >> homework[i];
    }
   
    int least = (homework[N] < homework[N-1])?(homework[N]):(homework[N-1]), sum = homework[N] + homework[N-1];
    
    for(int i = N-2; i > 0; i--){
        double currScore = (sum - least)/(N-i-1.0);
        if(currScore > kMax) { 
            kMax = currScore;    kLim = 0;  
        }   
        if(currScore == kMax) { 
            K[kLim] = i;        kLim++; 
        }   
        sum += homework[i];
        if(least > homework[i]) least = homework[i];
    }

    for(int i = kLim -1 ; i >= 0 ; i--){
        fout << K[i] << endl;
    }
    return 0;
}

















