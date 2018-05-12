/*
ID: wzhang11
LANG: JAVA
TASK: milk
*/
import java.io.*;
import java.util.*;

class test
{	
	

  public static void main (String [] args) throws IOException
  {
    for(int i=0; i<10;i++){
		System.out.println("i: "+i); 
		for(int k=0; k<10; k++){
			if(k>5){
				System.out.println();
				break;
			}
			System.out.println("k: "+k); 
			for(int j=0; j<2; k++){
				System.out.println("j: "+j); 
			}
		}
	}
	
  }
}