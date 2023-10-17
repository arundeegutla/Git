import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;

public class thermostat {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int Q = in.nextInt();
        Temp[] alltemps = new Temp[N];
        for (int i = 0; i < N; i++)
            alltemps[i] = new Temp(in.nextInt(), in.nextInt());
        
        while (Q-->0) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int v = in.nextInt(); 

            long[] vInC = getInC(alltemps[x], v);
            long[] cInY = getInY(vInC, alltemps[y]);

            long gcd = gcd(cInY[0], cInY[1]);

            long num = cInY[0]/gcd;
            long denom = cInY[1]/gcd;

            System.out.println(((num < 0 || denom < 0) ? "-" : "") + (Math.abs(num)) + "/" + (Math.abs(denom)));

            
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    private static long[] getInY(long[] vInC, Temp temp) {
        long d = 100*vInC[1];
        return new long[] {temp.m * vInC[0] + temp.b*d, d};
    }

    private static long[] getInC(Temp temp, int v) {
        return new long[] {100*(v-temp.b), temp.m};
    }
    
}

/**
 * Innerthermostat_arun
 */
class Temp {
    int b;
    int m;
    Temp(int zero, int hundered) {
        this.b = zero;
        this.m = hundered - zero;
    }
}