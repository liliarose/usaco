/*
ID: wzhang11
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std; 
int diff[50];

void print(int arr[], int len){
	
	for(int i = 0 ; i < len; i++){
		cout << arr[i] << " "; 
	}
	cout << "\n";
}

int main(){
	
	ifstream fin("barn1.in"); 
	ofstream fout("barn1.out"); 
	int M, S, C; 
	fin >> M >> S >> C; 
	if( M > C ){
		fout << C << endl; 
	}
	else{
		int cows[C]; 
		
		for(int i = 0; i < C; i++){
			fin >> cows[i]; 
		}
		
		sort(cows, cows+C); 
		print(cows, C); 
		
		for(int i = 0, diffence; i < C-1; i++){
			diffence = cows[i+1] - cows[i]; 
			for(int k = 0; k < M-1; k++){
				if(diffence > diff[k]){
					diff[k] = diffence; 
					sort(diff, diff+M-1);
					break; 
				}
			}
		}
		//cout << endl; 
		int total_diff = -M; 
		for(int i = 0; i < M-1; i++){
			total_diff += diff[i]; 
			//cout << diff[i] << endl; 
		}
		cout << cows[C-1] << " - "  << cows[0] << " - " << total_diff << " = " << (cows[C-1] - cows[0] - total_diff);
		fout << (cows[C-1] - cows[0] - total_diff) << endl; 
	}
	
}