import java.util.Scanner;

/**
 * j
 */
public class j {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPages = in.nextInt();
        long[] nums = new long[numPages];
        for (int i = 0; i < nums.length; i++)
            nums[i] = in.nextInt();
            
        long[] sNum = new long[numPages];
        long[] pNum = new long[numPages];
        
        sNum[0] = nums[0];
        for (int i = 1; i < sNum.length; i++)
            sNum[i] = sNum[i - 1] + nums[i];

        pNum[0] = nums[0];
        for (int i = 1; i < pNum.length; i++) {
            if (pNum[i - 1] * nums[i] <= sNum[numPages - 1]) {
                pNum[i] = pNum[i - 1] * nums[i];
            } else
                pNum[i] = -1;
        }

        for (int i = 0; i < pNum.length; i++) {
            
        }

    }
}