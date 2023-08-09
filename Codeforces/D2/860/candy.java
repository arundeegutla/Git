import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class candy {
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numTypes = in.nextInt();

            int[] counts = new int[numTypes];
            int[] cost = new int[numTypes];

            ArrayList<HashSet<Integer>> factors = new ArrayList<>();

            for (int i = 0; i < numTypes; i++) {
                counts[i] = in.nextInt();
                cost[i] = in.nextInt();
                factors.add(new HashSet<>());
                addFactors(counts[i], factors.get(i));
            }

            int numstickers = 1;

            HashSet<Integer>[] stickers = new HashSet[numTypes];
            for (int i = 0; i < stickers.length; i++) {
                stickers[i] = new HashSet<>();
            }

            for (int i = 1; i < cost.length; i++) {
                boolean newA = false;

                if (stickers[i-1].size() == 0) {
                    for (int factorBefore : factors.get(i-1)) {
                        if ((double)(factorBefore * cost[i-1])/cost[i] == (int)(factorBefore * cost[i-1])/cost[i] && factors.get(i).contains((factorBefore * cost[i-1])/cost[i])) {
                            stickers[i].add((factorBefore * cost[i-1])/cost[i]);
                            newA = true;
                        }
                    }
                } else {
                    for (int factorBefore : stickers[i-1]) {
                        if ((double)(factorBefore * cost[i-1])/cost[i] == (int)(factorBefore * cost[i-1])/cost[i] && factors.get(i).contains((factorBefore * cost[i-1])/cost[i])) {
                            stickers[i].add((factorBefore * cost[i-1])/cost[i]);
                            newA = true;
                        }
                    }
                }
                

                if (!newA) {
                    numstickers++;
                }
                
            }

            // System.out.println(Arrays.toString(stickers));
            System.out.println(numstickers);
            
        }
    }

    private static void addFactors(int num, HashSet<Integer> factors) {
        for (int i = 1; i <= Math.sqrt(num); i++) {
            if (num%i == 0) {
                factors.add(num/i);
                factors.add(i);
            }
        }
        factors.add(num);
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
    
