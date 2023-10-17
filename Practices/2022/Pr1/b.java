import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * b
 */
public class b {

    public static void main(String[] args) {
        FastScanner in = new FastScanner();

        int cases = in.nextInt();

        while (cases-- > 0) {
            int R = in.nextInt();
            int sides = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();
            int w = in.nextInt();

            

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
        if (st.hasMoreTokens())	return st.nextToken();
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
        if(st.hasMoreTokens()) line = st.nextToken();
        else try {return br.readLine();}catch(IOException e){e.printStackTrace();}
        while(st.hasMoreTokens()) line += " "+st.nextToken();
        return line;
    }
}