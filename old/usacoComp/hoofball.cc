/*
ID: your_id_here
TASK: hoofball 
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#define WID 2 


using namespace std;

bool flag[100];
void print(bool arr[], int N);
int get_target(int cow[], int N);

int main() {
    ofstream fout ("hoofball.out");
    ifstream fin ("hoofball.in");
	
	int cows[100], N, count = 0;

	fin >> N; 
	for(int i = 0; i < N; i++){
		fin >> cows[i];
	}
	sort(cows, cows + N);
	count = get_target(cows, N);

	flag[N-2] = true;

	for(int i = 0; i < N; i++){
		if(!flag[i]){
			count++;
		}
	}
//	print(flag, N);
	fout << count << endl;

	return 0;
}

int get_target(int cows[], int N){
	flag[1] = true;
	for(int i = 1; i < N-1; i++){
        if((cows[i] - cows[i-1]) < (cows[i+1] - cows[i])){
            flag[i-1] = true; 
        		
		} else {
            flag[i+1] = true; 
        }   
    }   
    flag[N-2] = true;
	return 0;
}



void print(bool arr[], int N){
    for(int i = 0; i < N; i++){
        cout << left << setw(WID) << arr[i];
    }
    cout << endl;
}

