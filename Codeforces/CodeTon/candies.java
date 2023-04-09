import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class candies {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        while (numCases-->0) {
            int n = in.nextInt();
            if (n % 2 == 0) {
                System.out.println(-1);
                continue;
            }
            int count = 0;
            StringBuilder str = new StringBuilder();

            while (n != 1) {
                if (((n+1)/2) % 2 != 0) {
                    str.insert(0, 1 + " ");
                    n = (n+1)/2;
                    count++;
                } else if (((n-1)/2) % 2 != 0){
                    str.insert(0, 2 + " ");
                    n = (n-1)/2;
                    count++;
                }
            }

            if (n == 1 && count <= 40) {
                System.out.println(count);
                System.out.println(str);
            } else {
                System.out.println(-1);
            }

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
    