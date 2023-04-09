import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class b {
    public static boolean[] hasDistinct;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int SIZE = (int)1e6 + 1;
        hasDistinct = new boolean[SIZE];
        for (int i = 1; i < hasDistinct.length; i++) {
            hasDistinct[i] = checkDistinct(i);
        }
        System.out.println(Arrays.toString(hasDistinct));
    }

    public static boolean checkDistinct(int n)
    {

        HashSet<Integer> primes = new HashSet<>();

        for (int j = 2; j * j <= n; j++) {
            while (n % j == 0) {
                if (primes.contains(j))
                    return false;
                primes.add(j);
                n /= j;
            }
        }
        if (n >= 2) {
            if (primes.contains(n))
                return false;
        }

        return true;

    }
}
