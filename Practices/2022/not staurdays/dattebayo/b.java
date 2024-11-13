import java.io.*;
import java.util.*;
/**
 * a
 */
public class b {

    public static void main(String[] args) throws IOException {
        File fileIn = new File("distance.in");
        File fileOut = new File("distance.out");
        FileWriter fw = new FileWriter(fileOut);
        FastScanner in = new FastScanner(fileIn);

        int n = in.nextInt(), m = in.nextInt(), s = in.nextInt()-1, e = in.nextInt()-1;

        ArrayList<Vertex> dist = new ArrayList<>();

        for (int i = 0; i < n; i++) 
            dist.add(new Vertex(i));

        for (int i = 0; i < m; i++) {
            int from = in.nextInt()-1;
            int to = in.nextInt()-1;
            int w = in.nextInt();
            dist.get(from).edges.add(new Edge(from, to, w));
            dist.get(to).edges.add(new Edge(to, from, w));
        }
        
        int[] prev = new int[n];
        boolean[] visited = new boolean[n];
        long[] disted = new long[n];
        Arrays.fill(disted, -1);
        PriorityQueue<Version> q = new PriorityQueue<>();
        q.add(new Version(s, 0));
        disted[s] = 0;

        while (!q.isEmpty()) {
            Version here = q.poll();
            if(visited[here.vertex]) continue;
            visited[here.vertex] = true;
            for (Edge ed : dist.get(here.vertex).edges) {
                if (disted[ed.to] == -1 || disted[ed.to] > here.dist + ed.w) {
                    q.add(new Version(ed.to, here.dist + ed.w));
                    disted[ed.to] = here.dist + ed.w;
                    prev[ed.to] = here.vertex;
                }
            }
        }

        if (disted[e] != -1) {
            fw.append(disted[e]+"\n");
            int here = e;
            StringBuilder str = new StringBuilder();
            while (here != s) {
                str.append(" " + (here+1));
                here = prev[here];
            }
            str.append(" " + (here+1));
            fw.append(str.reverse());
        } else {
            fw.append(disted[e]+"");


        fw.flush();
    }
}

class Vertex {
    int vertex;
    ArrayList<Edge> edges;
    Vertex(int vertex) {
        this.vertex = vertex;
        this.edges = new ArrayList<>();
    }
}

class Edge {
    int from, to;
    long w;
    Edge(int from, int to, int w) {
        this.from = from;
        this.to = to;
        this.w = w;
    }
}

class Version implements Comparable<Version>{
    int vertex;
    long dist;
    Version(int vertex, long dist) {
        this.vertex = vertex;
        this.dist = dist;
    }
    @Override
    public int compareTo(Version o) {
        return this.dist - o.dist < 0 ? -1 : 1;
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

