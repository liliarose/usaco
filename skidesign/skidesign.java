/*
ID: wzhang11
LANG: JAVA
TASK: skidesign
*/
import java.io.*;
import java.util.*;

class skidesign 
{   
	public int great(int[] a){
		int g = a[0];
		for(int i=1;i<a.length; i++){
			if(g<a[i])
				g = a[i];
		}
		return g; 
	}
	
	public int least(int[] a){
		int l = a[0];
		for(int i=1; i<a.length;++i){
			if(l>a[i])
				l= a[i];
		}
		return l; 
	}
	
  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("skidesign.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("skidesign.out")));	
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int N= Integer.parseInt(st.nextToken()); 
		int[] H =new int[N];
		int g, cost=0, temp=0; 
		
		for(int i=0; i<N;++i){
			st = new  StringTokenizer(in.readLine());
			H[i] = Integer.parseInt(st.nextToken()); 
		}
		skidesign sd = new skidesign();
		g = sd.great(H)-17;
		//System.out.println(g);
		
		for(int l= sd.least(H); l<g; l++){
			temp =0;
			for(int i=0; i<N; i++){
				if(l>H[i]){
					temp += ((l-H[i])*(l-H[i]));
					//System.out.print("less\t");
					//System.out.println(l+"-"+i+": "+temp+"\tH["+i+"]: "+H[i]);					
				}
				else if(H[i]>l+17){
					temp = ((H[i]-l-17)*(H[i]-l-17))+ temp;
					//System.out.print("greater\t");
					//System.out.println(l+"-"+i+": "+temp+"\tH["+i+"]: "+H[i]);	
				}
				//if(cost!=0&&temp>cost) break;
			}
			//System.out.println(l+"temp: "+temp+"\n");
			if(temp<cost&&cost!=0){
				cost =temp; 
			}
			else if(cost ==0)
				cost = temp;
		}
		out.println(cost);
		out.close();
		in.close();
		System.exit(0);	
		
  }
}












