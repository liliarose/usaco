/*
ID: wzhang11
LANG: JAVA
TASK: milk
*/
import java.io.*;
import java.util.*;

class milk implements Comparable<milk>
{	
	int price, amount; 
	
	milk(int a, int b){
		price = a; 
		amount = b; 
	}
	
	public String toString() {
		return "("+price+", "+amount+")";
	}
	
	public int compareTo(milk other) {
		if(price >other.price) return 1;
		if(price == other.price) return 0;
		return -1;
	}

  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("milk.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N= Integer.parseInt(st.nextToken()); 
		int M= Integer.parseInt(st.nextToken()); 
		ArrayList<milk> aL = new ArrayList<milk>();
		int total=0, s, e;
		milk a; 
		
		for (int i=0; i<M; ++i){
			st = new StringTokenizer(in.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			aL.add(new milk(s, e)); 
		}
		Collections.sort(aL);
		for (int k =0, i =0; i<M && k<N; ++i){
			a = aL.get(i);
			if((N-k)< a.amount){
				total+= a.price*(N-k);
				k = N; 
			}
			else{
				total+= a.price*a.amount; 
				k+=a.amount; 
			}
		}
		
		out.println(total);		
		in.close();
        out.close();
      
          
          System.exit(0);       
  }
}