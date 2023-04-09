import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class f {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numNums = in.nextInt();
        int product = in.nextInt();
        long[] nums = new long[1000000];
        for (int i = 0; i < numNums; i++)
            nums[in.nextInt()]++;
        ArrayList<Integer> factors = getFactors(product);
        // System.out.println(factors);

        long total = 0;
        for (int i = 0; i < factors.size(); i++) {
            for (int j = i; j < factors.size(); j++) {
                for (int k = j; k < factors.size(); k++) {

                    int s = factors.get(i);
                    int e = factors.get(j);
                    int f = factors.get(k);

                    if ((long)s * e * f != product)
                        continue;

                    if (s == e && e == f)
                        total += nck(nums[s], 3);
                    else if (s == e)
                        total += (nck(nums[s], 2) * nums[f]);
                    else if (e == f)
                        total += (nck(nums[e], 2) * nums[s]);
                    else if (s == f)
                        total += (nck(nums[s], 2) * nums[e]);  
                    else
                        total += (nums[s] * nums[e] * nums[f]);
                }
            }
        }

        System.out.println(total);

    }

    private static long nck(long n, long k) {
        long prev = 1;
        for (long c = 1; c <= k; c++)
            prev = (prev * (n - c + 1))/c;
        return prev;
    }

    private static ArrayList<Integer> getFactors(int product) {
        HashSet<Integer> factors = new HashSet<>();
        for (int i = 1; i <= Math.sqrt(product); i++) {
            if (product%i == 0) {
                factors.add(product/i);
                factors.add(i);
            }
        }
        factors.add(product);
        return new ArrayList<>(factors);
    }
}