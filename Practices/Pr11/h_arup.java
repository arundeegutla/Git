import java.util.*;

public class h_arup {

	public static long MOD = 1000000007L;

	public static long[] fact;
	public static long[] invfact;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		long n = stdin.nextLong();
		long x = stdin.nextLong();
		long y = stdin.nextLong();

		fact = new long[((int)n)+1];
		invfact = new long[fact.length];
		invfact[0] = 1;
		fact[0] = 1;
		for (int i=1; i<=n; i++) {
			fact[i] = (fact[i-1]*i)%MOD;
			invfact[i] = modInv(fact[i], MOD);
		}

		System.out.println(Arrays.toString(fact));
        System.out.println(Arrays.toString(invfact));
        System.exit(0);

		ArrayDeque<Long> xList = getList(n, x);
		ArrayDeque<Long> yList = getList(n, y);

		long res = 0;
		while (xList.size() > 0 && yList.size() > 0) {
			long xT = xList.pollFirst();
			long yT = yList.pollFirst();
			res = (res + xT*yT)%MOD;
		}

		System.out.println(res);

	}

	public static ArrayDeque<Long> getList(long n, long x) {

		ArrayDeque<Long> res = new ArrayDeque<Long>();
		long top = n-x;
		long bot = 0;

		while (top >= bot) {
			long ans = choose(top, bot);
			System.out.println(top + " choose " + bot + ":::::" + ans);
			res.add(ans);
			top = top - (x-1);
			bot++;
		}
		return res;
	}

	public static long modExp(long b, long e, long mod) {

		if (e == 0) return 1L;
		if (e%2 == 0) {
			long tmp = modExp(b, e/2, mod);
			return (tmp*tmp)%mod;
		}
		return (b*modExp(b,e-1,mod))%mod;
	}

	public static long choose(long n, long d) {
		long res = fact[(int)n];
		res = (res*invfact[(int)d])%MOD;
		res = (res*invfact[(int)(n-d)])%MOD;
		return res;
	}

	// a must be prime
	public static long modInv(long b, long a) {
		return modExp(b, a-2, a);
	}
}