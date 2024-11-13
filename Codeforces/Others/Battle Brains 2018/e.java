import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class e {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for (int i = 1; i <= t; i++) {
            String[] nums = br.readLine().split(" ");
            int d = Integer.parseInt(nums[0]);
            long x = Long.parseLong(nums[1]);
            long here = 0;
            long count = 0;

            while (d >= 0 && here != x) {
                long num = (long) Math.pow(2, d);
                if (here - num < 0 || x > here) 
                    here += num;
                else
                    here -= num;
                d--;
                count++;
            }

            if (here == x)
                System.out.println("Case " + i + ": YES " + count);
            else    
                System.out.println("Case " + i + ": NO");
        }
    }
}