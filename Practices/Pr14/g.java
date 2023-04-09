import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * g
 */
public class g {

    public static void main(String[] args) {
        FastScanner in = new FastScanner();

        HashMap<String, Integer> map = new HashMap<>();
        BigInteger x = BigInteger.ONE;
        for (int i = 1; i <= 100; i++) {
            x = x.multiply(new BigInteger(String.valueOf(i)));
            map.put(String.valueOf(x), i);
        }

        String str = in.nextLine();

        if(map.containsKey(str)) {
            System.out.println(map.get(str));
            return;
        }

        int length = str.length();
        int n = 1;
        double log10 = Math.log10(n);
        while (Math.floor(log10) + 1 < length) {
            n++;
            log10 += Math.log10(n);
        }

        System.out.println(n);

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