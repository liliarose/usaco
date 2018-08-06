/*
ID: your_id_here
LANG: JAVA
TASK: gift1
*/
import java.io.*;
import java.util.*;

class gift1 {
  public static int getIndex(String key, String names[]){
    int i;
    for(i = 0; i < names.length && !names[i].equals(key); i++){}
    return i;
  }
  public static void main (String [] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("gift1.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
    StringTokenizer st = new StringTokenizer(in.readLine());
    int N = Integer.parseInt(st.nextToken());
    System.out.println(N);
    String[] names = new String[N];
    int [] bank = new int [N];

    for(int i = 0; i < N; i++){
        names[i] = in.readLine();
        bank[i] = 0;
    }
    
    String tmp;

    for(int i = 0; i < N; i++){
        tmp = in.readLine();
        st = new StringTokenizer(in.readLine());
        int tot = Integer.parseInt(st.nextToken()), gifted = Integer.parseInt(st.nextToken()), am;
        if(gifted != 0) am = tot/gifted;
        else am = 0;
        bank[getIndex(tmp, names)] += tot%gifted - tot;
        for(int j = 0; j < gifted; j++){
            tmp = in.readLine();
            bank[getIndex(tmp, names)] += am;
        }
    }
    
    for(int i = 0; i < N; i++){
        
    }

    in.close();
    out.close();                                  // close the output file
  }
}
