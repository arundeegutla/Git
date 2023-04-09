// Fastscanner + Stringbuilder + Coordinate Compressor

import java.io.*;
import java.util.*;

public class h {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numFields = in.nextInt();
        int numQueries = in.nextInt();
        int[] fields = new int[numFields];

        int k = 0;
        HashMap<Double, Integer> mapping = new HashMap<>();
        for (int i = 0; i < fields.length; i++)
        {
            double num = in.nextDouble();
            if (!mapping.containsKey(num))
                mapping.put(num, k++);
            fields[i] = mapping.get(num);
        }
                    

        StringBuilder ret = new StringBuilder();

        loop : while (numQueries-- > 0) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            int min = (int)Math.floor((right - left + 1)/2) + 1;
            int[] arr = new int[10000];
            for (int i = left; i <= right; i++) {
                if (++arr[fields[i]] >= min) {
                    ret.append("usable\n");
                    continue loop;
                }
            }
            ret.append("unusable\n");
        }
        System.out.print(ret);
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