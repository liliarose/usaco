#include <iostream> 
#include <fstream>
#define STOP 1
#define CONT 0

//true = 1 false = 0
using namespace std; 

//ofstream //debug("//debug.out", std::ofstream::out | std::ofstream::trunc);

int num = 0; 

bool solution(int sum, int curr_num, int lim, int N){

  //  //debug << endl << "NEW START at " << curr_num  << "\t SUM = " << sum << "\t LIM = " << lim<< endl;
    if(sum == lim){
    	num ++;
	//debug << endl << "CORRECT SUBSET! \tcurrent #: " << curr_num << endl;
	return STOP;
    }
    else if(sum > lim){
    	return STOP;
    }
    else{
    	for(int i = curr_num+1; i <= N; i++){
            //debug << "At i = " << i << "\t" << "SUM = " << sum +i << endl;
	    if(solution(sum + i, i, lim, N)){
	    	//debug << "STOP at i = " << i << endl;  
	    	break;
	    } 
	    //debug << "SKIP i = " << i << "\t";
	}
    }
    return CONT; 
}

int main(){

   ifstream fin ("subset.in");
   ofstream fout ("subset.out");
   int N, lim; 
   fin >> N;
 //debug<< N << endl;
   
   if( !(N & 1)){
	//debug << 0 << endl; 
	fout << 0 << endl;
	return 0;
   } 

   // get lim * 2
   for(int i = 1; i <= N; i++){
      lim += i; 
   }
   lim/=2; 
//debug << "SUM LIMIT = " << lim << endl;
   //find all possible sums 
   for(int i = 1; i <= N/2 +2 ; i++){
	 //debug<< "Currently " << i << endl; 
   	solution(i, i, lim, N);
   }
   // divide num/2
 //debug<< endl  << num << endl; 
if(num & 1){
	cout << "ERROR: number is odd - " << num << endl;
} 
   fout << num/2 << endl;

fout.close();  
   return 0; 

}
