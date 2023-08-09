import java.io.*;
import java.util.*;

public class f {

    private static void solve() {
        int n = in.nextInt();
        long maxWidth = in.nextLong();
        long[] heights = new long[n];
        long[] widths = new long[n];
        for(int i = 0; i < n; i++){
            heights[i] = in.nextInt();
            widths[i] = in.nextInt();
        }   

        long[] memo = new long[n+1];
        Arrays.fill(memo, -1);
        memo[n] = 0;
        for(int at = n-1; at >= 0; at--){
            long minn = (long)1e18;
            long maxHeight = 0;
            long w = 0;
            for(int i = at; i < n; i++){
                maxHeight = Math.max(heights[i], maxHeight);
                w += widths[i];
                if(w > maxWidth) break;
                minn = Math.min(minn, memo[i+1] + maxHeight);
            }
            memo[at] = minn;
        }
        out.println(memo[0]);
    }
    
    public static FastScanner in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.flush();
        out.close();
    }
}

class FastScanner {
    BufferedReader br; StringTokenizer st;
    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        update();
    }
    public FastScanner(File in) {
        try {br = new BufferedReader(new FileReader(in));}
        catch (FileNotFoundException e) {e.printStackTrace();}
        update();
    }
    public void update(){
        try {st = new StringTokenizer(br.readLine());} 
        catch (Exception e){e.printStackTrace();}
    }
    public String next() {
        if (st.hasMoreTokens()) return st.nextToken();
        update();
        return st.nextToken();
    }
    public int nextInt() {return Integer.parseInt(next());}
    public long nextLong() {return Long.parseLong(next());}
    public double nextDouble() {return Double.parseDouble(next());}
}