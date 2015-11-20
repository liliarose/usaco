/*
ID: wzhang11
LANG: JAVA
TASK: combo
*/
import java.util.*;
import java.io.*; 

class combo{
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("combo.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
		
		// Scanner scan = new Scanner(System.in);
		//int N = scan.nextInt();
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		
		if(N < 6){
			out.println(N*N*N);
			in.close();
			out.close();
			System.exit(0);
		}
		int[] M1 = new int[3];
		int[] M2 = new int[3];
		
		st = new StringTokenizer(in.readLine());
		for(int i=0; i<3; ++i){
			M1[i]= Integer.parseInt(st.nextToken());
		}
		
		st = new StringTokenizer(in.readLine());
		for(int i=0; i<3; ++i){
			M2[i]= Integer.parseInt(st.nextToken());
		}
		
		/*M1[0]= scan.nextInt();
		M1[1]= scan.nextInt();
		M1[2]= scan.nextInt();
		M2[0]= scan.nextInt();
		M2[1]= scan.nextInt();
		M2[2]= scan.nextInt();*/
		int[] same = new int[3];
		int d;
		for(int i=0; i<3; ++i){
			if(M1[i] > M2[i])
				d = M1[i]-M2[i];
			else
				d = M2[i]-M1[i];
			if(d < 5)
				same[i] = 5-d;
			else if((N-d) < 5)
				same[i] = 5+d-N;
		}
		out.println(250-same[0]*same[1]*same[2]);
		
		in.close();
        out.close();
      
          
        System.exit(0);  
	}
}