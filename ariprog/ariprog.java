/*
ID: wzhang11
LANG: JAVA
TASK: ariprog
*/
import java.io.*;
import java.util.*;

class ariprog 
{  
	
  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("ariprog.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));	
		// scan in #s, N, M
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken()); 	
		st = new StringTokenizer(in.readLine());
		int M = Integer.parseInt(st.nextToken()); 
		boolean[] arr = new boolean[M*M*2+1]; 
		// set bisquare values to true
		for(int i = 0; i <= M ; ++i){
			for(int k = i; k <= M; ++k){
				arr[i*i+k*k]= true; 
			}}
		
		boolean notThere = true; 
		int MAX = M*M*2, n = N-1; 
		int size = MAX/n, S;
		for(int b = 1, k; b <= size; ++b){
			S = (MAX)-b*n;
			for(int a = 0; a <= S; ++a){
				for(k = 0; k < N;k++){
					if(!(arr[a+k*b]))
						break; 
				}
				if(k==N){
					out.println(a + " " + b);
					notThere = false; 
				}
				
			}
			
		}
		
		if(notThere){
			out.println("NONE");
		}

		in.close();
		out.close();
		System.exit(0);	
		
  }
}