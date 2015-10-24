/*
ID: wzhang11
LANG: JAVA
TASK: barn1
*/
import java.io.*;
import java.util.*;

class barn1 
{	

  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("barn1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
		// hello
		StringTokenizer st = new StringTokenizer(in.readLine());
		int M= Integer.parseInt(st.nextToken()); 
		int S= Integer.parseInt(st.nextToken()); 
		int C= Integer.parseInt(st.nextToken()); 
		
		
		if(M>=C){
			out.println(C);
		}
		else{
			int c, d, rem; 
			int[] aL = new int[C];
			barn1 a, b; 
			
			int[] dif = new int[M-1];
			// read numbers in 
			for (int i=0; i<C; ++i){
				st = new StringTokenizer(in.readLine());
				aL[i] = Integer.parseInt(st.nextToken());
			}
			// sort
			Arrays.sort(aL);
			// set to 0
			for(int i=0; i<M-1; ++i)
				dif[i]=0;

			// find greatest differences 		
			for(int i=(C-1); i>0; --i){
				c = aL[i]- aL[i-1]; 
				//System.out.println(c); 
				d =0; rem =M;
				for(int k =0; k<M-1 ; ++k){
					if(d<(c-dif[k])){
						rem = k; 
						d = c-dif[k];
					}
				}
				if(rem<M-1){
					dif[rem]= c;  
				}
			}
			
			// find total difference
			int tdif=-M; 
			
			for(int i=0; i<M-1; ++i){
				tdif+= dif[i];
				//System.out.println(i+ ": "+ dif[i]);
			}
			// print out #
			out.println(aL[C-1]-aL[0]-tdif);
		}
		
          
        out.close();
		in.close();
		System.exit(0);       
  }
}