/*
ID: wzhang11
LANG: JAVA
TASK: wormhole
*/
import java.io.*;
import java.util.*;

class wormhole 
{   
	public int[] X; 
	public int[] Y; 
	public int[] nextRight; 
	public int[] mate; 
	int N; 
	
	wormhole(int[] x, int[] y, int[] nR, int n){
		X=x; 
		Y=y; 
		nextRight= nR; 
		N=n;
		mate= new int[N+1]; 
	}
	
	public boolean isCycle(){
		int pos; 
		System.out.println();
		for(int start =1; start<=N;start++){
			pos= start;
			for(int i=0; i<N;++i){
				pos = nextRight[mate[pos]];
				//if(pos==0)			break; 
			}
			if(pos!=0)		return true; 
		}
		return false; 
	}
	
	public int pair(){
		int i, total=0; 
		for(i=1; i<=N;++i){
			if(mate[i]==0) 		break; 
		}
		if(i>N){
			if(isCycle())
				return 1; 
			else {
				return 0; 
			}
		}
		
		for(int k=i+1;k<=N;k++){
			if(mate[k]==0){
				mate[i]=k;
				mate[k]=i; 
				total+= pair();
				mate[i]=0; 		mate[k]=0; 
			}
		}
		return total; 
	}
	
  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("wormhole.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("wormhole.out")));	
		StringTokenizer st = new StringTokenizer(in.readLine());
		//scan in N and create (X, Y) and nextRight
		int N= Integer.parseInt(st.nextToken()); 
		int[] X =new int[N+1];
		int[] Y = new int[N+1]; 
		int[] nextRight = new int[N+1]; 
		
		//scan and store
		for(int i =1; i<=N;i++){
			st= new StringTokenizer(in.readLine());
			X[i] = Integer.parseInt(st.nextToken());
			Y[i] = Integer.parseInt(st.nextToken());
		}
		
		//find nextRight
		for(int i=1; i<=N;++i){
			for(int k=1; k<=N;++k){
				if(Y[i]==Y[k]&&X[i]<X[k]){
					if(nextRight[i]==0||X[k]-X[i]<X[nextRight[i]]-X[i]){
						nextRight[i]=k; 
					}
				}
			}
		}
		wormhole wh = new wormhole(X, Y, nextRight, N); 
		out.println(wh.pair()); 
		out.close();
		in.close();
		System.exit(0);
		
  }
}












