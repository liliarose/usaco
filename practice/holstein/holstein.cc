/*
ID: wzhang11
LANG: C++
TASK: holstein
*/
#include <iostream> 
#include <fstream>
using namespace std; 
int V, G, minLev, minFeed = 625, nowFeed = 0; 
int feed[15][25];
int ans[15];
int now_ans[15];
int temp_feed[25] = {0};
int vita[25]; 

bool check(){
	for(int i = 0; i < V; i++){
		if(vita[i] > temp_feed[i])
			return false; 
	}
	return true;	
}
/*void print(int arr[], int len){
	for(int i = 0; i < len; i++){
		cout << arr[i] << " "; 
	}
	cout << endl;
}*/
void DFS(int start, int level){
	nowFeed += start; 
	if(level > minLev || (nowFeed > minFeed && level == minLev)){
		nowFeed -= start;
		return; 
	}
	now_ans[level] = start;
	for(int i = 0; i < V; i++){
		temp_feed[i] += feed[start][i];
	}
	if(check()){
		minFeed = nowFeed; 
		minLev = level; 
		for(int i = 0; i <= level; i++){
			ans[i] = now_ans[i] + 1; 
		}
	}
	else{
		for(int i = start+1; i < G; i++){
			DFS(i, level+1);
		}
	}
	
	nowFeed -= start; 
	for(int i = 0; i < V; i++){
		temp_feed[i] -= feed[start][i];
	}	
}

int main(){
	ifstream fin("holstein.in"); 
	ofstream fout("holstein.out"); 
	fin >> V; 
	minLev = V; 
	for(int i = 0; i < V; i++)
		fin >> vita[i]; 
	fin >> G; 
	for(int i = 0; i < G; i++)
		for(int k = 0; k < V; k++)
			fin >> feed[i][k]; 
	//scanned in now 
	
	for(int i = 0; i < G; i++){ 
		DFS(i, 0); 
	}
	
	fout << minLev+1 << " "; 
	for(int i = 0; i <= minLev; i++){
		fout << ans[i];
		if(i != minLev){
			fout << " "; 
		}
		else{
			fout << endl; 
		}
	}
	return 0;
}