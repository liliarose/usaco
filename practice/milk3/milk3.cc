/*
ID: wzhang11
LANG: C++  
PROG: milk3
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int size[3];
int bucket[3]; 
bool record[21];
bool checkB[21];
bool checkC[21];

bool Full(int check){
	if(bucket[check] == size[check])		return true; 
	else 		return false; 
}
bool notFull(int check){
	if(bucket[check] < size[check])		return true; 
	else 		return false; 
}

bool Empty(int check){
	if(bucket[check] == 0)		return true; 
	else 		return false;
}

bool notEmpty(int check){
	if(bucket[check] != 0) 	return true; 
	else 	return false;
}

int getNum(int a, int b){
	if(a != 0 && b !=0)		return 0;
	if(a != 1 && b !=1)		return 1;
	else		return 2;
	
}

void pour(int give, int get){
	//cout << "before--> "<< "0: " << bucket[0] << " \t1: " << bucket[1] << " \t2: " << bucket[2] << endl; 
	//cout << "before--> "<< "0: " << bucket[0] << " \t1: " << bucket[1] << " \t2: " << bucket[2] << endl; 
	int temp = size[get] - bucket[get];
	bucket[get] += bucket[give]; 
	if(bucket[get] > size[get]) bucket[get] = size[get]; 
	bucket[give] -= temp; 
	if(bucket[give] < 0) bucket[give] = 0; 
	//cout << "after--> " <<"0: " << bucket[0] << " \t1: " << bucket[1] << " \t2: " << bucket[2] << endl << endl; 
	
}

void process(int give, int got){
	int t = 0; 
	do{
		if(Empty(0)){
			if(record[bucket[2]]) break; 
			else {
				record[bucket[2]] = true;
				//cout <<"0: " << bucket[0] << " \t2: " << bucket[2] << endl << endl;
			} 
		}
		else{
			if(Empty(1)){
			if(checkB[bucket[0]]) break; 
			else checkB[bucket[0]] = true; 
			}
			else if(Empty(2)){
				if(checkC[bucket[0]]) break; 
				else checkC[bucket[0]] = true; 
			}
			int other = getNum(give, got);
			int a = bucket[0]; int b = bucket[1]; int c = bucket[2];
			
			if(notEmpty(other)){
				pour(other, give); 
				process(other, give); 
				bucket[0] = a; bucket[1] = b; bucket[2] = c; 
				if(notFull(got)){
					pour(other, got); 
					process(other, got);
					bucket[0] = a; bucket[1] = b; bucket[2] = c; 
				}
			}
			if(notFull(other)){
				pour(got, other);
				process(got, other);
				bucket[0] = a; bucket[1] = b; bucket[2] = c; 
				if(notEmpty(give)){
					pour(give, other); 
					process(give, other); 
					bucket[0] = a; bucket[1] = b; bucket[2] = c; 
				}
			}
		}
}


int main() {
    //scan in items 
	ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
	fin >> size[0] >> size[1] >> size[2];
	bucket[0] = 0;	 bucket[1] = 0; 	bucket[2] = size[2]; int x = size[2] +1;
	for(int i = 0; i < x; ++i){
		record[i] = false; 
		checkB[i] = false;
		checkC[i] = false;
	}
	record[size[2]] = true; 
	pour(2, 1);
	process(2, 1); 
	//cout << "next step" << endl;
	bucket[0] = 0;	 bucket[1] = 0; 	bucket[2] = size[2];
	pour(2, 0);
	process(2, 0); 
	
	for(int i = 0, check = 0; i < x; ++i){
		//cout << record[i];
		if(record[i]){
			if(check == 1){
				fout <<" " << i;
			}
			else{
				fout << i; 
				check++;
			}
			
		}
	}
	fout << endl;
	
	
    return 0;
}

















