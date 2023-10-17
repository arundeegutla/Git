import java.util.Scanner;

public class sharon_test {
	
	static final int MOD = (int)1e9 + 7;
	static final int MAX = (int)1e6 + 1;
	static final long[] fact = new long[MAX];
	
	public static void main(String[] args) {
		precomp();
		Scanner scan = new Scanner(System.in);

        System.out.println(NKP(8, 4));


        long res = 1;
        for (long i = 8; i > 8-4; --i) {
            res = (res * i) % MOD;
        }
        
        long denom = 1;
        for (long i = 1; i <= 4; ++i) {
            long ti = i;
            while(ti % MOD == 0) {
                ti /= MOD;
            }
            denom = (denom * ti) % MOD;
        }
        res = (res * degree(denom, MOD-2, MOD)) % MOD;

        System.out.println(res);

		System.out.println((fact[8]/(fact[8-4]*fact[4])));

		System.out.println((double)1L);
	}
	
	private static long degree(long a, int k, int p) {
        long res = 1;
        long cur = a;
      
        while (k>0) {
          if (k % 2 > 0)
            res = (res * cur) % p;

          k /= 2;
          cur = (cur * cur) % p;
        }
        return res;
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
		long x = 1, y = a;
		while(b > 0) {
			if(b % 2 == 1)
				x = (x * y) % MOD;
			y = (y * y) % MOD;
			b /= 2;
		} 
		return x % MOD;
	}
	
}
