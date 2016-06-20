#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
bool flag[51][51];
bool castle[51][51][4];
int roomNum = 0;
int maxSize = 0; 
int nMaxSize = 0; 
int rmI, rmJ, rmK; 
int sizeCount; 

//recursive search: return room size
void searchRoom(int i, int j){
	if(!flag[i][j]){
		sizeCount++;
		flag[i][j] = true;
		int k = 0;
		
		//west
		if(castle[i][j][k]){
			searchRoom(i, j-1); 
			cout << "done";
		} k++;
		
		//north
		if(castle[i][j][k]){
			searchRoom(i-1, j); 
		} k++; 
		
		//east 
		if(castle[i][j][k]){
			searchRoom(i, j+1); 
		} k++;
		
		//south
		if(castle[i][j][k]){
			searchRoom(i+1, j); 
		} k++; 
	}
	
}
int main(){
	memset(flag, '0', 1);
	ifstream fin ("castle.in");
	ofstream fout ("castle.out"); 
	int M, N; 
	fin >> M >> N;
	
	//scan in
	for(int i = 0, temp; i < N; i++){
		for(int j = 0; j < M; j++){
			fin >> temp; 
			for(int k = 0; k < 4; k++){
				if((temp%2) == 1){
					castle[i][j][k] = true;	} // has wall
				else{ 
					castle[i][j][k] = false;}
				temp /= 2;	
				//cout << "castle[" << i << "][" << j << "][" << k << "]: " <<  castle[i][j][k] << endl;
			}
			//cout << endl;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!flag[i][j]){
				sizeCount = 0; 
				searchRoom(i, j); 
				roomNum++; 
				if(sizeCount > maxSize){ maxSize = sizeCount;}
				cout << "[" << i << "]["<< j << "] sizeCount: " << sizeCount<< endl;  
			}
		}
	}
	cout << maxSize <<" " <<  roomNum << endl;  
	
	
}






