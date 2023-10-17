import java.util.Scanner;

public class j {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.println(nchooser(2 * n, n + 1, (long)1e5+7) - (nchooser(2 * n, 2, (long)1e5+7) - n));
        System.out.println(choose(2 * n, n + 1) - (choose(2 * n, 2) - n));
    }

    static long choose(int n, int r) {
        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i);

        long denom = (fac[n-r] * fac[r]);

        return fac[n]/denom;
    }

    static long nchooser(int n, int r, long p) {
        if (n < r) return 0;
        if (r == 0) return 1;

        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;
    
        long ans = fac[n];
        long denom = (modinv(fac[r], p) % p) * (modinv(fac[n - r], p) % p);

        return (ans * denom) % p;
    }

    static long modinv(long n, long p) {
        return pow(n, p - 2, p);
    }

    static long pow(long x, long y, long p) {
        long res = 1;
        x = x % p;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
        }
        return res;
    }
}
