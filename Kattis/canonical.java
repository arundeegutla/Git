import java.util.Scanner;

public class canonical {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCoins = in.nextInt();
        int[] coins = new int[numCoins];

        for (int i = 0; i < numCoins; i++)
            coins[i] = in.nextInt();

        System.out.println(isCononical(coins) ? "canonical" : "non-canonical");
        in.close();
    }

    private static boolean isCononical(int[] coins) {
        int[] dp = new int[coins[coins.length-1] + coins[coins.length - 2] + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < dp.length; i++)
            if(getGreedy(coins, i) != getOptimal(coins, i, dp))
                return false;
    
        return true;
    }

    private static int getOptimal(int[] coins, int n, int[] dp) {

        if (dp[n] > 0)
            return dp[n];

        if (n == 0)
            return 0;

        int min = Integer.MAX_VALUE;
        for (int i = 0; i < coins.length && coins[i] <= n; i++)
            min = Math.min(min, 1 + getOptimal(coins, n - coins[i], dp));

        dp[n] = min;
        return min;
    }

    private static int getGreedy(int[] coins, int n) {
        
        int numCoins = 0;
        int coin = coins.length - 1;

        while(n > 0) {

            int thisCoins = n / coins[coin];
            n = n - (coins[coin] * thisCoins);
            numCoins += thisCoins;

            coin--;

        }

        return numCoins;
    }
}
