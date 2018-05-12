/*
ID: wzhang11
LANG: JAVA
TASK: dualpal
*/
import java.io.*;
import java.util.*;

class dualpal 
{	
	public StringBuffer cvBase (int num, int bn){
		StringBuffer cv = new StringBuffer();
		int c; 
		
		while(num!=0){
			c= num%bn; 
			cv.insert(0, c);
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
        BufferedReader in = new BufferedReader(new FileReader("dualpal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N= Integer.parseInt(st.nextToken()); 
		int S= Integer.parseInt(st.nextToken()); 
		
		dualpal dp = new dualpal();
		int count; 
		for(int i = 0, num =S+1; i<N; ++num){
			count=0;
			
			if(dp.isPd(dp.cvBase(num, 2)))
				count++;
			if(dp.isPd(dp.cvBase(num, 3)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 4)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 5)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 6)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 7)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 8)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 9)))
				count++;
			if(count<2 && dp.isPd(dp.cvBase(num, 10)))
				count++;
			
			if(count==2){
				out.println(num); 
				i++;
			}
				
		}
		

		  in.close();
          out.close();
      
          
          System.exit(0);       
  }
}