import java.util.Scanner;

/**
 * prob4
 */
public class prob4 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        in.nextLine();
        
        while (numCases-- > 0) {
            String[] nums = in.nextLine().split("/");
            long top = Long.parseLong(nums[0]);
            long bottom = Long.parseLong(nums[1]);

            while (bottom != 0) {
                System.out.print((top/bottom) + (top % bottom == 0 ? "\n" : ", "));
                long temp = top;
                top = bottom;
                bottom = temp % bottom;
            }

        }
    }
}