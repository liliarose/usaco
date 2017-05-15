/*
ID: wzhang11
LANG: C++
TASK: preface
*/
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;
 
int n,s[20];
char b[8]={'\0','I','V','X','L','C','D','M'};
//						1		2		3		4		5		6		7		8		9
int c[10][3]={{0,0,0},{1,0,0},{2,0,0},{3,0,0},{1,1,0},{0,1,0},{1,1,0},{2,1,0},{3,1,0},{1,0,1}};
// c[x][0] = I 		c[x][1] = V 		c[x][2] = X
// c[x][0] = X      c[x][1] = L         c[x][2] = C 
//etc. 

void print(int arr[], int lim){
	for(int i = 0; i < lim; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
}
int main(){
    ifstream fin("preface.in");
	ofstream fout("preface.out"); 

	fin >> n; 
   	
	for(int i=1;i<=n;i++){ 
		int k=i,f=0, j=0; 
		while (k>0){
			for(int j=0; j < 3; j++){
				s[f*2+j+1]+=c[k%10][j];
			}
            f++;
            k/=10;
        }
    }

    for (int i=1;i<=7;i++) 
		if (s[i]!=0) 
			fout << b[i] << " " << s[i] << endl;
    
	return 0;
}


