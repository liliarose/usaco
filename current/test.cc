#include <iostream>

using namespace std; 

int arr[] = {1000, 500, 100, 50, 10, 5}; 
char c[] = {'M', 'D', 'C', 'L', 'X', 'V'};
void print(int times, char c){
	for(int i = 0; i < times; i++){
		cout << c; 
	}
}

void to_Roman_Num(int num){
	
	for(int i = 0; i < 6; i++){
		if(num > arr[i]){
			print((num/arr[i]), c[i]); 
			num %= arr[i];
		}
	}
	if(num != 4){
		print(num, 'I'); 
	}
	else{
		cout << "IV"; 
	}
}
int main(){
  
  int x; 
  while(x > -1){
	  cin >>  x; 
	  to_Roman_Num(x); 
  }  
  to_Roman_Num(5112);
  return 0; 
}