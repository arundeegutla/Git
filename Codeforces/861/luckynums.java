import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
/**
 * luckynums
 */
public class luckynums {
    public static void main(String[] args) {

        FastScanner in = new FastScanner();
        StringBuilder ans = new StringBuilder();

        int numCases = in.nextInt();
        while (numCases-->0) {
            int l = in.nextInt();
            int r = in.nextInt();

            int max = -1;
            int index = l;
            for(int i = l; i <= r; i++){

                int maxNum = -1;
                int min = -1;
                String str = Integer.toString(i);

                for (int j = 0; j < str.length(); j++) {
                    if (maxNum == -1 || str.charAt(j)-'0' > maxNum)
                        maxNum = str.charAt(j)-'0';
                    if (min == -1 || str.charAt(j)-'0' < min)
                        min = str.charAt(j)-'0';
                }

                int num = maxNum - min;

                if (num > max) {
                    max = num;
                    index = i;
                }
                if (max == 9)
                    break;
            }

            ans.append(index+"\n");
        }

        System.out.print(ans);
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
    
