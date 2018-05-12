	/*
	ID: wzhang11
	LANG: JAVA
	TASK: oldmilk2
	*/
	import java.io.*;
	import java.util.*;
	class oldoldmilk2 implements Comparable<oldoldmilk2>{
		int start; 
		int end; 
		
		oldoldmilk2 (int s, int e){
			start = s;
			end = e;
		}
		
	public String toString() {
		return "("+start+","+end+")";
		}
	public int compareTo(oldoldmilk2 other) {
		if(start >other.start) return 1;
		if(start == other.start) return 0;
		return -1;
	}
	
	public static void main (String [] args) throws IOException{
		
		BufferedReader in = new BufferedReader(new FileReader("milk2.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk2.out")));		
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N= Integer.parseInt(st.nextToken()); 

        ArrayList<oldmilk2> aL = new ArrayList<oldmilk2>();
		int s, e; 
		
		for (int i=0; i<N; ++i){
			st = new StringTokenizer(in.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			aL.add(new oldmilk2(s, e)); 
		}

	int lCt = 0, lDt=0, temp, det,k; 
	oldmilk2 a, b, c;
	//sort aL
	Collections.sort(aL);
	//print aL
	for (oldmilk2 p2:aL)
        System.out.println("the item is "  + p2);
	
	// merge the same ones 
	for (int i=0;i<N-1; i++){
		a = aL.get(0);
		b = aL.get(1); 
		if (a.start<= b.start){
			if (b.start<=a.end){
			a = aL.get(0);
			for (k=1;b.start<=a.end&& k< aL.size(); ++k, i++)
			{
				b = aL.get(k);
				if (a.end<b.end)
					aL.add(new oldmilk2 (a.start, b.end));
				else 
					aL.add(new oldmilk2 (a.start, a.end));
				aL.remove(k);
			}
		}
		else {
			aL.remove(0);
			aL.add(a);
		}
		System.out.println ("\ni: "+i);
		}
		else 
			i=N; 
		
	}
	a = aL.get(0);
	aL.remove(0);
	aL.add(a);
	//print aL
	 System.out.println(); 
	for (oldmilk2 p2:aL)
        System.out.println("the item is "  + p2);
	
	out.println(lCt + " " + lDt);
	
	in.close();
	out.close();
	System.exit(0);
	}
	}
	
	
	
	
	
	
	
	