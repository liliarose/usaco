import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.*;

public class Ex01 { 

    public class Period implements Comparable<Period> {
        int start;
        int end;

        Period(int start, int end) {
		this.start = start;
		this.end = end;
        }

	public String toString() {
		return "("+start+","+end+")";
	}

	public int r(Period other) {
		if(start >other.start) return 1;
		if(start == other.start) return 0;
		return -1;
	}
    }

    public static void main(String[] args) throws IOException { 
	Ex01 ex1;
        Period p1;
 
        BufferedReader userInput = new BufferedReader 
            (new InputStreamReader(System.in));
 
	ex1 = new Ex01();
        ArrayList<Period> alist = new ArrayList<Period>();

	alist.add(ex1.new Period(1,2));
	alist.add(ex1.new Period(6,8));
	alist.add(ex1.new Period(2,4));
	p1 = ex1.new Period(6,8);
        alist.add(p1);
	p1 = ex1.new Period(2,4);
        alist.add(p1);

        System.out.println("the length:"  + alist.size());

	Iterator<Period> iter = alist.iterator();
	for (Period p2:alist) {
        	System.out.println("the item is "  + p2);
	}

	Collections.sort(alist);

        System.out.println("\nAfter sorting:");
	for (Period p2:alist) {
        	System.out.println("the item is "  + p2);
	}

    } 
} 
