/*
ID: wzhang11 
TASK: fence
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int N, arr[501][501], mx = -1;

stack<int> circuit;

void add_edge(int a, int b){
	arr[a][b]++;
	arr[b][a]++;
}

void rm_edge(int a, int b){
	arr[a][b]--;
	arr[b][a]--;
}

void find_circuit(int a);

void eulerianTrail(){
	int curr = 1; 
	for(int i = 1; i <= mx; ++i){
        int degree = 0;
        for(int j = 1; j <= mx; j++){
            if(arr[i][j] > 0) {
                degree++;   
            }   
        }   
        if(degree&1){
            curr = i;
			break;
        }   
  	}
	find_circuit(curr);
}

void find_circuit(int a){
	for(int i = 1; i <= mx;){
		if(arr[a][i] > 0){
			rm_edge(a, i);
			find_circuit(i);
		}
		i++;
	}
	circuit.push(a);
}

void print(){
	for(int i = 1; i <= mx; i++){
		for(int k = 1; k <= mx; k++){
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}
}

int main() {
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");

	fin >> N;
	for(int i = 0, t1, t2; i < N; i++){
		fin >> t1 >> t2;
		add_edge(t1, t2);
		if(mx < t1) mx = t1;
		if(mx < t2) mx = t2;
	}
	eulerianTrail();
	
	while(!circuit.empty()){
		fout << circuit.top() << endl;
		circuit.pop();
	}

	/*while(!circuit.empty()){
		//cout << circuit.top() << endl;
		fout << circuit.top() << endl; 
		circuit.pop();
	}*/
	
	return 0;
}
