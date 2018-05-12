/*
ID: your_id_here
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool arr[250][250];
int main() {
    ifstream fin ("range.in");
    ofstream fout ("range.out");
	int N; 
	fin >> N;
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++)
			fin >> arr[k][i];
	}
	fout << N << endl;
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
			fout << arr[k][i];
		}
		fout << endl; 
	}
	fout << endl;
	
	return 0;
}

