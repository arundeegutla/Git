import java.math.BigDecimal;
import java.math.MathContext;
import java.util.*;

public class f {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.println("Case " + i + ": " + solve(in.nextLong()));
            ;
        }
    }

    private static long solve(long pushups) {
        long lo = 1;
        long hi = (long)1e18;
        long ans = -1;
        while(lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long count = go(mid);
            if(count >= pushups)
                hi = (ans = mid) - 1;
            else if (count < pushups)
                lo = mid + 1;
        }
        return ans;
    }

    private static long go(long index) {
        BigDecimal ssq = new BigDecimal(index).sqrt(new MathContext(50));
        ll row = ceil(sqrt((ld)index));
        ll p = row - 1;
        ll col = index - (p*p);
        ll totalInRow = row + (row-1);

        ll sum = (p*(p+1)*(2*p+1)) / 6;
        if(col <= row) {
            sum += (col*(col+1))/2;
        } else {
            ll sub = totalInRow-col;
            sum -= (sub*(sub+1))/2;
            sum += row*row;
        }
        return sum;
    }
}
