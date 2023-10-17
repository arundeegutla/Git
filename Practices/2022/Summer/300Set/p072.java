import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class p072 {
    public static int MOD = (int)1e9+7;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long[] fac = new long[20];
        fac[1] = 1;
        for (int i = 2; i < fac.length; i++)
            fac[i] = fac[i-1]*i;

        for (int i = 1; i <= 17; i++) {

            int[] perm = new int[i];
            boolean[] used = new boolean[i];
            long ans = go(0, perm, used);
            // System.out.println(Arrays.toString(uniq));
            System.out.println(fac[i] + " - " + (fac[i]-ans) + " = " + ans);
        }
    }

    private static long go(int at, int[] perm, boolean[] used) {
        if(at==perm.length)
            return perm[at-1]%(perm[0]) <= 2 ? 1 : 0;

        long count = 0;
        for (int i = 0; i < perm.length; i++) {
            if(used[i]) continue;
            if(at!=0 && (perm[at-1]%(i+1) > 2)) continue;

            used[i] = true;
            perm[at] = i+1;

            count += go(at+1, perm, used);;
            count %= MOD;
            used[i] = false;
        }
        return count;
    }

}
