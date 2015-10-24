/*
ID: wzhang11
LANG: JAVA
TASK: friday
*/

import java.io.*;
import java.util.*;

class friday1 
{
	int [] month= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	public static int f13(int day){
		day-=2;
		if(day<0)
			day=7+day;
		return day; 
	}
	
	public static int fld (int mt, int fday, int yr){
		int m; 
		if (mt!=1)
			m= month[mt];
		elseif (yr%4==0){
			if (yr%100!=0)
				m= month[mt]+1;
			elseif (yr%400==0)	{m= month[mt]+1;}
		}
		else 
			m= month[mt];
		
		if (m==28)
			return fday; 
		if (m==29)
			fday++;
		if (m==30)
			fday+=2; 
		if (m==31)
			fday+=3;
		if (fday>6)
			fday-=7;
		
		return fday;
	}
	
  public static void main (String [] args) throws IOException{
	  
	int N, day=1,d13;
	int [] dwks= {0, 0, 0, 0, 0, 0, 0}; 
        BufferedReader in = new BufferedReader(new FileReader("friday.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
		  
		StringTokenizer st;
		st = new StringTokenizer(in.readLine());
        N= Integer.parseInt(st.nextToken());
		System.out.println(N);
	
		//years circulation
		for (int i= 0; i<N; ++i){
			//months circulation
			for (int k=0;k<12;++k){
				d13= f13 (day);
				day= fld (k, day, i);
			}
		}
		
		for ( int i=0; i<dwks.length; i++ ){
            out.print( dwks[i]+" "); 
		}
	
        in.close();
        out.close();
  }
}

/*
January 1, 1900 was on a Monday.
Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800,
1900 and 2100 are not leap years, but 2000 is a leap year.
 
PROGRAM NAME: friday

INPUT FORMAT

One line with the integer N.
SAMPLE INPUT (file friday.in)

20
OUTPUT FORMAT

Seven space separated integers on one line. These integers represent the number of times the 13th falls on Saturday, Sunday, Monday, 
Tuesday, ..., Friday.
SAMPLE OUTPUT (file friday.out)

36 33 34 33 35 35 34
*/