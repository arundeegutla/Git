import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class trainaddiction {

    static int MOD = (int) 1e9 + 7;
    public static void main(String[] args) {
        FastScanner s = new FastScanner();
        PrintWriter pw = new PrintWriter(System.out);
        int t = s.nextInt();
        while (t-- > 0) {
            int n = s.nextInt(), k = s.nextInt();
            long[] arr = new long[k], freq = new long[51];
            for (int i = 0; i < k; i++) {
                arr[i] = s.nextInt();
                freq[(int) arr[i]]++;
            }
            int[] dp = new int[n + 1];
            for (int i = 0; i < k; i++) {
                if (arr[i] <= n) dp[(int) arr[i]] = 1;
            }
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < k; j++) {
                    if (i + arr[j] <= n) {
                        dp[(int) (i + arr[j])] += dp[i];
                        dp[(int) (i + arr[j])] %= MOD;
                    }
                }
            }
            for (int i = 0; i < 51; i++) {
                if (freq[i] != 0) {
                    dp[n] *= freq[i];
                    dp[n] %= MOD;
                }
            }
            pw.println(dp[n] == 0 ? "IMPOSSIBLE" : dp[n]);
        }
        pw.flush();
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							Fast Scanner								*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
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
        if(st.hasMoreTokens()) line = st.nextToken();
        else try {return br.readLine();}catch(IOException e){e.printStackTrace();}
        while(st.hasMoreTokens()) line += " "+st.nextToken();
        return line;
    }
    public int[] nextIntArray(int n){
        int[] array=new int[n];
        for(int i=0;i<n;++i)array[i]=nextInt();
        return array;
      }
      public int[] nextSortedIntArray(int n){
        int array[]=nextIntArray(n);
        Arrays.sort(array);
        return array;
      }
      public ArrayList<Integer> nextIntArrayList(int n){
        ArrayList<Integer> ar= new ArrayList<>();
        for(int i=0;i<n;i++)
        ar.add(nextInt());
        return ar;
      }
      public ArrayList<Long> nextLongArrayList(int n){
        ArrayList<Long> ar= new ArrayList<>();
        for(int i=0;i<n;i++)
        ar.add(nextLong());
        return ar;
      }
  
      public int[] nextPrefixSumIntArray(int n){
        int[] array=new int[n];
        array[0]=nextInt();
        for(int i=1;i<n;++i)array[i]=array[i-1]+nextInt();
        return array;
      }
      public long[] nextLongArray(int n){
        long[] array=new long[n];
        for(int i=0;i<n;++i)array[i]=nextLong();
        return array;
      }
      public long[] nextPrefixSumLongArray(int n){
        long[] array=new long[n];
        array[0]=nextInt();
        for(int i=1;i<n;++i)array[i]=array[i-1]+nextInt();
        return array;
      }
      public long[] nextSortedLongArray(int n){
        long array[]=nextLongArray(n);
        Arrays.sort(array);
        return array;
      }
}