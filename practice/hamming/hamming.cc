/*
ID: wzhang11
LANG: C++  
PROG: hamming	
*/
#include <iostream>
#include <fstream>

using namespace std; 

int N, B, D, max1; 
int* ans; 
bool check(int a){
	
	for(int i = 0; i < a; i++){
		int comp = ans[i] ^ ans[a];
		int count = 0;
		while(comp != 0){
			count++; 
			comp = comp & (comp - 1); 
		}
		if(count < D){
			return false; 
		}
	}
	return true;
}

int main(){
	
	ifstream fin ("hamming.in"); 
	ofstream fout("hamming.out"); 
	
	fin >> N >> B >> D; 
	int temp[N]; 
	ans = temp;
	ans[0] = 0; 	
	fout << "0 ";
	max1 = (510 >> (8-B));
	for(int k = 0, count = 1; count < N && k < max1; k++){
		ans[count] = k;
		if(check(count)){
			fout << k ;
			count++;
			if(count%10 && count != N){
				fout << " ";
			}
			else {
				fout << endl; 
			}
		}
	}
	return 0;
}