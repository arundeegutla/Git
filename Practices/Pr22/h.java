import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class h {

    static HashMap<Long, Long> seen = new HashMap<Long, Long>();

    static void primefactor(long n) {
        for (long i = 2; i * i <= n; i++) {
            boolean put = false;
            while (n % i == 0) {
                n /= i;
                if (!put) seen.put(i, 1 + seen.getOrDefault(i, (long) 0));
                put = true;
            }
        }
        if (n >= 2) seen.put(n, 1 + seen.getOrDefault(n, (long) 0));
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            primefactor(s.nextInt());
        }
        ArrayList<Long> primes = new ArrayList<Long>();
        for (Long l : seen.keySet()) primes.add(l);
        Collections.sort(primes);
        for (int i = 0; i < primes.size(); i++) {
            if (i != 0 && i % 5 == 0) System.out.println();
            System.out.print(primes.get(i) + " ");
        }
        System.out.println();
    }
}
