import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class perm {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        while (numCases-->0) {

            int n = in.nextInt();
            int c = in.nextInt();
            int d = in.nextInt();

            HashSet<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++)
                set.add(in.nextInt());
            Arrays.sort(array);

            int at = 1;
            long total = 0;
            for (int i = 0; i < array.length; i++) {
                if (array[i] > at) {
                    if ((n-i) * c <= d) {
                        total += (n-i) * c;
                        break;
                    } else {
                        total += d;
                    }
                } else if (array[i] < at) {
                    if ((n-i) * c <= c + d) {
                        total += (n-i) * c;
                        break;
                    } else {
                        total += c + d;
                    }
                }
            }

            System.out.println(total);
            
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
    