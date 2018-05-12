/*
ID: wzhang11
LANG: JAVA
TASK: palsquare
*/
import java.io.*;
import java.util.*;

class palsquare 
{	
	public StringBuffer cvBase (int num, int bn){
		String d = "0123456789ABCDEFGHIJ";
		StringBuffer cv = new StringBuffer();
		int c; 
		
		while(num!=0){
			c= num%bn; 
			cv.insert(0, d.charAt(c));
			num/=bn; 
		}
		
		
		return cv;
	}
	
	public boolean isPd(StringBuffer cvd){
		int i = 0;
		int j = cvd.length()-1;
		while(j>i) {
				if(cvd.charAt(i)!= cvd.charAt(j)) return false;
				j--;i++;
		}
		return true;
	}

  public static void main (String [] args) throws IOException
  {
          BufferedReader in = new BufferedReader(new FileReader("palsquare.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		  int N= Integer.parseInt(st.nextToken()); 

		// char[] d = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 
		//	'D', 'E', 'F', 'G', 'H', 'I', 'J'};
		palsquare p= new palsquare();
		boolean det; 
		for(int i=1; i<301; ++i){
			 
			det = p.isPd(p.cvBase(i*i, N));
			if(det== true)
				out.println(p.cvBase(i, N)+" "+ p.cvBase(i*i, N));
		 }

		  in.close();
          out.close();
      
          
          System.exit(0);       
  }
}