/*
ID: wzhang11
LANG: C++
TASK: preface
*/
#include <iostream>
#include <fstream> 

using namespace std; 

int main(){
	int N, count[7] = {0,0,0,0,0,0,0};
	char roman_numeral[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; 
	int pattern[10][3] = {{0,0,0}, {1,0,0}, {2,0,0}, {3,0,0}, {1,1,0}, {0,1,0}, {1,1,0}, {2,1,0}, {3,1,0}, {1,0,1}};

	ifstream fin ("preface.in");
	ofstream fout("preface.out"); 
	fin >> N; 

	for(int i = 0; i <=N; i++){
		for(int k = i, n = 0; k > 0; k /= 10, n++){
			for(int j = 0; j < 3; j++){
				count[n*2+j] += pattern[k%10][j];
			}	
		} 
	}

	for(int i = 0; i < 7; i++){
//	true = 1 false = 0
		if(count[i]){
//			cout << roman_numeral[i] << " " << count[i] << "\n";
			fout << roman_numeral[i] << " " << count[i] << "\n"; 
		}

	}

} 


