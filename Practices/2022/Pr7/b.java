import java.util.Scanner;

public class b {

    public static String myAns;
    public static String friendAns;
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numCorrect = in.nextInt();

        in.nextLine();
        myAns = in.nextLine();
        friendAns = in.nextLine();
        

        System.out.println(getMaxCorrect(numCorrect));

        in.close();

    }

    public static int getMaxCorrect(int numCorrect) {

        int[][] dp = new int[myAns.length() + 1][myAns.length() + 1];

        for (int at = 0; at < dp.length; at++) {
            dp[at][myAns.length()] = (at == numCorrect) ? 0 : Integer.MIN_VALUE;
            dp[myAns.length()][at] = (at == numCorrect) ? 0 : Integer.MIN_VALUE;
        }

        

        for (int total = myAns.length() - 1; total >= 0 ; total--) {
            for (int k = myAns.length() - 1; k >= 0; k--) {

                int falseCount = check(false, friendAns.charAt(k), myAns.charAt(k)) + dp[total][k + 1];
                int trueCount = check(true, friendAns.charAt(k), myAns.charAt(k)) + dp[total + 1][k + 1];

                dp[total][k] = Math.max(falseCount, trueCount);
            }
        }



        return dp[0][0];
    }


    public static int check(boolean key, char friend, char mine) {

        if (key && mine == friend) return 1;
        else if (!key && mine != friend) return 1;

        return 0;

    }
}


/*
 * import java.util.Arrays;
import java.util.Scanner;

public class b_mine {

    public static String myAns;
    public static String friendAns;
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numCorrect = in.nextInt();

        in.nextLine();
        myAns = in.nextLine();
        friendAns = in.nextLine();
        
        int[][] memo = new int[myAns.length()][myAns.length()];

        for (int[] arr : memo) {
            Arrays.fill(arr, (int)1e9);
        }

        System.out.println(getMaxCorrect(numCorrect, 0, 0, memo));

        in.close();

    }

    public static int getMaxCorrect(int numCorrect, int total, int k, int[][] memo) {

    
        


        int[][] dp = new int[myAns.length() + 1][myAns.length() + 1];

        for (int at = 0; at < dp.length; at++) {
            dp[at][myAns.length()] = (at == numCorrect) ? 0 : Integer.MIN_VALUE;
        }

        for (int i = dp.length - 1; i >= 0 ; i--) {
            for (int j = ; j < dp.length; j++) {
                
            }
        }

        int falseCount = 0;
        int trueCount = 0;

        falseCount = check(false, friendAns.charAt(k), myAns.charAt(k)) + getMaxCorrect(numCorrect, total, k + 1, memo);

        if (total < numCorrect) {
            trueCount = check(true, friendAns.charAt(k), myAns.charAt(k)) + getMaxCorrect(numCorrect, total + 1, k + 1, memo);
        }
        
        memo[total][k] = Math.max(falseCount, trueCount);


        return memo[total][k];
    }


    public static int check(boolean key, char friend, char mine) {

        if (key && mine == friend) return 1;
        else if (!key && mine != friend) return 1;

        return 0;

    }
}

 */