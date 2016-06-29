/*
ID: wzhang11
LANG: JAVA
TASK: ride 
*/
import java.io.*;
import java.util.*;

class ride {

  public static int ModVal (String str)
  {
      int v=1;
      int len = 
      
      for (int i=0;i<len;++i)
      {
          char c= str.charAt(i); 
          
          if (c<'A'||c>'Z')
          {
              System.out.println("invalid character = |"+c +"|");
              break;
          }
          v *= ((int)c-(int)'A')+1; 
      }
      
      v %= 47;
      return v; 
  }
  
  public static void main (String [] args) throws IOException {

    BufferedReader in = new BufferedReader(new FileReader("ride.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
    int[] val= new int[2];
    
    for (int i=0; i<2; ++i)
    {
        String line;
        if ((line= in.readLine())==null)
        {
            System.out.println("null line");
            System.exit(0); 
        }
        val[i]=ride.ModVal(line);
    }
    
    if (val[0]==val[1])
        out.println("GO");
    else 
        out.println("STAY"); 
    
    in.close();
    out.close();
  }
}