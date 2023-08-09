import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T = fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n = fs.nextInt();
			int[] a = fs.readArray(n);

			long[] expectedCS = new long[n+1];
			for (int i=1; i<=n; i++) 	
				expectedCS[i] = expectedCS[i-1] + a[i-1];

			int l=0, r=n-1;
			while (l != r) {
				int m = (l+r) / 2;
				StringBuilder sb=new StringBuilder("? "+(m+1)+" ");
				for (int i=0; i<=m; i++) {
					sb.append(i+1);
					sb.append(" ");
				}
				System.out.println(sb.toString());
				long total=fs.nextLong();
				if (total == expectedCS[m+1]) {
					l=m+1;
				}
				else {
					r=m;
				}
			}
			System.out.println("! "+(l+1));

		}
		out.close();
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
