import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * p028
 */
public class p028 {
    public static int n;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int m = in.nextInt();


        PriorityQueue<Assignment> math = new PriorityQueue<>();
        PriorityQueue<Assignment> info = new PriorityQueue<>();

        for (int i = 0; i < m; i++)
            math.add(new Assignment(i, in.nextInt()-1, in.nextInt()-1));
        for (int i = 0; i < n-m; i++)
            info.add(new Assignment(i, in.nextInt()-1, in.nextInt()-1));

        int lo = 0;
        int hiBig = n-1;
        
        while (lo < hiBig) {
            int mid = (hiBig+lo)/2;
            if(canDo(mid, math, info)){
                lo = mid;
            } else {
                hiBig = mid - 1;
            }
        }

        lo = 0;
        int hiSmall = n-1;
        while (lo < hiSmall) {
            int mid = (hiBig+lo)/2;
            if(canDo(mid, new PriorityQueue<>(math), new PriorityQueue<>(info))){
                hiSmall = mid;
            } else {
                lo = mid + 1;
            }
        }
    
        System.out.println(hiBig  + " " + hiSmall);

    }

    private static boolean canDo(int mid, PriorityQueue<Assignment> math, PriorityQueue<Assignment> info) {
        int count = 0;
        PriorityQueue<Assignment> all = new PriorityQueue<>(math);
        all.addAll(info);

        for (int day = 0; day < 400; day++) {
            
        }
        return false;
    }

}

class Assignment implements Comparable<Assignment> {
    int id;
    int start;
    int end;
    Assignment(int id, int start, int end) {
        this.id = id;
        this.start = start;
        this.end = end;
    }
    @Override
    public int compareTo(Assignment o) {
        if(o.start == start && o.end == end) return this.id - id;
        if(o.start == start) return this.end - o.end;
        return this.start - o.start;
    }
    @Override
    public String toString() {
        return "{" + id + ": " + start + " ---> " + end + "}";
    }
}