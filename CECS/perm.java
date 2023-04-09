import java.util.Arrays;
import java.util.Scanner;

public class perm {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] perm = new int[n];
        for (int i = 0; i < perm.length; i++)
            perm[i] = i+1;

        int[] nums = new int[n];
        for (int i = 0; i < (nums.length*2); i+=2) {
            // if(perm[i%nums.length] == 0)
            // {
            //     System.out.println("NO SOLUTION");
            //     return;
            // }

            nums[i/2] = perm[i%nums.length];

        }

        for (int i = 0; i+1 < nums.length; i++) {
            if(Math.abs(nums[i+1] - nums[i]) == 1)
            {
                System.out.println("NO SOLUTION");
                return;
            }
        }
        
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + (i == nums.length - 1 ? "\n" : " "));
        }


    }
}
