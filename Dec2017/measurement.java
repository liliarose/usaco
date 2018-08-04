/*
ID: wenxzha1 
LANG: JAVA
TASK: measurement
*/
import java.io.*;
import java.util.*;

class measurement {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("measurement.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    int N = Integer.parseInt(st.nextToken());    // first integer
    int XSystem.out.println(i1);
    int i2 = Integer.parseInt(st.nextToken());    // second integer
    
    out.close();                                  // close the output file
  }
}
