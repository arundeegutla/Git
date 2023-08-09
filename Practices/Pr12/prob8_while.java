import java.util.Scanner;

public class prob8_while {

    public static long[] arr;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        arr = new long[500001];

        arr[0] = 0;
        for (int i = 1; i < arr.length; i++) 
            arr[i] = arr[i-1] + i;

        StringBuilder finalStr = new StringBuilder();

        int num;
        while ((num = in.nextInt()) != 0) {

            boolean polite = false;
            int left = 0;
            int right = 0;
            while (arr[right] < num)
                right++;
            
            while(right <= (num+1)/2)
            {
                if (arr[right] - arr[left] == num) {
                    polite = true;
                    finalStr.append(num + " = " + (left+1) + " to " + right + "\n");
                    right++;
                }
                left++;
                while (right <= (num+1)/2 && arr[right] - arr[left] < num)
                    right++;
            }
            
            if(!polite)
                finalStr.append(num + " is not polite\n");

        }
        System.out.print(finalStr);
    }

}
