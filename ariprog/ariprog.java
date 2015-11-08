/*
ID: wzhang11
LANG: JAVA
TASK: ariprog
*/
import java.io.*;
import java.util.*;

class ariprog 
{  	//search 
	public boolean binarySearch (int[] ary, int key, int low){
		int high = ary.length-1; 
		int mid;
		int size = ary.length;
		while(high >= low ){
			mid = (low+high)/2; 
			//System.out.println("["+mid+"]: "+ary[mid]);
			//System.out.println("low: "+ low+ "\thigh: "+ high);
			if(ary[mid] == key)
				return true; 
			else if(ary[mid] > key)
				high = mid -1; 
			else 
				low = mid +1; 
				
		}
		return false; 
	}
	
  public static void main (String [] args) throws IOException
  {
        BufferedReader in = new BufferedReader(new FileReader("ariprog.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));	
		// scan in #s, N, M
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken()); 	
		st = new StringTokenizer(in.readLine());
		int M = Integer.parseInt(st.nextToken())+1; 
	//squares array
		int[] squareList ={0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256,
		289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 
		1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304,
		2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969,
		4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084,
		6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649,
			8836, 9025, 9216, 9409, 9604, 9801, 10000, 10201, 10404, 10609, 10816, 11025, 11236, 
			11449, 11664, 11881, 12100, 12321, 12544, 12769, 12996, 13225, 13456, 13689, 13924, 
			14161, 14400, 14641, 14884, 15129, 15376, 15625, 15876, 16129, 16384, 16641, 16900, 
			17161, 17424, 17689, 17956, 18225, 18496, 18769, 19044, 19321, 19600, 19881, 20164, 
			20449, 20736, 21025, 21316, 21609, 21904, 22201, 22500, 22801, 23104, 23409, 23716, 
			24025, 24336, 24649, 24964, 25281, 25600, 25921, 26244, 26569, 26896, 27225, 27556, 
			27889, 28224, 28561, 28900, 29241, 29584, 29929, 30276, 30625, 30976, 31329, 31684, 
			32041, 32400, 32761, 33124, 33489, 33856, 34225, 34596, 34969, 35344, 35721, 36100, 
			36481, 36864, 37249, 37636, 38025, 38416, 38809, 39204, 39601, 40000, 40401, 40804,
			41209, 41616, 42025, 42436, 42849, 43264, 43681, 44100, 44521, 44944, 45369, 45796,
			46225, 46656, 47089, 47524, 47961, 48400, 48841, 49284, 49729, 50176, 50625, 51076,
			51529, 51984, 52441, 52900, 53361, 53824, 54289, 54756, 55225, 55696, 56169, 56644,
			57121, 57600, 58081, 58564, 59049, 59536, 60025, 60516, 61009, 61504, 62001, 62500}; 
		// determine bisquare array size 
					int size; 
		if(M%2==0)
			 size = (M/2)*(M+1);
		else
			 size = ((M+1)*(M/2)+M/2+1); 
		int[] bisquare = new int[size];
		for(int i = 0, count = 0; i < M; i++){
			for(int k = i; k < M; k++, count++){
				bisquare[count] = squareList[i]+ squareList[k];
			}
		}
		Arrays.sort(bisquare);
		boolean any = false;
			ariprog ap = new ariprog();
		
		int MAX = (bisquare[size-1]/(N-1));
		for(int b = 1, max, i, a, temp = -1; b <= MAX; b++){
			max = bisquare[size-1] - b*(N-1);
			for(int j = 0; bisquare[j] <=max ; j++){
				if(temp == bisquare[j])
					continue; 
				a = bisquare[j];
				temp = bisquare[j];
				for(i = 1; i < N ; i++){
					if(!(ap.binarySearch(bisquare, a+b*i, (j+i))))
						break; 
				}
				if(i == N){
					out.println(a + " " + b);
					any = true; 
				}
			}
		}
	
		if(!any)
			out.println("NONE");
		in.close();
		out.close();
		System.exit(0);	
		
  }
}



/*		for(int i=0, a; i<1;i++){
			a = bisquare[i];
			for(int k = i+1, b; k<4; k++){
				b = bisquare[k]-a;			
				int j; 
				for(j = 2 ; j<N ; j++){
					// search if in bisquare array 
					//System.out.println(a+" "+ b);
					if(ap.binarySearch(bisquare, a+j*b, k))
						break;
				}
				System.out.println("out"+i);
				if(j==N){
					out.println(bisquare[a]+" "+b);
					any = true; 
				}
			}
		}	*/
		
		
		
		
		//醉後決定愛上你
		