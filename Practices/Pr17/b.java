import java.util.Arrays;
import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numNums = in.nextInt();
        int numBuckets = in.nextInt();

        int[] nums = new int[numNums];
        for (int i = 0; i < nums.length; i++)
            nums[i] = in.nextInt();

        Arrays.sort(nums);
        long[][][] memo = new long[nums.length + 1][numBuckets + 1][nums.length + 1];
        for (long[][] twoD : memo) 
            for (long[] oneD : twoD)
                Arrays.fill(oneD, -1);
        System.out.println(getMin(0, numBuckets, -1, nums, memo));
    }

    private static long getMin(int at, int numBuckets, int prevBar, int[] nums, long[][][] memo) {
        if (memo[at][numBuckets][prevBar + 1] != -1)
        {
            // System.out.println("memo!");
            return memo[at][numBuckets][prevBar + 1];
        }

        if (numBuckets <= 0)
            return (long)1e18;
        // System.out.println(stringBuilder + "Current:::" + at + " with " + numBuckets + " " + prevBar);

        long add = nums[at] - nums[prevBar + 1];
        add *= add;
        if (at == nums.length - 1)
            return add;
        
        long putBar = getMin(at+1, numBuckets-1, at, nums, memo) + add;
        long didntPutBar = getMin(at+1, numBuckets, prevBar, nums, memo);

        return memo[at][numBuckets][prevBar + 1] = Math.min(putBar, didntPutBar);
    }
}
