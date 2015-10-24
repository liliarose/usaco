/*
ID: wzhang11
LANG: JAVA
TASK: namenum
*/
import java.io.*;
import java.util.*;

class namenum 
{	
	public int pow(int a, int b){
		int k=1;
		for(int i = 0; i<b; ++i){
			k*=a;
		}
		return k; 
	}
	
	public long decode(String str){
		char a;
		long ret=0; 
		for(int i=0; i<str.length();i++){
			a = str.charAt(i);
			if(a>='A'&&a<='C')
				ret=ret*10+2;
			if(a>='D'&&a<='F')
				ret=ret*10+3;
			if(a>='G'&&a<='I')
				ret=ret*10+4;
			if(a>='J'&&a<='L')
				ret=ret*10+5;
			if(a>='M'&&a<='O')
				ret=ret*10+6;
			if(a>='P'&&a<='S')
				ret=ret*10+7;
			if(a>='T'&&a<='V')
				ret=ret*10+8;
			if(a>='W'&&a<='Y')
				ret=ret*10+9;
			if(a=='Z'||a=='Q')
				return 0;
		}
		return ret;
	}
	

  public static void main (String [] args) throws IOException
  {
          BufferedReader read = new BufferedReader(new FileReader("namenum.in"));
          PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
          String temp = read.readLine();
		  long N,num;
		  int count=0, check=0; 		namenum nn = new namenum();
		  if(temp.length()<10){
			StringTokenizer st = new StringTokenizer(temp);
		    N= Integer.parseInt(st.nextToken()); 
		  }
		  else{
			  String sub = temp.substring(0,8);
			  StringTokenizer st = new StringTokenizer(sub);
			  N = Integer.parseInt(st.nextToken()); 
			  sub = temp.substring(8, temp.length());
			  StringTokenizer s = new StringTokenizer(sub);
			  num = Integer.parseInt(s.nextToken()); 
			  for(long t1= num;t1!=0; count++){
					t1/=10;
			  }
			  N= N*(nn.pow(10,count))+num; 
		  }

		  count =0; 
		  for(long t1= N;t1!=0; count++){
			  t1/=10;
		  }
		 BufferedReader r = new BufferedReader(new FileReader("dict.txt"));
		 
		 for(int i =0; i<4531;++i){
			temp = r.readLine();
			if(temp.length()==count){
				num=nn.decode(temp);	
				if(num==N){
					out.println(temp);
					++check;
				}
			}
		 }
		 if(check==0){
			 out.println("NONE");
		 }
		 
		  r.close();
		  read.close();
          out.close();
      
          
          System.exit(0);       
  }
}