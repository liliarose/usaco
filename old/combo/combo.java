/*
ID: wzhang11
LANG: JAVA
TASK: combo
*/
import java.io.*;
import java.util.*;

class combo 
{   
	public int isOverlap(int a, int b, int N){
		int d;
		if(a>b)
				d= a-b; 
			else
				d= b-a; 
		if(N>9){
			if((5-d)>0)
				return 5-d;
			else{
				if((5-N+d)>0)
					return (5-N+d);
			}
		}
		else if(N>5){
			int sum=0;
			if(5-d>0)
				sum+=(5-d);
			if((5-N+d)>0)
				sum+=(5-N+d);
			return sum; 
		}
		else if(N>0){
			return N; 
		}
		return 0; 
		
	}

  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("combo.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
		combo cb = new combo(); 
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int[] a= new int[3]; 
		int[] b= new int[3];  
		st = new StringTokenizer(in.readLine());
		for(int i=0; i<3; ++i){
			a[i]= Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(in.readLine());
		for(int i=0; i<3; ++i){
			b[i]= Integer.parseInt(st.nextToken());
		}
		int [] same = new int[3];
		for(int i=0; i<3;++i){
			same[i]=cb.isOverlap(a[i], b[i], N); 
			//System.out.println(a[i]+" "+ b[i]+" "+same[i]);
		}
		
		if(N>5){
			out.println((250-same[0]*same[1]*same[2]));
		}
		else{
			out.println((N*N*N));
		}
		
		
        in.close();
        out.close();
      
          
        System.exit(0);       
  }
}