/*
ID: wzhang11
LANG: C++
TASK: frac1
*/

#include <iostream> 
#include <fstream>
#include <algorithm>

using namespace std;

struct frac{
	int numer; 
	int denom;
}; 

int size = 0; 
frac collect[7807]; 
void print(){
	for(int i = 0; i < size; i++){
		cout << i << ": "; 
		cout << collect[i].numer << "/" << collect[i].denom << endl; 
	}
}

bool diff_denom(int a, int b){
	for(int i = 2; i <=a; i++){
		if((a%i==0)&&(b%i == 0)){
			return false; 
		}
	}
	return true; 
}

bool comp(frac a, frac b){
	double c = a.numer/(double)a.denom; 
	double d = b.numer/(double)b.denom; 
	//cout << c << " " << d << (c < d) << endl; 
	return (c < d); 
}

int N;
int main(){
	ifstream fin ("frac1.in");
	ofstream fout ("frac1.out");
	fin >> N;
	
	collect[size].numer = 0; 
	collect[size].denom = 1; 
	size++; 
	
	for(int i = 1; i <= N; i++){
		collect[size].numer = 1; 
		collect[size].denom = i; 
		size++; 
		for(int k = 2; k < i; k++){
			if(diff_denom(k, i)){
				collect[size].numer = k; 
				collect[size].denom = i; 
				size++;
			}
		}
	}
	sort(collect, collect+size, comp);
	for(int i = 0; i < size; i++){
		fout << collect[i].numer << "/" << collect[i].denom << endl; 
	}
	//cout << size; 
	return 0; 
}

