/*
ID: wzhang11
LANG: JAVA
TASK: milk3
*/
import java.util.*;
import java.io.*; 

class milk3{
	
	public void exchange( int give, int get, int[] size, int[] change){
		int temp = size[get] - change[get];
		change[get] += change[give]; 
		if(change[get] > size[get]) 	change[get] = size[get]; 
		change[give] -= temp; 
		if(change[give] < 0) change[give] = 0; 
	}
	
	public static void main (String[] args)throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("milk3.in")); 
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out"))); 
		StringTokenizer st = new StringTokenizer(in.readLine()); 
		int[] msize = new int[3];	
		milk3 M = new milk3(); 		
		msize[0] = Integer.parseInt(st.nextToken()); 
		msize[1] = Integer.parseInt(st.nextToken()); 
		msize[2] = Integer.parseInt(st.nextToken()); 
		int x = msize[2]+1; 
		// times each emptyA
		boolean[] emptyA = new boolean[x]; 
		// msize[2] is def. part of answer 
		emptyA[msize[2]] = true; 
		int[] actual = new int[3]; 
		// intialize actual[] values 
		actual[0] = 0; 		actual[1] = 0; 		actual[2] = msize[2]; 
		
		// for C -> B ->  A
		for(int i = 2, k, temp; ; --i){
			if(i != 0) k = i-1; 
			else k = 2; 
			M.exchange( i, k, msize, actual);
			//System.out.println("")
			// test if actual is 0, and emptyA is t/f 
			if(actual[0] == 0){
				if(emptyA[actual[2]]){
					if(i == 0) i = 3; 
					break; 
				}
				else{
					emptyA[actual[2]] = true; 
				}
			}
			if(i == 0) i = 3; 
		}
		
		// array count 
		boolean[] count = new boolean[x];
		
		// for C -> A ->  B
		for(int i = 2, k, temp; ; i++){
			if(i != 2) k= i+1; 
			else k = 0; 
			
			M.exchange( i, k, msize, actual);			
			// System.out.println("actual["+i+"]: "+actual[i]+"\tactual["+k+"]: "+actual[k]); 
			
			if(actual[0] == 0){
				if(count[actual[2]]){
					break; 
				}
				else{
					count[actual[2]] = true; 
					emptyA [actual[2]] = true; 
				}
			}
			if(i == 2) i = -1; 
		}
		for( int i = 0; i < x; i++){
			if(emptyA[i])
				System.out.println(i);
		}
		
	}
}















