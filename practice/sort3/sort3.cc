/*
ID: wzhang11
LANG: C++
PROG: sort3	
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

void print(int arr[], int len){
	
	for(int i = 0; i < len; i++ ){
		cout << arr[i] << "  ";
	}
	cout << endl; 
}

int main(){
	
	ifstream fin ("sort3.in"); 
	ofstream fout("sort3.out");
	int N, temp, exchanges = 0;
	fin >> N; 
	int original[N]; 
	int sorted[N]; 
	int count[6] = {0}; // 12 = 0, 21 = 1, 13 = 2, 31 = 3, 23 = 4, 32 = 5
	
	for(int i = 0; i < N; i++){
		fin >> original[i]; 
		sorted[i] = original[i];
	}
	//print(count, 6);
	sort(sorted, sorted+N);
	for(int i = 0; i < N; i++){
		if(original[i] != sorted[i]){
			temp = original[i] + sorted[i]; 
			if(temp == 3){
				if(original[i] == 1){
					count[0]++;
				}
				else{
					count[1]++;
				}
			}
			else if(temp == 4){
				if(original[i] == 1){
					count[2]++;
				}
				else{
					count[3]++;
				}
			}
			else if(temp == 5){
				if(original[i]== 2){
					count[4]++;
				}
				else{
					count[5]++; 
				}
			}
		}
	}
	//print(count, 6);
	if(count[0] == count[1]){
		exchanges = count[0] + count[2] + count[4]; 
		temp = 0; 
	}
	else{
		if(count[0] < count[1]){
			exchanges = count[0];
			temp = count[1] - count[0]; 
		}
		else{
			exchanges = count[1]; 
			temp = count[0] - count[1]; 
		}
		
		if(count[2] < count[3]){
			exchanges += count[2]; 
		}
		else{
			exchanges += count[3]; 
		}
		
		if(count[4] < count[5]){
			exchanges += count[4];
		}
		else {
			exchanges += count[5];
		}
	}
	exchanges += temp*2; 
	//cout << exchanges << endl; 
	fout << exchanges << endl; 
}