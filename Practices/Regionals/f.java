import java.util.*;
import java.io.*;

public class f {
    public static long[][] memo;
    public static int[] mess;
    public static int[] clean;
    public static boolean[] parents;


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numDays = in.nextInt();
        int numParents = in.nextInt();

        mess = new int[numDays];
        clean = new int[numDays];
        parents = new boolean[numDays];
        
        for (int i = 0; i < mess.length; i++) {
            mess[i] = in.nextInt();
            clean[i] = in.nextInt();
        }

        for (int i = 0; i < numParents; i++)
            parents[in.nextInt() - 1] = true;
        
        memo = new long[numDays + 1][numDays + 1];
        for (long[] oned : memo)
            Arrays.fill(oned, -1);

        for (int i = 0; i <= numDays; i++) {
            long ans = getMin(numDays-1, i);
            if(ans <= (long)1e9) {   
                System.out.println(i);
                return;
            }
        }

        System.out.println(-1);
    }

    private static long getMin(int at, int numCleans) {
        
        if (numCleans < 0)
            return (long)1e10;

        if(at == -1)
            return 0;
    
        if (memo[at][numCleans] != -1)
            return memo[at][numCleans];
    
        long didnt = Math.max(0, getMin(at-1, numCleans) + mess[at]);
        long did = Math.max(0, getMin(at-1, numCleans-1) +  mess[at] - clean[at]);

        if (parents[at])
            if (did!=0 && didnt!=0)
                return memo[at][numCleans] = (long)1e10;
    
        return memo[at][numCleans] = Math.min(did, didnt);
    }
}