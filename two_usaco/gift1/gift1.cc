/*
ID: your_id_here
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10

using namespace std;

int account[MAX], N;
string names[MAX];
int find(string str);

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

	fin >> N;

	for(int i = 0; i < N; i++){
		fin >> names[MAX];
	}

	while(!fin.eof()){
		string curr; 
		int total, p;
		cin >> curr >> total >> p;
		account[find(curr)] = total%p;
		for(int i = 0, id, tmp = total/p; i < p; i++){
			cin >> curr;
			account[find(curr)] = tmp;
		}
		cout << curr << endl;
	}

	//for()

	return 0;
}


int find(string str){
	for(int i = 0; i < N; i++){
		if(str == names[i])
			return i;
	}
	return -1;
}









