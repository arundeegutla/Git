import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class casino {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        StringBuilder ans = new StringBuilder();
        while (numCases-->0) {
            int numPlayers = in.nextInt();
            int numCards = in.nextInt();
            int[][] cards = new int[numPlayers][numCards];

            for (int i = 0; i < numPlayers; i++)
                for (int j = 0; j < numCards; j++)
                    cards[i][j] = in.nextInt();

            long total = 0;
            long[] prev = new long[numCards];
            for (int i = 1; i < cards.length; i++) {
                for (int k = 0; k < numCards; k++) {
                    total += (Math.abs(prev[k] - cards[i][k]));
                    prev[k] = cards[i][k];
                }
            }
            ans.append(total+"\n");
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
    
