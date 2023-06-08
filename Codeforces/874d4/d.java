import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.*;

/**
 * d
 */

public class d {

    private static void solve() {
        int numCases = in.nextInt();
        while (numCases-->0) {
            // Insert code here.
            int n = in.nextInt();
            int[] arr = in.nextIntArray(n);

            int target = n;
            if (arr[0]==n)
                target-=1;

            int index = 0;
            for (int i = 0; i < arr.length; i++) {
                if (arr[i]==target) {
                    index = i;
                    break;
                }
            }


            PriorityQueue<Point> pq = new PriorityQueue<>((a,b)->a.x-b.x);

            int right = index + 1 < n ? arr[index+1] : -1;
            int left = index  - 1 >= 0 ? arr[index-1] : -1;
            int[] ans = new int[n];
            int[] ans2 = new int[n];
            int[] ans3 = new int[n];

            int cur = 0;
            for (int i = index+1; i < n; i++) {
                ans3[cur++] = arr[i];
            }
            ans3[cur++] = arr[index];
            for (int i = 0; i < index; i++) {
                ans3[cur++] = arr[i];
            }

            cur = 0;
            int sInd = index - 2;
            while (sInd >= 0 && arr[sInd] > arr[0])
                sInd--;

            for (int i = index; i < n; i++)
                ans[cur++] = arr[i];
            for (int i = index-1; i >= sInd && i >= 0; i--)
                ans[cur++] = arr[i];
            for (int i = 0; i < sInd; i++)
                ans[cur++] = arr[i];


            cur = 0;
            for (int i = index; i >= 0; i--)
                ans2[cur++] = arr[i];
            for (int i = index + 1; i < n; i++)
                ans2[cur++] = arr[i];

            if (Arrays.compare(ans, ans3) < 0 && Arrays.compare(ans2, ans3) < 0) {
                for (int i = 0; i < ans3.length; i++)
                    out.print(ans3[i] + " ");
                out.println();
            } else if(Arrays.compare(ans, ans2) >= 0) {
                out.println("right " + sInd + " --> " + index);
                for (int i = 0; i < ans.length; i++)
                    out.print(ans[i] + " ");
                out.println();
            } else {
                out.println("left ");
                for (int i = 0; i < ans2.length; i++) {
                    out.print(ans2[i] + " ");
                }
                out.println();
            }

                
        }
    }
    
    /*********************************************************************************************/
    public static FastScanner in;
    public static PrintWriter out;
    //                            R       L       D      U      DR     DL      UR       UL
    public static int[][] DD = {{0, 1},{0, -1},{1, 0},{-1, 0},{1, 1},{1, -1},{-1, 1},{-1, -1}};
    public static int[][] D = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    public static int MOD = (int)1e9 + 7;
    public static void main(String[] args) {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.flush();
        out.close();
    }
    
    public static void permute(int n) {
        int[] perm = new int[n];
        boolean[] used = new boolean[n];
        permute(0, perm, used);
    } 

    private static void permute(int at, int[] perm, boolean[] used) {
        if(at==perm.length){
            // check(perm);
            return;
        }
        for (int i = 0; i < perm.length; i++) {
            if(used[i]) continue;
            used[i] = true;
            perm[at] = i;
            permute(at+1, perm, used);
            used[i] = false;
        }
    }

    public static long sum(int[] arr) {
        long sum = 0;
        for (int i : arr)
            sum += i;
        return sum;
    }

}
/*************************************************************************************************/
class MyMath {
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
    static long fastPowerMod(long x, long y, long p)
    {
        long res = 1; // Initialize result
        x = x % p; // Update x if it is more than or equal to p
        while (y > 0) {
            if (y % 2 != 0)
                res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
        }
        return res;
    }
    public static int primeSieve(int n) {
        int primecount = 0;
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) 
                    prime[j] = false;
            }
        }
        for (int i = 2; i <= n; i++)
            if (prime[i]) primecount++;
        return primecount;
    }
    public static ArrayList<Integer> primeFactors(long N) {
        ArrayList<Integer> factors = new ArrayList<>();
        for (int i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                factors.add(i);
                N /= i;
            }
        }
        if (N >= 2) 
            factors.add((int)N);
        return factors;
    }
}
/*************************************************************************************************/
class Graph {
    int numVertices;
    ArrayList<Node> nodes;
    Graph(int numVertices) {
        this.numVertices = numVertices;
        nodes = new ArrayList<>();
        for (int i = 0; i < numVertices; i++)
            nodes.add(new Node(i));
    }
    public void addEdge(int from, int to, long weight, boolean biDirected) {
        nodes.get(from).addEdge(nodes.get(to), weight);
        if (biDirected)
            nodes.get(to).addEdge(nodes.get(from), weight);
    }
}
class Node {
    int id;
    ArrayList<Edge> edges;
    Node (int id) {
        this.id = id;
        edges = new ArrayList<>();
    }
    public void addEdge(Node to, long weight) {
        edges.add(new Edge(this, to, weight));
    }
    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
    @Override
    public boolean equals(Object obj) {
        return ((Node)obj).id == id;
    }
}
class Edge {
    Node from;
    Node to;
    long weight;
    Edge (Node from, Node to, long weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}
/*************************************************************************************************/
class FastScanner {
    BufferedReader br; StringTokenizer st;
    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        update();
    }
    public FastScanner(File in) {
        try {br = new BufferedReader(new FileReader(in));}
        catch (FileNotFoundException e) {e.printStackTrace();}
        update();
    }
    public void update(){
        try {st = new StringTokenizer(br.readLine());} 
        catch (Exception e){e.printStackTrace();}
    }
    public String next() {
        if (st.hasMoreTokens()) return st.nextToken();
        update();
        return st.nextToken();
    }
    public short nextShort() {return Short.parseShort(next());}
    public int nextInt() {return Integer.parseInt(next());}
    public long nextLong() {return Long.parseLong(next());}
    public double nextDouble() {return Double.parseDouble(next());}
    public int[] nextIntArray(int n){
        int[] array=new int[n];
        for(int i=0;i<n;++i)array[i]=nextInt();
        return array;
    }
    public long[] nextLongArray(int n){
        long[] array=new long[n];
        for(int i=0;i<n;++i)array[i]=nextLong();
        return array;
    }
}
/*************************************************************************************************/