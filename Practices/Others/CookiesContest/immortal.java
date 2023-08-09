import java.util.Scanner;

public class immortal {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            in.nextInt();

            long[] res = new long[2];

            long n = in.nextLong();
            FastDoubling(n, res);

            System.out.println(i+1 + " " + res[0]);
        }

        in.close();
    }

    public static void FastDoubling(Long n, long []res)
    {
        long a, b, c, d;
        int MOD = 1000000000;

        if (n == 0)
        {
            res[0] = 0;
            res[1] = 1;
            return;
        }

        FastDoubling((n / 2), res);
     

        a = res[0];
        b = res[1];
     
        c = 2 * b - a;
     
        if (c < 0)
            c += MOD;
     

        c = (a * c) % MOD;
     

        d = (a * a + b * b) % MOD;
     

        if (n % 2 == 0)
        {
            res[0] = c;
            res[1] = d;
        }
        else
        {
            res[0] = d;
            res[1] = c + d;
        }
    }
     
}
