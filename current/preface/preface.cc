/*
ID: wzhang11
LANG: c++
TASK: preface
*/
#include <iostream>
#include <fstream>

using namespace std; 
int N; 
int numberals[MAX]; 
int lim[] = {1, 5, 10, 50, 100, 500, 1000}; 
int level[] = {7, 5, }

enum rnums{
	I,
	V,
	X, 
	L, 
	C, 
	D, 
	M, 
	MAX
}; 

int main(){
	
	ifstream fin ("preface.in"); 
	ofstream fout("preface.out"); 
	cin >> N; 
	
	solve(); 
	
    cout << "I " << numberals[I] << 
		    "\nV " << numberals[V] <<
			"\nX " << numberals[X] << 
			"\nL " << numberals[L] <<
			"\nC " << numberals[C] <<
			"\nD " << numberals[D] <<
			"\nM " << numberals[M] << "\n"; 
	return 0; 
}

