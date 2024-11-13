import java.sql.Array;
import java.util.Arrays;
import java.util.Scanner;

public class spidermanworkout {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int n = in.nextInt();
            int sum = 0;
            int[] arr = new int[n];
            for (int i = 0; i < arr.length; i++)
                sum += (arr[i] = in.nextInt());

            int[][] memo = new int[n][sum+1];
            for (int[] is : memo) Arrays.fill(is, -1);
            go(0, 0, arr, memo);

            StringBuilder str = new StringBuilder();
            int prev = 0;

            for (int i = 0; i < n; i++) {
                if (memo[i][prev] > prev) {
                    str.append('U');
                } else {
                    str.append('D');
                }
                prev = memo[i][prev];
            }
            System.out.println(prev!=0?"IMPOSSIBLE":str);
        }
    }

    private static int go(int at, int curHeight, int[] arr, int[][] memo) {
        if(curHeight < 0)
            return (int)1e9;
            
        if(at == arr.length)
            return curHeight==0?0:(int)1e9;

        if(memo[at][curHeight] != -1) {
            // System.out.println("memo!");
            return memo[at][curHeight];
        }

        int goDown = go(at+1, curHeight-arr[at], arr, memo);
        int goUp = go(at+1, curHeight+arr[at], arr, memo);

        if (goDown==(int)1e9&&goUp) {
            
        }

        if (goDown <= goUp) {
            return memo[at][curHeight] = curHeight-arr[at];
        } else if(goUp <= goDown){
            return memo[at][curHeight] = curHeight+arr[at];
        } else {
            return memo[at][curHeight] = (int)1e9;
        }

    }
}
