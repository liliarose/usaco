/*
ID: wzhang11
LANG: JAVA
TASK: friday
*/
import java.io.*;
import java.util.*;

class tbeads 
{
	public static void main (String [] args) throws IOException{
        
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tbeads.out")));
		
		String mst= "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
		int L= mst.length();
		for (int i=0;i<L;i++){
			out.println(i+ ": "+mst.charAt(i));	
		}
        out.close();
		}
}