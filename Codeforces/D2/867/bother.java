import java.util.*;
import java.io.*;

public class bother {

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws java.lang.Exception {
        FastScanner sc = new FastScanner();
        int t = sc.nextInt();
        while (t-- > 0) {
            // your code goes here
            int n = sc.nextInt(), a[] = sc.readArray(n);
            Arrays.sort(a);
            long op1 = (long)((long)(a[0]) * (long)(a[1]));
            long op2 = (long)((long)(a[a.length - 2]) * (long)(a[a.length - 1]));
            long op3 = (long)((long)(a[0]) * (long)(a[a.length - 1]));
            System.out.println(Math.max(op1, Math.max(op2, op3)));
        }
    }
}
