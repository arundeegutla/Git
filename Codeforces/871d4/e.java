import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.*;

/**
 * e
 */

public class e {
    public static FastScanner in;
    public static OutputWriter out;
    public static boolean TIME;
    public static int[][] D = {{0, 1}, {0 , -1}, {1, 0}, {-1 ,0}};
    private static void solve() {
        int numCases = in.nextInt();
        while (numCases-->0) {
            // Insert code here.
            int n = in.nextInt();
            int m = in.nextInt();

            int[][] grid = new int[n][m];
            for (int i = 0; i < grid.length; i++)
                grid[i] = in.nextIntArray(m);

            boolean[][] visited = new boolean[n][m];

            long max = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    max = Math.max(max, go(i, j, grid, visited));
                }
            }

            System.out.println(max);
        }
    }

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * 								MAIN									*
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    private static long go(int r, int c, int[][] grid, boolean[][] visited) {
        if (r<0||r>=grid.length||c<0||c>=grid[0].length||visited[r][c]||grid[r][c]==0)
            return 0;

        visited[r][c] = true;
        long total = grid[r][c];
        for (int[] d : D)
            total += go(r+d[0], c+d[1], grid, visited);

        return total;
    }

    public static void main(String[] args) {

        new Thread(null, new Runnable() {
            @Override
            public void run() {
                in = new FastScanner();
                out = new OutputWriter(System.out);
                solve();
                out.flush();
                out.close();
            }
        }, "Solver", (1L<<29)).start();
    }

}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							Utils										*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class MyUtils {

    public static long getSumofArray(int[] arr) {
        long sum = 0;
        for (int i : arr)
            sum += i;
        return sum;
    }

    // Finds a specific value within a range of values such that some function, defined by f(x), 
    // is at its minimum or maximum
    static double ternarySearch() {
        double lo = 0, hi = (int)1e9;
        double epsilon = 1e-9;
        while (hi - lo > epsilon) {
            double m1 = lo + (hi - lo) / 3;
            double m2 = hi - (hi - lo) / 3;

            // CALCULATE points
            double f1 = 0;
            double f2 = 0;
            // ‘<’ to find the maximum, ‘>’ to find the minimum
            if (f1 < f2) 
                lo = m1;
            else 
                hi = m2;
        }
        // CALCULATE LO
        return lo;
    }

    public static long tspHelper(long[][] dist) {
        int n = dist.length;
        long[][] memo = new long[1<<n][n];
        for (long[] oneD : memo) 
        Arrays.fill(oneD, -1);
        long shortest = (int)1e9; /* be mindful of this */
        /*Test all starting pos.*/
        for (int i = 0; i < n; i++){
            long thisShortest = tsp(1<< i, i, dist, memo) + dist[0][i];
            shortest = Math.min(shortest, thisShortest);
        }
        return shortest;
    }
    
    public static long tsp(int visited, int current, long[][] dist, long[][] memo) {
        if (memo[visited][current] != -1)
            return memo[visited][current];
    
        // all visited; go back to start.
        if (visited == ((1<<dist.length) - 1))
            return dist[current][0];
    
        long min = (int)1e9; // be mindful
        for (int i = 0; i < dist.length; i++)
            if ((visited & (1<<i)) == 0) // only go to unvisited
                min = Math.min(min, tsp(visited | (1<<i), i, dist, memo) + dist[current][i]);
        
        return memo[visited][current] = min;
    }

    /* 
    * Returns length of LCS for X[0..m-1], Y[0..n-1] 
    */
    public static int LCS( char[] X, char[] Y, int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m-1] == Y[n-1])
            return 1 + LCS(X, Y, m-1, n-1);
        else
            return Math.max(LCS(X, Y, m, n-1), LCS(X, Y, m-1, n));
    }

    public static String convertBase(String current, int before, int after) {
        return Long.toString(Long.parseLong(current, before), after);
    }

    public static int[] sort(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i : arr)
            list.add(i);
        Collections.sort(list);
        for (int i = 0; i < arr.length; i++)
            arr[i] = list.get(i);
        return arr;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							Number Theory								*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class NumberTheory {

    public static int MOD = (int)1e9 + 7;

    public static int[] mobiusArr(int N) {
        int[] mobius = new int[N];
        mobius[1] = 1;
        for (int i = 1; i < N; i++)
                for (int j = i + i; j < N; j += i)
                    mobius[j] -= mobius[i];
        return mobius;
    }

    /*
     * Value of Catalan at a given N:
     * Gives the number of combinations such that some value ‘Y’ in an initial segment of a
     * string does not appear more than ‘X’
     * Ex: N = 3, cat(N) = 5: XXXYYY  XYXXYY  XYXYXY  XXYYXY  XXYXYY
     */
    public static long[] catalanArr(int N) {
        long[] cat = new long[N];
        cat[0] = 1;
        for (int i = 1; i < N; i++)
            cat[i] = (long) (((4 * (i - 1) + 2) / (double) (i + 1)) * cat[i - 1]);
        return cat;
    }

    /*
     * Modifies an array of two values, the value at the 0th index being the
     * (N - 1)th fibonacci number and the value at the 1st index being the Nth
     * fibonacci number.
     */
    public static void FastFib(long n, long[] res, long MOD) {
        long a, b, c, d;

        if (n == 0) {
            res[0] = 0;
            res[1] = 1;
            return;
        }
        FastFib((n / 2), res, MOD);
        a = res[0];
        b = res[1];
        c = 2 * b - a;
        if (c < 0)
            c += MOD;

        c = (a * c) % MOD;
        d = (a * a + b * b) % MOD;

        if (n % 2 == 0) {
            res[0] = c;
            res[1] = d;
        } else {
            res[0] = d;
            res[1] = c + d;
        }
    }

    // Euler’s Theorem:
    public static long modDivide(long a, long b, long P){
        return (a * modInverse(b, P-2)) % P;
    }

    // Least Common Multiple LCM
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    // Fast GCD:
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }

    // Fast Modular Exponentiation
    static long fastPowerMod(long x, long y, long p)
    {
        long res = 1; // Initialize result
        x = x % p; // Update x if it is more than or equal to p
        while (y > 0) {
            // If y is odd, multiply x with result
            if (y % 2 != 0)
                res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
        }
        return res;
    }


    // Returns n^(-1) mod p
    static long modInverse(long n, long p) {
        return fastPowerMod(n, p - 2, p);
    }

    // Returns nCr % p using Fermat's little theorem.
    public static long nCkP(int n, int r, int p, long[] fac) {
        if (n < r) return 0;
        if (r == 0) return 1;
        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }

    // Factorials
    public static long[] getFactorialMod(int n, int p) {
        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = ((long)fac[i - 1] * i) % p;
        return fac;
    }


    // Value of Prime Sieve at a given N:
    // Number of prime numbers less than or equal to N
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
    

    /*
     * Gets prime factors of a number.
     */
    public static ArrayList<Integer> getPrimeFactors(long N) {
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
    public static boolean isPrime(long N) {
        return (new BigInteger(Long.toString(N)).isProbablePrime(20));
    }
        
    public static long[][] floydWarshalls(int[][] graph) {
        int V = graph.length;
        long[][] dist = new long[V][V];
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
        return dist;
    }

    // Finds the area of a polygon given an array of points with (x, y) values
    static double shoelaceTheorem(Point[] points) {
        double l = 0, r = 0;
        int N = points.length;
        for (int i = 0; i < N; i++) {
            l += points[i].x * points[(i + 1) % N].y;
            r += points[i].y * points[(i + 1) % N].x;
        }
        return Math.abs(l - r) / 2;
    }

    public static long[][] matrixExpo(long[][] base, long exp) {
        int n = base.length;
        if (exp == 0) return identity(n);
        if (exp%2 == 0) {
            long[][] sqrt = matrixExpo(base, exp/2);
            return multiply(sqrt, sqrt);
        }
        long[][] tmp = matrixExpo(base, exp-1);
        return multiply(tmp, base);
    }
    private static long[][] identity(int n) {
        long[][] m = new long[n][n];
        for (int i = 0; i < n; i++)
            m[i][i] = 1;
        return m;
    }
    public static long[][] multiply(long[][] A, long[][] B){
        // Check Compatibility.
        int row1 = A.length; 
        int row2 = B.length, col2 = B[0].length;
        long C[][] = new long[row1][col2];
        for (int i = 0; i < row1; i++)
            for (int j = 0; j < col2; j++)
                for (int k = 0; k < row2; k++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }
        
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							List Graph									*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class Graph {
    int numVertices;
    ArrayList<Vertex> nodes;
    Graph(int numVertices) {
        this.numVertices = numVertices;
        nodes = new ArrayList<>();
        for (int i = 0; i < numVertices; i++)
            nodes.add(new Vertex(i));
    }
    public void addEdge(int from, int to, long weight, boolean biDirected) {
        nodes.get(from).addEdge(nodes.get(to), weight);
        if (biDirected)
            nodes.get(to).addEdge(nodes.get(from), weight);
    }
}

class Vertex {
    int id;
    ArrayList<Edge> edges;
    Vertex (int id) {
        this.id = id;
        edges = new ArrayList<>();
    }
    public void addEdge(Vertex to, long weight) {
        edges.add(new Edge(this, to, weight));
    }
}

class Edge {
    Vertex from;
    Vertex to;
    long weight;

    Edge (Vertex from, Vertex to, long weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 							Segment Tree								*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class SegmentTree {

    SegmentTree left, right;
    int lo, hi, max;
    
    SegmentTree(int l, int r) {
        lo = l;
        hi = r;
        max = 0; // change based on problem

        if (l == r) return;

        left = new SegmentTree(l, (l + r) / 2);
        right = new SegmentTree((l + r) / 2 + 1, r);
    }
    
    int query(int l, int r) {
        if (l > hi || r < lo) return 0; // No cover
        if (l <= lo && hi <= r) return max; // Full cover
        
        int leftAns = left.query(l, r);
        int rightAns = right.query(l, r);
        
        return Math.max(leftAns, rightAns); // change based on problem
    }

    void update(int index, int val) {
        if (lo == hi) {
            max = val;
            return;
        }
        
        if (index <= (lo + hi) / 2) left.update(index, val);
        else right.update(index, val);
        
        max = Math.max(left.max, right.max); // change based on problem
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

class OutputWriter {
    private final PrintWriter writer;
    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(System.out);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) writer.print(' ');
            if (objects[i] == null) System.out.println('-');
            else writer.print(objects[i]);
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(double[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(long[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(array[i]);
        }
    }

    public void print(char[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(array[i]);
        }
    }
    public void print(String[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(array[i]);
        }
    }
    public void print(int[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }

    public void print(double[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }

    public void print(long[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }

    public void print(char[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }

    public void print(String[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }
    public void print(Object[][] matrix){
        for(int i=0;i<matrix.length;++i)
            println(matrix[i]);
    }

    public void println(int[] array) {
        print(array);
        writer.println();
    }

    public void println(double[] array) {
        print(array);
        writer.println();
    }

    public void println(long[] array) {
        print(array);
        writer.println();
    }

    public void println(String[] array) {
        print(array);
        writer.println();
    }

    public void println() {
        writer.println();
    }

    public void println(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void println(char i) {
        writer.println(i);
    }

    public void println(char[] array) {
        writer.println(array);
    }

    public void printf(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void println(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void println(int i) {
        writer.println(i);
    }

    public void separateLines(int[] array) {
        for (int i : array)
            println(i);
    }
}
