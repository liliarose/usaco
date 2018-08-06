/*
ID: wenxzha1 
TASK: shuffle 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAX 100001

using namespace std;

//int id_curr[101];
//int id_prev[101];
int N;
bool flag[MAX];
bool flag2[MAX];

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
    int order[N];
    int test[N];
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        fin >> order[i];
        if(flag[i]]){
            cnt++;
            flag2[i] = true;
        } else {
           flag[i] = true; 
        }
    }

    if(cnt != 0){
        for(int i = 0; i < N; i++){
            memset(test, 0, sizeof(test));
            for(int i = 1; i < N; i++){
                if(!flag2[i]){
                    
                }
            }
        }
    }

    fout << N - cnt << endl;
    
    return 0;
}







