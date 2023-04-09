import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class interview {
    public static FastScanner in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new FastScanner();
        out = new PrintWriter(System.out);

        int numCases = in.nextInt();
        while (numCases-->0) {
            int len = in.nextInt();
            long[] preSum = new long[len + 1];
            
            for (int i = 1; i <= len; i++)
                preSum[i] = preSum[i-1] + in.nextInt();

            int index = binSearch(1, len, preSum);
            
            out.println("! " + index);
            out.flush();
        }

    }

    private static int binSearch(int start, int end, long[] preSum) {
        if (start == end) 
            return start;

        int mid = (start+end)/2;
        int sumLeft = getActualSum(start, mid);

        if (sumLeft > preSum[mid] - preSum[start - 1])
            return binSearch(start, mid, preSum);
        return binSearch(mid+1, end, preSum);
    }

    private static int getActualSum(int start, int end) {
        StringBuilder str = new StringBuilder("? " + (end - start + 1));
        for (int i = start; i <= end; i++)
            str.append(" " + i);
        out.println(str);
        out.flush();
        return in.nextInt();
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
    