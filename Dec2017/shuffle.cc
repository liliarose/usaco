/*
ID: wenxzha1 
TASK: shuffle 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <queue>
#define MAX 100001

using namespace std;

void print(int arr[], int N){
    for(int i = 1; i <= N; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}
void print(bool arr[], int N){
    for(int i = 1; i <= N; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    ifstream fin ("shuffle.in");
    ofstream fout("shuffle.out");
    
    int N;
    fin >> N;
    int cnt = N;
    int order[N+1];
    int back_cnt[N+1];
    queue <int> q;
    
    //memset(test, 0, sizeof(test));
    memset(back_cnt, 0, sizeof(back_cnt));

    //back_cnt[][0] = first value && back_cnt[][1] = last value
    for(int i = 1; i <= N; i++){
        fin >> order[i];
        back_cnt[order[i]]++;
    }
    //print(back_cnt, N);  
    //memset(flag, 0, sizeof(flag));

    for(int i = 1; i <= N; i++){
        if(!back_cnt[i]){
            //cout << i << endl;
            q.push(i);
            cnt--;
        }
    }
    
    while(!q.empty()){
       int i = q.front();
       q.pop();
       //back_cnt[order[i]]--;
       if(!(--back_cnt[order[i]])){
           q.push(order[i]);
           cnt--;
       }
       //print(back_cnt, N);
    }
    
    //cout << cnt << endl;
    fout << cnt << endl;
    //print(test, N);
    return 0;
}







