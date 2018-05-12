/*
ID: your_id_here
TASK: gift1 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string names [10]; 
	int intial[10];
	int final[10]; 
	int N; 
	string temp; 

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> names[i];
	}

	for(int i = 0, A, B; i < N; i++){
		cin >> temp >> A >> B;
		intial[getIndex(names, temp)] = A; 
		for(int j = 0; j < B; j++){
			cin >> temp; 
			final[getIndex(names, temp)] = A/B; 
			no
		}
	} 
	
    return 0;
}
