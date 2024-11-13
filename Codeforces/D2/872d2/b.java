import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.*;

/**
 * b
 */

public class b {

    public static int MIN = -1;
    private static void solve() {
        int numCases = in.nextInt();
        while (numCases-->0) {
            // Insert code here.
            int n = in.nextInt();
            int m = in.nextInt();
            int[] arr = in.nextIntArray(n*m);

            Arrays.sort(arr);

            out.println(Math.max(max(arr, n, m), min(arr, n , m)));
            


            
            // permute(n*m, n, m, arr);

            // for (int i = 0; i < arr.length; i++) {
            //     for (int j = 0; j < arr.length; j++) {
            //         if(i==j)continue;
            //         for (int k = 0; k < arr.length; k++) {
            //             if(k==i || k==j)continue;

            //             int one = arr[i];
            //             int two = arr[j];
            //             int three = arr[k];

            //             long ans = 0;
            //             ans += (long)(Mat)*(m-1);
            //             ans += (long)(max - min2)*(n-1);
            //             ans += (long)(max - Math.min(min1, min2)) * ((n-1)*(m-1));
            //             out.println(max + " " + min1 + " " + min2 + " ----> " + ans);
            //         }
            //     }
            // }
            

            // out.println();
        }
    }
    
    private static long min(int[] arr, int n, int m) {
        int min = arr[0];
        int max1 = arr[arr.length - 1];
        int max2 = arr[arr.length - 2];

        if(n>=m) {
            max2 = arr[arr.length - 1];
            max1 = arr[arr.length - 2];
        }
        
        long ans = 0;
        ans += (long)(max1 - min)*(m-1);
        ans += (long)(max2 - min)*(n-1);
        ans += (long)(Math.max(max1, max2) - min) * ((n-1)*(m-1));

        return ans;
    }

    private static long max(int[] arr, int n, int m) {
        int max = arr[arr.length - 1];
        int min1 = arr[0];
        int min2 = arr[1];

        if(n>=m) {
            min2 = arr[0];
            min1 = arr[1];
        }
        
        long ans = 0;
        ans += (long)(max - min1)*(m-1);
        ans += (long)(max - min2)*(n-1);
        ans += (long)(max - Math.min(min1, min2)) * ((n-1)*(m-1));

        return ans;
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
    
    public static void permute(int n, int r, int c, int[] arr) {
        int[] perm = new int[n];
        boolean[] used = new boolean[n];
        permute(0, perm, used, r, c, arr);
    } 

    private static void permute(int at, int[] perm, boolean[] used, int r, int c, int[] arr) {
        if(at==perm.length){
            check(perm, r, c, arr);
            return;
        }
        for (int i = 0; i < perm.length; i++) {
            if(used[i]) continue;
            used[i] = true;
            perm[at] = i;
            permute(at+1, perm, used, r,c, arr);
            used[i] = false;
        }
    }

    private static void check(int[] perm, int r, int c, int[] arr) {
        int[][] grid = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                grid[i][j] = arr[perm[i*c+j]];
            }
        }

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                max = Math.max(max, grid[i][j]);
                min = Math.min(min, grid[i][j]);
                ans += max - min;
            }
        }

        if(ans > MIN) {
            System.out.println(ans);
            for (int[] is : grid) {
                System.out.println(Arrays.toString(is));
            }
            System.out.println();
            MIN = ans;
        }
        
        if(ans == 64) {
            
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