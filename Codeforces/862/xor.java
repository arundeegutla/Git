import java.util.Scanner;

/**
 * xor
 */
public class xor {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        loop:while (numCases-->0) {
            int n = in.nextInt();
            int[] arr = new int[n];
            
            for (int i = 0; i < arr.length; i++)
                arr[i] = in.nextInt();

            for (int x = 0; x < (1<<8); x++) {
                int b = 0;
                for (int i = 0; i < arr.length; i++)
                    b ^= arr[i]^x;
                if (b == 0) {
                    System.out.println(x);
                    continue loop;
                }
            }
            System.out.println(-1);
        }
    }
}