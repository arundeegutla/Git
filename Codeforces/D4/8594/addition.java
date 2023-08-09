import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class addition {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        loop:while (numCases-->0) {
            int numVal = in.nextInt();
            int[] vals = new int[numVal];
            for (int i = 0; i < vals.length; i++)
                vals[i] = in.nextInt();
            Arrays.sort(vals);

            // System.out.println(Arrays.toString(vals));
            long a = 1;
            for (int i = 0; i < vals.length; i++) {
                // System.out.println(a + " " + vals[i]);
                if (vals[i] > a) {
                    System.out.println("no");
                    continue loop;
                }
                if (i!=0) {
                    a += vals[i];   
                }
            }

            System.out.println("yes");
        }
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
    