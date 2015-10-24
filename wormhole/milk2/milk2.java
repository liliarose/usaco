	/*
	ID: wzhang11
	LANG: JAVA
	TASK: milk2
	*/
	import java.io.*;
	import java.util.*;

	class milk2 implements Comparable<milk2>{
		int start; 
		int end; 
		
		milk2 (int s, int e){
			start = s;
			end = e;
		}
		
	public String toString() {
		return "("+start+","+end+")";
		}
	public int compareTo(milk2 other) {
		if(start >other.start) return 1;
		if(start == other.start) return 0;
		return -1;
	}
	
	public static void main (String [] args) throws IOException{
		
		BufferedReader in = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));		
		PrintWriter outt = new PrintWriter(new BufferedWriter(new FileWriter("org.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N= Integer.parseInt(st.nextToken()); 

        ArrayList<milk2> aL = new ArrayList<milk2>();
		milk2 a, b;
		int lCt = 0, lDt=0, temp, det=0, s= 0, e=0; 
		
		for (int i=0; i<N; ++i){
			st = new StringTokenizer(in.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			aL.add(new milk2(s, e)); 
		}
	//sort aL
	Collections.sort(aL);
	for(milk2 c:aL){
		outt.println("the item is "  + c);}
	// merge the same ones 
	while(det==0&&aL.size()>1){
		a= aL.get(0);
		aL.remove(0);
		b= aL.get(0);
		if (a.end<b.start){
			aL.add(a);
		}
		else{
			if(a.start>b.start){
				det=1;
				aL.add(a);
			}
			else{
				aL.remove(b);
				s= a.start;
				e= (a.end>b.end)? a.end: b.end;
				b= aL.get(0);
				while(b.start<=e&&det==0&&aL.size()>1){
					if(s>b.start){
							det=1;
					}
					else{
						if (b.end>e)
							e= b.end;
						aL.remove(0);
						b=aL.get(0);
					}}
					if(b.start<=e&&det==0){
						if (b.end>e)
							e= b.end;
						aL.remove(0);
					}
				aL.add(new milk2(s, e));
			}
		}
		
	}
	//print all members
	/*for(milk2 c:aL){
		System.out.println("the item is "  + c);
	}*/
	// lCt
	for(int i=0;i<aL.size();++i){
		a = aL.get(i);
		temp = a.end - a.start; 
		lCt= (temp>lCt)? (temp): (lCt);
		if (temp==912){
			System.out.println(a);
			//(3037,3949)
		}
	}
	// lDt
	for(int i=1;i<aL.size();++i){
		a = aL.get(i-1);
		b = aL.get(i);
		temp = b.start-a.end;
		lDt= (temp>lDt)? (temp): (lDt);
	}
	
	out.println(lCt + " " + lDt);
	
	in.close();
	out.close();
	System.exit(0);
	}
	}
	
	
	
	
	
	
	
	