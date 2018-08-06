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
int least[100001];
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
    double sum = 0.0; 

    for(int i = 1; i <= N; i++){
        fin >> homework[i];
        sum += homework[i];
    }
    least[N] = homework[N];
    
    for(int i = N-1; i > 0; i--){
        least[i] = (least[i+1] > homework[i]) ? (homework[i]):(least[i+1]);
    }
    least[0] = least[1];
    
    sum -= homework[1];
    for(int i = 2; i < N; i++){
        double currScore = (sum - least[i])/(N-i);
        if(currScore > kMax) { 
            kMax = currScore;    kLim = 0; 
            //cout << "CHANGED MAX SUM TO: " << currScore << "\t";
        }
        if(currScore == kMax) { 
            K[kLim] = i-1; kLim++; 
            //cout << i -1 << "\tADDED with MAX SUM OF: " << currScore << "\n";
        }
        sum -= homework[i];
    }

    for(int i = 0; i < kLim; i++){
        fout << K[i] << endl;
    }
    return 0;
}








