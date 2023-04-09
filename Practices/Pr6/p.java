import java.util.Scanner;
import java.util.HashMap;

public class p {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        long n = s.nextLong();
        long m = s.nextLong();
        HashMap<Long, Long> lastSeen = new HashMap<Long, Long>();

        long res = 0;
        for (int i = 0; i < m; i++) {
            long curr = s.nextLong();

            if (lastSeen.containsKey(curr - 1))
                res += ((n - 1) - (i - lastSeen.get(curr - 1)));
            else
                res += ((n - 1) - i);

            System.out.println(res);
            lastSeen.put(curr - 1, (long) (i + 1));
        }
    }
}
