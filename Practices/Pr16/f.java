import java.util.*;

/**
 * f
 */
public class f {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(getFactors(in.nextLong()));

    }

    private static long getFactors(long product) {
        HashSet<Long> factors = new HashSet<>();
        for (int i = 1; i <= Math.sqrt(product); i++) {
            if (product%i == 0) {
                factors.add(product/i);
                factors.add((long)i);
            }
        }
        factors.add(product);
        return factors.size();
    }
}