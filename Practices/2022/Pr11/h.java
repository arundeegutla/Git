// Thanks for helping me get this one, Cameron Custer

import java.util.Scanner;

public class h {
    
    public static final int MOD = (int)1e9+ 7;
    public static long[] fact;
    public static long[] invfact;
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        
        fact = new long[n + 1];
        invfact = new long[n + 1];

        fact[0] = 1;
        invfact[0] = 1;
        for (int i = 1; i < fact.length; i++){
            fact[i] = (fact[i-1] * i)%MOD;
            invfact[i] = binaryExpo(fact[i], MOD - 2);
        }

        long ret = 0;
        for (int i = 1; i <= Math.min(n/x, n/y); i++) 
            ret = (ret + (choose(n - i * x + i - 1, i - 1) * choose(n - i * y + i - 1, i - 1))) % MOD;

        System.out.println(ret);
    }


    public static long choose(int top, int bottom) {
        return (fact[top] * ((invfact[top - bottom] * invfact[bottom]) % MOD)) % MOD;
    }

    public static int binaryExpo(long a, long b) {
        long ret = 1;
        while (b > 0) {
            if ((b & 1) > 0)
                ret = (ret * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return (int)(ret % MOD);
    }
}


// n!/(n-k)!k!
// <=>
// n! * (n-k)^-1! * k^-1!