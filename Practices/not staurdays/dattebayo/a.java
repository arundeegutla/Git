import java.io.*;
import java.util.*;

/**
 * a
 */
public class a {

    public static void main(String[] args) throws IOException {
        File fileIn = new File("dijkstra.in");
        File fileOut = new File("dijkstra.out");
        FileWriter fw = new FileWriter(fileOut);
        FastScanner in = new FastScanner(fileIn);

        int n = in.nextInt(), s = in.nextInt()-1, e = in.nextInt()-1;

        int[][] dist = new int[n][n];
        for (int i = 0; i < dist.length; i++)
            for (int j = 0; j < dist.length; j++)
                dist[i][j] = in.nextInt();


        int[] disted = new int[n]; Arrays.fill(disted, -1);
        disted[s] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(s);

        while (!q.isEmpty()) {
            int here = q.poll();
            for (int i = 0; i < dist.length; i++) {
                if (dist[here][i] != -1 && (disted[i] == -1 || disted[i] > disted[here] + dist[here][i])) {
                    q.add(i);
                    disted[i] = disted[here] + dist[here][i];
                }
            }
        }

        fw.append(disted[e]+"");
        fw.flush();
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							Fast Scanner								*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class FastScanner {
    BufferedReader br; StringTokenizer st;
    public FastScanner(File in) {
        try {
            br = new BufferedReader(new FileReader(in));
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
}

