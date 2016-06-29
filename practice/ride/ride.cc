#include <iostream>
#include <fstream>

using namespace std; 


int toInt(char *arr, int len){
	
	int a = 0; 
	while(int i = 0; i < len; i++){
		a = a* (((int)arr[i]) - 65); 
	}
	return a; 
}

int main(){
	
	ifstream fin("ride.in"); 
	ofstream fout("ride.out"); 
	
	string a, b; 
	int c, d; 
	fin >> a >> b; 
	
	c = toInt(a, sizeof(a));
	d = toInt(b, sizeof(b));
	
	if(c%47 == d%47 ){
		fout << "GO\n"; 
	}
	else{
		fout << "STAY\n";
	}
	
	return 0; 
}