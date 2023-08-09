import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class lotto {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        loop : while (numCases-->0) {
            int numDays = in.nextInt();


            HashMap<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < numDays; i++) {
                int numPeople = in.nextInt();
                for (int j = 0; j < numPeople; j++) {
                    map.put(in.nextInt(), i);
                }
            }


            int[] winners = new int[numDays];

            for (int i : map.keySet()) {
                winners[map.get(i)] = i;
            }

            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < winners.length; i++) {
                ans.append(winners[i] + " ");
                if(winners[i] == 0) {
                    System.out.println(-1);
                    continue loop;
                }
            }

            System.out.println(ans);

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
    
