import java.util.ArrayList;
import java.util.Scanner;

public class thermostat_brennan {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), q = s.nextInt();
        ArrayList<Temp> temps = new ArrayList<Temp>();
        for (int i = 0; i < n; i++) temps.add(new Temp(s.nextInt(), s.nextInt()));
        for (int i = 0; i < q; i++) {
            int x = s.nextInt(), y = s.nextInt(), v = s.nextInt();
            
            Temp tempA = temps.get(x - 1), tempB = temps.get(y - 1);

            long rangeA = tempA.hi - tempA.lo, rangeB = tempB.hi - tempB.lo;
            long num = v * 100 - tempA.lo * rangeA, denom = rangeA;
            System.out.println(num + " " + denom);
            num *= rangeB;
            denom *= 100;
            long gcd = gcd(num, denom);
            num /= gcd;
            denom /= gcd;
            num += tempB.lo * denom;
            long newgcd = gcd(num, denom);
            System.out.println(((num < 0 || denom < 0) ? "-" : "") + (Math.abs(num / newgcd)) + "/" + (Math.abs(denom / newgcd)));
        }
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

class Temp {
    long lo, hi;
    Temp(long lo, long hi) { this.lo = lo; this.hi = hi; }
}