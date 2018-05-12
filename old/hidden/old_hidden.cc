/*
ID: wzhang11 
TASK: hidden  
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int arr[200000], N;

int main() {
    ofstream fout ("hidden.out");
    ifstream fin ("hidden.in");
    int index= 0; 
	char tmp, min = 'z';
	fin >> N;

	//clock_t t = clock();
	for(int i = 0; i < N; i++){
		fin >> tmp; 
		arr[i] = tmp; 
		arr[i+N] = tmp;
		if(min > tmp){
			min = tmp;
			index = i;
		}
	}
	//t = clock() - t;
	//cout << "Time spent inputting string: " << ((double)t)/CLOCKS_PER_SEC << endl;
	
	for(int i = index+1, prev = -1; i < N; i++){
		int j;
		for(j = 0; j < N; j++){
			if(arr[index+j] != arr[i+j]){
				if(arr[index+j] > arr[i+j]) {	index = i; 	}
				break;
			}
		}
		if(j == N){
			break;	
		}
		if(j > N/2 && j == prev - 1){
			i = i + j - 1;
		}
		prev = j;
	}

	fout << index << endl;
	return 0;
}
