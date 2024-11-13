import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

1
3
3 10 6

1
5
9 8 2 4 6

 */
public class d1 {

	static final boolean debug = false;

	public static void main(String[] subscribeToSecondThread) {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = fs.nextInt();
		for (int tt = 0; tt < T; tt++) {
			int n = fs.nextInt();
			int[] a = fs.readArray(n);
			RMQ rmq = new RMQ(a);
			// long ans = (n - 1) * (n) / 2;
			long ans = 0;
			for (int i = 0; i < n; i++) {
				ans += i * (n - i);
			}
			if (debug)
				System.out.println("Starting wtih " + ans);
			for (int split = 0; split + 1 < n; split++) {
				if (debug)
					System.out.println("  Split " + split);
				int ll = 0;
				int rMin = a[split + 1];
				for (int rr = split + 1; rr < n; rr++) {
					int lMax = rmq.query(ll, split);
					rMin = Math.min(rMin, a[rr]);
					if (debug)
						System.out.println("Starting at ll: " + ll + " rMin " + rr);
					while (ll <= split && lMax > rMin) {
						ll++;
						lMax = rmq.query(ll, split);
					}
					if (ll <= split) {
						if (debug)
							System.out.println("For split " + split + " rr: " + rr + " using ll: " + ll);
						ans -= split - ll + 1;
					}
				}
			}
			out.println(ans);
		}
		out.close();
	}

	static class RMQ {
		int[] vs;
		int[][] lift;

		public RMQ(int[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new int[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.max(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public int query(int low, int hi) {
			int range = hi - low + 1;
			if (range == 0) {
				return -1;
			}
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.max(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}

	static final Random random = new Random();
	static final int mod = 1_000_000_007;

	static void ruffleSort(int[] a) {
		int n = a.length;// shuffle, then sort
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static long add(long a, long b) {
		return (a + b) % mod;
	}

	static long sub(long a, long b) {
		return ((a - b) % mod + mod) % mod;
	}

	static long mul(long a, long b) {
		return (a * b) % mod;
	}

	static long exp(long base, long exp) {
		if (exp == 0)
			return 1;
		long half = exp(base, exp / 2);
		if (exp % 2 == 0)
			return mul(half, half);
		return mul(half, mul(half, base));
	}

	static long[] factorials = new long[2_000_001];
	static long[] invFactorials = new long[2_000_001];

	static void precompFacts() {
		factorials[0] = invFactorials[0] = 1;
		for (int i = 1; i < factorials.length; i++)
			factorials[i] = mul(factorials[i - 1], i);
		invFactorials[factorials.length - 1] = exp(factorials[factorials.length - 1], mod - 2);
		for (int i = invFactorials.length - 2; i >= 0; i--)
			invFactorials[i] = mul(invFactorials[i + 1], i + 1);
	}

	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n - k]));
	}

	static void sort(int[] a) {
		ArrayList<Integer> l = new ArrayList<>();
		for (int i : a)
			l.add(i);
		Collections.sort(l);
		for (int i = 0; i < a.length; i++)
			a[i] = l.get(i);
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
