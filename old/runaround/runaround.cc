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

string getUniqueN(string num);
bool check(string num);

int main() {
    ofstream fout ("runaround.out");
    ifstream fin ("runaround.in");
	string curr_num;  
	bool test = false; 
	fin >> curr_num;

	while(test){
		curr_num = getUniqueN(curr_num); 
		test = check(curr_num); 
	} 

	fout << curr_num; 
    return 0;
}

string getUniqueN(string num){
	bool flag[10] = {false};
	bool change = false;
	for(int i = 0; i < num.length(); i++){
		if(flag[num[i]] || num[i] == 0){
			//change curr# 
			
			change = true; 
		}
		else{
			flag[num[i]] = true; 
		}
	}
	if(!change){
		//change to next uniqueN
	}
	return num; 
}

bool check(string num){
	bool flag[10] = {false};
	for(int i = 0, curr = (num[0] - 48); i < num.length(); i++){
		flag[curr] = true; 
		if(flag[num.length()-curr]){
			return false;
		}
		else{
			curr = (num[num.length()-curr] - 48);
		}
	}
	return true; 
}

