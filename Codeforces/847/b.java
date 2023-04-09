import java.util.Arrays;
import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-- > 0) {
            int numDice = in.nextInt();
            int tot = in.nextInt();
            int rTot = in.nextInt();

            int[][] memo = new int[numDice][tot + 1];
            for (int[] is : memo) {
                Arrays.fill(is, -1);
            }
            int[] arr = new int[numDice];

            get(0, arr, tot, tot - rTot, memo);

            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + (i == arr.length - 1 ? "\n" : " "));
            }
        }
    }

    private static boolean get(int at, int[] arr, int tot, int last, int[][] memo) {
        if (at == arr.length - 1) {
            arr[at] = last;
            return tot - last == 0;
        }

        if (memo[at][tot] != -1) {
            return false;
        }

        for (int i = 1; i <= last; i++){
            arr[at] = i;
            if (get(at+1, arr, tot-i, last, memo))
                return true;
        }
        
        memo[at][tot] = 0;
        return false;
    }
}
