/*
ID: wzhang11
LANG: JAVA
TASK: gift1
*/
import java.io.*;
import java.util.*;

class gift1 
{ll
    public static int getIndex (String a, String[] names)
    {
        for(int j= 0;!(names[j].equals(a));j++)
        {}
        return j;}

  public static void main (String [] args) throws IOException
  {
          BufferedReader read = new BufferedReader(new FileReader("gift1.in"));
          PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
          
          int A=0, B=0, C=0, index=0, index1=0, NP=0;
          int count=0;
          String N;
          
          
          StringTokenizer st;
          st = new StringTokenizer(read.readLine());
          NP= Integer.parseInt(st.nextToken());
          
          String[] names= new String[NP];
          int[] intial= new int[NP];
          int[] finals = new int [NP];
          
          for ( int j=0; j<finals.length; j++ )
              finals[j]=0;
          
          for (int i=0; i<NP; ++i)
          {names[i]=read.readLine();}
          //loop 
          while(count<NP)
          {
              
          N= read.readLine();
          index= gift1.getIndex(N, names);
          
          st = new StringTokenizer(read.readLine());
          A= Integer.parseInt(st.nextToken());
          //put into original 
          intial[index]=A;
          B= Integer.parseInt(st.nextToken());
         
          if (B!=0)
          {
              C= A/B; 
			finals[index]+=A%B; 
          
            for(int j=0; j<B; ++j)
            {
                N=read.readLine();
                index1= gift1.getIndex(N,names);
                finals[index1]+=C;
            }
          }
				count++;
          }
          
		 for ( int j=0; j<names.length; j++ )
       {
            out.println( names[j]+" "+(finals[j]-intial[j])); 
       }
	   
        read.close();
        out.close();
      
          
          System.exit(0);       
  }
}