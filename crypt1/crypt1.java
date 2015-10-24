/*
ID: wzhang11
LANG: JAVA
TASK: crypt1
*/
import java.io.*;
import java.util.*;

class crypt1 
{   
	public boolean snum(int[] bb, int a){
		int remain=0, det; 
		//System.out.println(a/10);
		while(a!=0){
			det=0;
			remain=a%10; 
			a/=10;
			//
			for(int i=0;i<bb.length;i++){
				if(bb[i]==remain){
					det=1;
					break;
				//System.out.println("i: "+i);
				}
			}
			if(det!=1){
				//System.out.println("a: "+a+"\tc: "+ remain);
				return false;
			}
		}
		//System.out.println("true");
		return true; 
	}


  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("crypt1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crypt1.out")));
 	    crypt1 cyp = new crypt1();		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N= Integer.parseInt(st.nextToken()); 
		st = new StringTokenizer(in.readLine());
		
		int[] cnum = new int[N]; 
		for(int i=0; i<N; i++){
			cnum[i]=Integer.parseInt(st.nextToken());
			//System.out.println(cnum[i]);
		}
		Arrays.sort(cnum);
		
		int abc, pp1, pp2, sum=0, total; 

		for(int h=0;h<N;h++){
			for(int t=0;t<N;t++){
				for(int n=0;n<N;n++){
					abc=cnum[h]*100+cnum[t]*10+cnum[n]; 
					for(int t2=0; t2<N;t2++){
						pp1=abc*cnum[t2];
						if(pp1>=1000) {
							break; 
						}else if (cyp.snum(cnum, pp1)==false){
							continue;
						}
						for(int n2=0; n2<N; n2++){
							pp2=abc*cnum[n2]; 
							if(pp2>=1000)
								break;
							else if(cyp.snum(cnum, pp2)==true){
								total =pp1*10+pp2;
								if(total<10000&&cyp.snum(cnum,total)==true){
									sum++;
								}
							}
						}
					}
				}
				
			}
		}
		
		
	    out.println(sum);
        in.close();
        out.close();
      
          
        System.exit(0);       
  }
}