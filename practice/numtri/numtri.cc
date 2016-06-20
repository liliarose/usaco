/*
ID: wzhang11
LANG: C++  
PROG: numtri
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define MAX 1000

using namespace std; 
/*void add(int row, int col, int sum){
//	cout << "row: " << row << "\tcol: " << col << "\t tri: "<< tri[row][col]<<"\t sum: " << sum <<endl;
	sum += tri[row][col]; 	
		if (row == R){	if(sum > largest) largest = sum; 	}
		else{
			++row;		
			add(row, col, sum); 
			++col;
			add(row, col, sum); 
		} 
	
}
int[] add(int row, int col, int sum, int tstore[]){
//	cout << "row: " << row << "\tcol: " << col << "\t tri: "<< tri[row][col]<<"\t sum: " << sum <<endl;
	sum += tri[row][col]; 	
		if (row == R){	if(sum > largest) largest = sum; 	}
		else{
			++row;		
			add(row, col, sum); 
			++col;
			add(row, col, sum); 
		} 
	
}*/
int max (int a, int b){
	if(a > b) return a;
	else return b; 
}

int main() {
    //scan in items 
	ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
	int R;
	fin >> R;
	int tri[R][R];
	for(int i = 0 ; i < R; i++){
		for(int k = 0; k <=i; k++){
			fin >> tri[i][k];
		}
	}
	
	for(int i = R-1; i >=0; --i){
		for(int k = 0; k <i ; k++){
			tri[i-1][k] += max(tri[i][k], tri[i][k+1]);
		}
	}
	fout << tri[0][0] << endl;
	//cout << tri[0][0] << endl;
	
    return 0;
}