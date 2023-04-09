import java.util.*;
import java.io.*;
public class h_dannywest {
	static final int max = Integer.MAX_VALUE / 2;
	
	static int n, m;
	static int sum1 = 0, sum2 = 0;
	static int[] arr1, arr2;
	public static void main(String[] args) {
		FS sc = new FS();
		n = sc.nextInt();
		arr1 = new int[n];
		for(int i = 0; i < n; ++i) sum1 += arr1[i] = sc.nextInt();
		m = sc.nextInt();
		arr2 = new int[m];
		for(int i = 0; i < m; ++i) sum2 += arr2[i] = sc.nextInt();
		
		int[] min1 = getMin(n, arr1, sum1);
		System.exit(0);
		int[] min2 = getMin(m, arr2, sum2);
		
		int out = max;
		for(int i = 1; i <= Math.min(sum1, sum2); ++i) {
			if(min1[i] != -1 && min2[i] != -1) out = Math.min(out, min1[i] + min2[i]);
		}
		
		if(out == max) System.out.println("impossible");
		else System.out.println(out);
	}
	static int[] getMin(int n, int[] arr, int totalSum) {
		int[] min = new int[totalSum + 1];
		Arrays.fill(min, -1);
		min[0] = 0;
		
		System.out.println(totalSum);
		for(int i = 0; i < n; ++i) {
			for(int j = totalSum; j >= 0; --j) {
				System.out.println(Arrays.toString(min));
				if(min[j] == -1) 
					continue;

				int newj = j + arr[i];
				int num = min[j] + 1;
				if(newj <= totalSum && (min[newj] == -1 || num < min[newj])) 
					min[newj] = num;
			}
		}
		
		return min;
	}
	static class FS {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while(!st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(Exception e) {}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}