#include <iostream>
#include <fstream>

using namespace std; 

int N, M;

bool solve(int element, int diff, bool[] &bisquare){
	
	for(int i = 1; i < N; i++){
		element += diff;
		if(!bisquare[element]){
			return false;
		}
	}
		
	return true; 
}

int main(){
  
  ifstream fin ("ariprog.in");
  ofstream fout("ariprog.out"); 
   
  bool isAns = false;
  fin >> N >> M; 
  int MAX = M*M*2+1;
  bool bisquare[MAX] ={0};
  
  //set bisquare to true 
  for(int i = 1; i < M; i++){
	  for(int k = i; k < M; k++){
		  bisquare[(i*i + k*k)] = true; 
	  }
  }
  
  //process it 
  
  for(int diff = 1; diff < MAX/N; diff++){
	 for(int element = 1; element < (MAX -diff*N); element++){
		 if(bisquare[element] && solve(element, diff, bisquare)){
			 fout << element << " " << diff << endl;
			 isAns = true;
		 }
	 }
  }
  
  if(!isAns){
	  fout << "NONE\n";
  }
  
  return 0; 
}