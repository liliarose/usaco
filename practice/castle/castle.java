/*
ID: wzhang11
LANG: JAVA
TASK: castle
*/
import java.io.*;
import java.util.*;

class castle {
	int M, N; 
	int[][] flag; 
	boolean[][][] castle;
	int sizecount; 
	int roomNum = 0; 
	int max = 0; 
	int nMax = 0;
	int rmI, rmJ, rmK;
	int count = 1; 
	castle(int i, int j){
		flag = new int[i][j]; 
		castle = new boolean[i][j][4]; 
		i = N; 
		j = M;
	}
	void checkMax(){
		if(sizecount > max){ max = sizecount; }
	}
	void checkNMax(int i, int j, int k){
		if(sizecount > nMax) {
			nMax = sizecount; 
			rmI = i + 1; 
			rmJ = j + 1;
			rmK = k;
		}
	}
	
	void storeIJK(int i, int j, int k){
		
	}
		void searchRoom(int i, int j){
			if(flag[i][j] != count){
				sizecount++;
				flag[i][j] = count;
				int k = 0;
				//west
				if(castle[i][j][k]){
					searchRoom(i, j-1);
				}k++;
				//north
				if(castle[i][j][k]){
					searchRoom(i-1, j);
				}k++;
				//east
				if(castle[i][j][k]){
					searchRoom(i, j+1);
				}k++;
				//south
				if(castle[i][j][k]){
					searchRoom(i+1, j);
				}
			}
		}
	
	public static void main (String [] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("castle.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));
		StringTokenizer st;
		st = new StringTokenizer(in.readLine());
        int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken()); 
		castle ct = new castle( N, M);
		
		for(int i = 0, temp; i < N; i++){
			st = new StringTokenizer(in.readLine());
			for(int j = 0; j < M; j++){
				temp = Integer.parseInt(st.nextToken());
				for(int k = 0; k < 4; k++){
					if(temp%2 == 0){
						ct.castle[i][j][k] = true; //open
					}
					temp /= 2;
					//out.println("castle["+ i + "][" + j + "][" + k + "]: " + ct.castle[i][j][k]);
				}
				//out.println();
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(ct.flag[i][j] == 0){
					ct.sizecount = 0; 
					ct.searchRoom(i, j); 
					ct.checkMax();
					ct.roomNum++;
				}
			}
		}
		for(int j = 0; j < M; j++){
			for(int i = N-1; i > -1; i--){
				for(int k = 1; k < 3; k++){
					if((k == 1 && i == 0) || (k == 2 && j == M-1)){
						continue;}
					if(!ct.castle[i][j][k]){
						ct.castle[i][j][k] = true;
						ct.count++; 
						ct.sizecount = 0;
						ct.searchRoom(i, j);
						ct.checkNMax(i, j, k);
						ct.castle[i][j][k] = false;
					}
				}
			}
		}
		
		
		
		//System.out.println("roomNum: " + ct.roomNum + " Max: " + ct.max + " nMax: " + ct.nMax);
		//System.out.println("remove: " + ct.rmI + " " + ct.rmJ + " " + ct.rmK);
		out.println(ct.roomNum);
		out.println(ct.max);
		out.println(ct.nMax);
		out.print(ct.rmI + " " + ct.rmJ);
		if(ct.rmK == 1){
			out.println(" N");
		}
		else{
			out.println(" E");
		}
		
		out.close();
		in.close();
		System.exit(0);
	}
}	