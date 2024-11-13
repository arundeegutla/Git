import java.util.Arrays;
import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-- > 0) {
            int permLength = in.nextInt();
            int[][] freq = new int[permLength - 1][permLength + 1];

            for (int i = 0; i < permLength; i++)
                for (int j = 0; j < permLength - 1; j++)
                    freq[j][in.nextInt()]++;
                    
            int at = 0;
            int[] arr = new int[permLength];
            boolean[] used = new boolean[permLength + 1];

            for (int i = 0; i < permLength - 1; i++) {

                int thisNumber = 0;
                int next = 0;
                for (int j = 1; j <= permLength; j++) {
                    if (!used[j] && freq[i][j] > freq[i][thisNumber])
                    {
                        next = thisNumber;
                        thisNumber = j;
                    } else if (!used[j] && freq[i][j] > freq[i][next])
                        next = j;
                }

                arr[at] = thisNumber;
                at++;
                used[thisNumber] = true;
                if (next > 0) {
                    used[next] = true;
                    arr[at] = next;
                    at++;
                }

             }
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + (i == arr.length - 1 ? "\n" : " "));
            }
        }
    }
}

