import java.util.Scanner;

public class h_sharon {
	
	static final int MOD = (int)1e9 + 7;
	static final int MAX = (int)1e6 + 1;
	static final long[] fact = new long[MAX];
	
	public static void main(String[] args) {
		precomp();
		Scanner scan = new Scanner(System.in);

		long N = scan.nextLong(), X = scan.nextLong(), Y = scan.nextLong();
		long res = 0;

		for(long i = 1 ; i <= N ; i++) {

			if((i*(X-1))+1L > N)
				continue;

			if((i*(Y-1))+1L > N)
				continue; 
				
			int n1 = (int) (N - (i * (X - 1)) - 1L);
			int n2 = (int) (N - (i * (Y - 1)) - 1L);
//			System.out.println(n1 + " " + (i - 1));
//			System.out.println(n2 + " " + (i - 1));
			if(n1 < (i - 1) || n2 < (i - 1))
				continue;
			long a = NKP(n1, (int)(i - 1));
			long b = NKP(n2, (int)(i - 1));
//			System.out.println("results: " + a + " " + b);
//			System.out.println();
			res = (res + ((a * b) % MOD)) % MOD;
		}
		System.out.println(res);
	}
	
	// Precompute factorials with mod = 1,000,000,007
	static void precomp() {
		fact[0] = 1;
		for(int i = 1 ; i < MAX ; i++)
			fact[i] = (fact[i-1] * i) % MOD;
	}
	
	// N choose K mod P
	static long NKP(int n, int k) {
//		System.out.println(n+" "+k);
		return (fact[n] * ((modinverse(fact[k]) * modinverse(fact[n-k])) % MOD)) % MOD;
	}
	
	static long modinverse(long n) {
		return power(n, MOD-2);
	}
	
	static long power(long a, long b) {
		long x = 1;
		long y = a;
		
		while(b > 0) {
			if(b % 2 == 1)
				x = (x * y) % MOD;
			y = (y * y) % MOD;
			b /= 2;
		} 
		return x % MOD;
	}
	
}
