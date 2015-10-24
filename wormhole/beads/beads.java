		/*
		ID: wzhang11
		LANG: JAVA
		TASK: beads
		*/
		import java.io.*;
		import java.util.*;

	class beads{
		
	public static int[] getNum (int start, String M){
		
		int dead =0, exnum=0, L=M.length(), k;
		char evc= 'w', exchar = 'w';
		int [] AA= {0,0,0};
		
		for (k=0; k<=L && dead==0 ; k++){
			if((k+start)<L)
				exnum=k+start;
			else
				exnum=k+start-L;
			if ((k+start)==L)
				AA[2]=1;
			exchar=M.charAt(exnum);
			
			if (exchar!='w' && exchar!=evc){
				if (evc=='w')
					evc=exchar;
				else 
					dead=1;}
			
			if (exchar==evc)
				AA[0]=exnum+1;
			
			//System.out.println(exnum+": "+exchar);
		}
		//System.out.println("\tk: "+k);
		evc = 'w'; 		 dead=0;		k-=1;
		//System.out.println("\tk: "+k);
		//System.out.println("change\n");
			
		for (; k<=L && dead==0; k++){
			if((k+start)<L)
				exnum=k+start;
			else
				exnum=k+start-L;
			if ((k+start)==L)
				AA[2]=1;
			exchar=M.charAt(exnum);
			//System.out.println(exnum+": "+exchar);
			if (exchar!='w' && exchar!=evc){
				if (evc=='w')
					evc=exchar;
				else 
					dead=1;}	
		}
		if (AA[0]==L)
			AA[0]--;
		AA[1]=k-1; 
		//System.out.println("\t\tAA[0]: "+AA[0]);
		//System.out.println("\t\tAA[1]: "+AA[1]);
		//System.out.println("\t\tAA[2]: "+AA[2]);
		//System.out.println("\n done\n");
		return AA;
	}
	
	public static void main (String [] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("beads.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
		
		StringTokenizer st;
		st = new StringTokenizer(in.readLine());
        int N= Integer.parseInt(st.nextToken()); // read number
		String mst = in.readLine(); // read necklace 
		
		int max=0, start=0, dead= 0; 
		int[] A = new int[3];
		
		while (dead==0){
			A= getNum(start, mst);
			start= A[0];
			dead= A[2];
			//System.out.println("\n\t\tdead: "+dead);
			if (max<A[1]){
				max=A[1];
				//System.out.println("start:"+ before);
			}}
		
			A= getNum(start, mst);
			if (max<A[1]){
				max=A[1];
				//System.out.println("start:"+ before);
			}
				
		
		
		out.println(max);
		in.close();
        out.close();
	}}