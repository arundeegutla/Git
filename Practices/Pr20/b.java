import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double mean = 0;
        double[] nums = new double[10];
        for (int i = 0; i < 10; i++)
            mean += nums[i] = in.nextDouble();
        mean/=10;

        var numerator = 0;
        for (int i = 0; i < nums.length; i++)
            numerator += (nums[i] - mean) * (nums[i] - mean);
        
        System.out.println(Math.sqrt(numerator/9) <= 1 ? "COMFY" : "NOT COMFY");

    }
}
