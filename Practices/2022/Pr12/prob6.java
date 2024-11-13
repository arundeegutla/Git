import java.util.Arrays;
import java.util.Scanner;

public class prob6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();

        while (cases-- > 0) {
            char addOrMult = in.next().charAt(0);
            int numof = in.nextInt();

            int[] nums = new int[numof];
            int[] ans = new int[numof];

            for (int i = 0; i < ans.length; i++)
                ans[i] = in.nextInt();

            if (addOrMult == '+') {
                if (isPosAdd(nums, ans, 0)) 
                    for (int i = 0; i < nums.length; i++)
                        System.out.print(nums[i] + (i == nums.length - 1 ? "\n" : " "));
                else
                    System.out.println("no solution");
            } else {
                if (isPosMulti(nums, ans, 0)) 
                    for (int i = 0; i < nums.length; i++)
                        System.out.print(nums[i] + (i == nums.length - 1 ? "\n" : " "));
                else
                    System.out.println("no solution");
            }
            
        }
    }

    private static boolean isPosAdd(int[] nums, int[] ans, int at) {

        if (at == 0) {
            for (int i = 1; i <= ans[0]; i++) {
                nums[at] = i;
                if (isPosAdd(nums, ans, at + 1)) {
                    return true;
                }
            } 
        } else if (at == nums.length) {
            if (ans[at - 1] - nums[at - 1] == nums[0]) {
                return true;
            }
            return false;
        } else {
            int num = ans[at - 1] - nums[at - 1];
            if (num <= 0) {
                return false;
            }
            nums[at] = num;
            return isPosAdd(nums, ans, at + 1);
        }

        return false;
    }

    private static boolean isPosMulti(int[] nums, int[] ans, int at) {

        if (at == 0) {
            for (int i = 1; i <= ans[0]; i++) {
                nums[at] = i;
                if (isPosMulti(nums, ans, at + 1))
                    return true;
            }
        } else if (at == nums.length) {
            if (nums[at - 1] * nums[0] == ans[at - 1]) {
                return true;
            }
            return false;
        } else {
            double num = (double)ans[at - 1]/nums[at - 1];
            if (num <= 0 || (int)num != num) {
                return false;
            }
            nums[at] = (int)num;
            return isPosMulti(nums, ans, at + 1);
        }

        return false;
    }

}
