import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Inet4Address;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class tea {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        
        StringBuilder str = new StringBuilder();
        while(numCases--> 0)
        {
            int numTotal = in.nextInt();
            int[] amount = new int[numTotal];
            int[] tasters = new int[numTotal];
            int[] munchers = new int[numTotal];
            long[] totals = new long[numTotal];

            for (int i = 0; i < numTotal; i++)
                amount[i] = in.nextInt();

            for (int i = 0; i < numTotal; i++)
                tasters[i] = in.nextInt();

            int index = numTotal - 1;
            for (int i = numTotal - 1; i >= 0; i--) {
                if (tasters[index] <= tasters[i])
                    index = i;
                munchers[i] = index;
            }

            System.out.println(Arrays.toString(munchers));

            // for (int i = 0; i < numTotal; i++) {
            //     totals[i] = 0;
            //     for (int j = i; j >= 0; j--) {
            //         totals[i] += Math.min(tasters[i], amount[j]);
            //         amount[j] -= Math.min(tasters[i], amount[j]);
            //     }
            // }
            // for (int i = 0; i < numTotal; i++) {
            //     str.append(totals[i] + (i == numTotal - 1 ? "\n" : " "));
            // }
        }
        System.out.print(str);
    }
}

class FastScanner {
    BufferedReader br; StringTokenizer st;
            public FastScanner() {
                try {
                    br = new BufferedReader(new InputStreamReader(System.in));
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e){e.printStackTrace();}
            }
            public String next() {
                if (st.hasMoreTokens()) return st.nextToken();
                try {st = new StringTokenizer(br.readLine());}
                catch (Exception e) {e.printStackTrace();}
                return st.nextToken();
            }
            public short nextShort() {return Short.parseShort(next());}
            public int nextInt() {return Integer.parseInt(next());}
            public long nextLong() {return Long.parseLong(next());}
            public double nextDouble() {return Double.parseDouble(next());}
            public String nextLine() {
                String line = "";
                if(st.hasMoreTokens()) 
    line = st.nextToken();
                else 
    try {return br.readLine();}catch(IOException e){e.printStackTrace();}
                while(st.hasMoreTokens()) line += " "+st.nextToken();
                return line;
            }
    }
    